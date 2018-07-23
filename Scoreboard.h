#include  "Graph.h"
#include "std_lib_facilities_5.h"
using namespace Graph_lib;

struct Entry {
	string name;
	string score;
};

class Scoreboard : public Shape {
public:
	//Constructor 
	Scoreboard(Point xy, string filename);

	void set_latest_score(int value) {
		latest_score = value;
		sort_score();
	}
	//Appearance functions
	void draw_lines() const;

	void set_font(Graph_lib::Font f);
	Graph_lib::Font font() const { return Graph_lib::Font(fnt); }

	void set_font_size(int s);
	int font_size() const { return fnt_size; }

	void set_color(Color col);
	Color color() const { return tcolor; }

	void add_current_player(string name);

private:
	vector<Entry> scores;
	Vector_ref<Text> scores_obj;
	string game_file;
	Point start_point;
	Graph_lib::Font fnt;
	int fnt_size;
	Color tcolor;
	int latest_score;
	void sort_score();
	void update_scores();
};