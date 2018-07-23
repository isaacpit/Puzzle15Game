#include "Scoreboard.h"

//Constructor
Scoreboard::Scoreboard(Point xy, string filename) 
	: game_file{filename}, 
	start_point{xy}, 
	fnt{ fl_font() },
	fnt_size{ (fl_size() < 14) ? 14 : fl_size() },
	tcolor{ fl_color() }
{
	add(start_point);
	fstream fs;
	fs.open(game_file, ios_base::in);
	if (!fs)
		error("File not found");
	
	string name = "";
	string score = "";
	while (fs >> name >> score) //NOTE: Assumes scores in file are already sorted
		scores.push_back(Entry{name,score});
	
	fs.close();

	while (scores.size() < 5)
		scores.push_back(Entry{"---","---"});
	
	for (unsigned int i = 0; i < scores.size(); ++i) {
		int x = start_point.x;
		int y = start_point.y + 17*i;
		string listing = to_string(i+1)+". "+scores[i].name+"  "+ scores[i].score;
		scores_obj.push_back(new Text(Point(x,y),listing));
	}
	
}


void Scoreboard::draw_lines() const
{
	for (int i = 0; i < scores_obj.size(); ++i)
	{
		scores_obj[i].draw();
	}
}

void Scoreboard::set_font(Graph_lib::Font f)
{
	fnt = f;
	for (int i = 0; i < scores_obj.size(); ++i)
	{
		scores_obj[i].set_font(f);
	}
}

void Scoreboard::set_font_size(int s)
{
	fnt_size = s;
	for (int i = 0; i < scores_obj.size(); ++i)
	{
		scores_obj[i].set_font_size(s);
	}
}

void Scoreboard::set_color(Color col)
{
	tcolor = col;
	for (int i = 0; i < scores_obj.size(); ++i)
	{
		scores_obj[i].set_color(col);
	}
}

void Scoreboard::update_scores()
{
	fstream fs;
	fs.open(game_file, ios_base::in);
	int count_dash = 0;
	for (int i = 0; i < scores.size();++i)
		if (scores[i].name == "---")
			++count_dash;
	string name = "";
	string score = "";
	for (int i = 0; i < 5; ++i) {
		fs >> name >> score;
		if (i > (5 - count_dash) ) {
			name = "---";
			score = "---";
		}
		scores[i].name = name;
		scores[i].score = score;
		string listing = to_string(i + 1) + ". " + scores[i].name + "  " + scores[i].score;
		scores_obj[i].set_label(listing);
	}
	fs.close();
}

void Scoreboard::add_current_player(string name)
{ 
	while (name.length() < 3)
		name.push_back('X');
	
	string temp = "";
	for (unsigned int i = 0; i < 3; ++i)
		temp.push_back(toupper(name.at(i)));
	if(scores.size()<6)
		scores.push_back(Entry{temp,"---"});
	else {
		scores[5].name = temp;
		scores[5].score = "---";
	}
		
	int x = start_point.x;
	int y = start_point.y + 17 * 5;
	string listing = "6. " + scores[5].name + "  " + scores[5].score;
	if(scores_obj.size() < 6)
		scores_obj.push_back(new Text(Point(x, y), listing));
	else
		scores_obj[5].set_label(listing);
	
	scores_obj[5].set_color(tcolor);
	scores_obj[5].set_font(fnt);
	scores_obj[5].set_font_size(fnt_size);
}

bool operator<(const Entry& a, const Entry& b)/* this function defines the < operator for Entry*?
{
	int atemp = 0;
	int btemp = 0;
	if (a.score != "---")
		atemp = stoi(a.score);
	if (b.score != "---")
		btemp = stoi(b.score);
	if (atemp<btemp)
		return true;
	els/
		return false;
}

void Scoreboard::sort_score() {
	scores[5].score = to_string(latest_score);       /*this function, clears teh file, then sorts the ezisting scores and writes them into the file again*/
	sort(scores);
	for (unsigned int i = 0; i<scores.size(); i++)
		cout << scores[i].name << " " << scores[i].score << endl;
	fstream fs;
	fs.open(game_file, ios::out | ios::trunc);
	for (unsigned int i = scores.size() - 1; i>0; --i) {
		if (scores[i].name != "---")
			fs << scores[i].name << " " << scores[i].score << '\n';
	}
	fs.close();
	update_scores();
}