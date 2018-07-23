/*
Team 39 15 Puzzle

Members:
Durian Nguyen
Isaac Pitblado
Ameya Nair
Layne Mayes

CSCE 121-518
Due Date: 11/30/17
*/

#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "Splash_window.h"
#include "Simple_window.h"
#include "std_lib_facilities_5.h"
#include <vector>

using namespace Graph_lib;


// Constructor 
Splash_window::Splash_window(Point xy, int w, int h, const string title)
	: Graph_lib::Window(xy, w, h, title),

	gameName(Point(x_max() / 32, y_max() / 6), "15 PUZZLE"),
	splashText(Point(x_max() / 32, y_max() / 4), "TEAM 39 PROJECT"),
	Durian(Point(x_max() / 20, y_max() / 4+22), "Durian Nguyen"),
	Isaac(Point(x_max() / 20, y_max() / 4+44), "Isaac Pitblado"),
	Ameya(Point(x_max() / 20, y_max() / 4+66), "Ameya Nair"),
	Layne(Point(x_max() / 20, y_max() / 4+88), "Layne Mayes"),

	gameOver(Point(x_max()/5+20, y_max() / 4), "Game Over"),
	userScore(Point(x_max()/3+20, y_max() / 4+70), "Score: 0"),

	start_button(Point(x_max() / 2 - BUTTON_WIDTH, y_max() / 2), BUTTON_WIDTH * 2, BUTTON_HEIGHT * 2, "Start", cb_start),
	start_button_back(Point(start_button.loc.x, start_button.loc.y), BUTTON_WIDTH * 2, BUTTON_HEIGHT * 2),
	start_button_back2(Point(start_button.loc.x - 10, start_button.loc.y - 10),
		BUTTON_WIDTH * 2 + 20, BUTTON_HEIGHT * 2 + 20),
	start_button_text(Point(start_button.loc.x + 40, start_button.loc.y + BUTTON_HEIGHT), "Start"),

	exit_button(Point(x_max() - BUTTON_WIDTH / 2, 0), BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2, "Exit", cb_exit),
	exit_button_back(Point(exit_button.loc.x, exit_button.loc.y), BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2),
	exit_button_text(Point(exit_button.loc.x + 5, exit_button.loc.y + 30), "Exit"),

	hint_button(Point(X_BUFFER / 2, Y_BUFFER / 4 + 60), BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2, "Hint", cb_hint),
	hint_button_back(Point(hint_button.loc.x, hint_button.loc.y), BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2),
	hint_button_text(Point(hint_button.loc.x + 5, hint_button.loc.y + 30), "Hint:"),
	hint_output(Point(140, 110), "0"),

	leave_button(Point(X_BUFFER + 250, Y_BUFFER*3 ), BUTTON_WIDTH, BUTTON_HEIGHT, "Quit", cb_leave),
	leave_button_back(Point(leave_button.loc.x, leave_button.loc.y), BUTTON_WIDTH , BUTTON_HEIGHT ),
	leave_button_text(Point(leave_button.loc.x + 40, leave_button.loc.y + 45), "Quit"),

	replay_button(Point(X_BUFFER , Y_BUFFER*3 ), BUTTON_WIDTH, BUTTON_HEIGHT, "Replay", cb_replay),
	replay_button_back(Point(replay_button.loc.x, replay_button.loc.y), BUTTON_WIDTH, BUTTON_HEIGHT),
	replay_button_text(Point(replay_button.loc.x + 25, replay_button.loc.y + 45), "Replay"),

	easy_button(Point(x_max() / 2 - (BUTTON_WIDTH / 2), y_max() * 2.0 / 6.0),
		BUTTON_WIDTH * 2.0, BUTTON_HEIGHT, "Easy", cb_easy),
	easy_button_back(Point(easy_button.loc.x, easy_button.loc.y), BUTTON_WIDTH * 2.0, BUTTON_HEIGHT),
	easy_button_text(Point(easy_button.loc.x + 120, easy_button.loc.y + BUTTON_HEIGHT / 2), "Easy"),

	intermediate_button(Point(x_max() / 2 - (BUTTON_WIDTH / 2), y_max() * 3.0 / 6.0), BUTTON_WIDTH * 2.0, BUTTON_HEIGHT, "Intermediate", cb_intermediate),
	intermediate_button_back(Point(intermediate_button.loc.x, intermediate_button.loc.y),
		BUTTON_WIDTH * 2.0, BUTTON_HEIGHT),
	intermediate_button_text(Point(intermediate_button.loc.x + 60, intermediate_button.loc.y + BUTTON_HEIGHT / 2), "Intermediate"),

	hard_button(Point(x_max() / 2 - (BUTTON_WIDTH / 2), y_max() * 4.0 / 6.0),
		BUTTON_WIDTH * 2.0, BUTTON_HEIGHT, "Hard", cb_hard),
	hard_button_back(Point(hard_button.loc.x, hard_button.loc.y), BUTTON_WIDTH * 2.0, BUTTON_HEIGHT),
	hard_button_text(Point(hard_button.loc.x + 120, hard_button.loc.y + BUTTON_HEIGHT / 2), "Hard"),

	expert_button(Point(x_max() / 2 - (BUTTON_WIDTH / 2), y_max() * 5.0 / 6.0),
		BUTTON_WIDTH * 2.0, BUTTON_HEIGHT, "Expert", cb_expert),
	expert_button_back(Point(expert_button.loc.x, expert_button.loc.y), BUTTON_WIDTH * 2.0, BUTTON_HEIGHT),
	expert_button_text(Point(expert_button.loc.x + 110, expert_button.loc.y + BUTTON_HEIGHT / 2), "Expert"),

	instructionsObj0(Point(X_BUFFER / 2, Y_BUFFER / 4 +  30), instructions0),
	instructionsObj1(Point(X_BUFFER / 2, Y_BUFFER / 4 +  50), instructions1),
	instructionsObj2(Point(X_BUFFER / 2, Y_BUFFER / 4 +  70), instructions2),
	instructionsObj3(Point(X_BUFFER / 2, Y_BUFFER / 4 +  90), instructions3),
	instructionsObj4(Point(X_BUFFER / 2, Y_BUFFER / 4 + 110), instructions4),
	game_status_obj1(Point(X_BUFFER / 2, Y_BUFFER / 4 + 30), game_status1),
	game_status_obj2(Point(X_BUFFER / 2, Y_BUFFER / 4 + 50), game_status2),
	topLeft     (Point(0       ,       0), 50),
	topRight    (Point(x_max() ,       0), 50),
	bottomLeft  (Point(0       , y_max()), 50),
	bottomRight (Point(x_max() , y_max()), 50),
	background(Point(0, 0), Point(x_max(), y_max())),
	backgroundBorder(Point(10, 10), Point(x_max() - 10, y_max() - 10)),

	easy_scores(Point(X_BUFFER*3.5, Y_BUFFER / 4 + 10),"easy_scores.txt"),
	intermediate_scores(Point(X_BUFFER*3.5, Y_BUFFER / 4 + 10), "intermediate_scores.txt"),
	hard_scores(Point(X_BUFFER*3.5, Y_BUFFER / 4 + 10), "hard_scores.txt"),
	expert_scores(Point(X_BUFFER*3.5, Y_BUFFER / 4 + 10), "expert_scores.txt"),
	initials_box(Point(X_BUFFER*2, Y_BUFFER / 4 + 10),100,50,"Enter Initials: "),
	enter_button(Point(X_BUFFER*2, Y_BUFFER / 4 + 150), BUTTON_WIDTH * 2.0, BUTTON_HEIGHT, "Enter", cb_enter)

{
	topLeft.set_fill_color(Color::black);
	topRight.set_fill_color(Color::black);
	bottomLeft.set_fill_color(Color::black);
	bottomRight.set_fill_color(Color::black);
	background.set_fill_color(Color::black);
	backgroundBorder.set_fill_color(Color::dark_green);
	attachBackground();
	
	// Constructs starting spots
	int X_BUFFER = 100;
	int Y_BUFFER = 150;
	int PIECE_WIDTH = x_max() / 6;
	int PIECE_HEIGHT = y_max() / 6;
	int tempX = 0;
	int tempY = 0;
	for (int j = 0; j < 4; ++j) {
		tempY = Y_BUFFER + (j * PIECE_HEIGHT);
		for (int i = 0; i < 4; ++i) {
			tempX = X_BUFFER + (i * PIECE_WIDTH);
			spots.push_back(new Point(tempX, tempY));

		}
	}

	// Constructs buttons 
	for (int i = 0; i < spots.size(); ++i) {
		switch (i) //Switch statement is necessary for determining which button was pushed
		{
		case 0:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(0); }));
			break;
		case 1:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(1); }));
			break;
		case 2:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(2); }));
			break;
		case 3:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(3); }));
			break;
		case 4:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(4); }));
			break;
		case 5:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(5); }));
			break;
		case 6:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(6); }));
			break;
		case 7:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(7); }));
			break;
		case 8:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(8); }));
			break;
		case 9:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(9); }));
			break;
		case 10:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(10); }));
			break;
		case 11:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(11); }));
			break;
		case 12:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(12); }));
			break;
		case 13:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(13); }));
			break;
		case 14:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(14); }));
			break;
		case 15:
			buttons.push_back(new Button(spots.operator[](i), PIECE_WIDTH, PIECE_HEIGHT,
				to_string(i), [](Address, Address pw) {reference_to<Splash_window>(pw).move_piece(15); }));
			break;
		}
	}

	//Constructs grid 
	int horizontalX1 = X_BUFFER;
	int horizontalX2 = x_max() - X_BUFFER;
	int horizontalY = 0;
	int verticalX = 0;
	int verticalY1 = Y_BUFFER;
	int verticalY2 = y_max() - 50;
	for (int i = 0; i < 5; ++i) {
		horizontalY = Y_BUFFER + i * PIECE_HEIGHT;
		grid.add(Point(horizontalX1, horizontalY), Point(horizontalX2, horizontalY));
		verticalX = X_BUFFER + i * PIECE_WIDTH;
		grid.add(Point(verticalX, verticalY1), Point(verticalX, verticalY2)); 
	}

	// Various text objects cosmetic details
	splashText.set_color(Color::black);
	splashText.set_font(Graph_lib::Font::screen_bold);
	splashText.set_font_size(40);

	gameName.set_color(Color::black);
	gameName.set_font(Graph_lib::Font::screen_bold);
	gameName.set_font_size(50);

	Durian.set_color(Color::black);
	Durian.set_font(Graph_lib::Font::screen_bold);
	Durian.set_font_size(30);

	Isaac.set_color(Color::black);
	Isaac.set_font(Graph_lib::Font::screen_bold);
	Isaac.set_font_size(30);

	Ameya.set_color(Color::black);
	Ameya.set_font(Graph_lib::Font::screen_bold);
	Ameya.set_font_size(30);

	Layne.set_color(Color::black);
	Layne.set_font(Graph_lib::Font::screen_bold);
	Layne.set_font_size(30);

	gameOver.set_color(Color::black);
	gameOver.set_font(Graph_lib::Font::screen_bold);
	gameOver.set_font_size(50);

	userScore.set_color(Color::black);
	userScore.set_font(Graph_lib::Font::screen_bold);
	userScore.set_font_size(30);

	instructionsObj0.set_color(Color::black);
	instructionsObj1.set_color(Color::black);
	instructionsObj2.set_color(Color::black);
	instructionsObj3.set_color(Color::black);
	instructionsObj4.set_color(Color::black);
	instructionsObj0.set_font_size(23.5);
	instructionsObj1.set_font_size(23.5);
	instructionsObj2.set_font_size(23.5);
	instructionsObj3.set_font_size(23);
	instructionsObj4.set_font_size(23);
	instructionsObj0.set_font(Graph_lib::Font::screen_bold);
	instructionsObj1.set_font(Graph_lib::Font::screen_bold);
	instructionsObj2.set_font(Graph_lib::Font::screen_bold);
	instructionsObj3.set_font(Graph_lib::Font::screen_bold);
	instructionsObj4.set_font(Graph_lib::Font::screen_bold);

	game_status_obj1.set_color(Color::black);
	game_status_obj2.set_color(Color::black);
	game_status_obj1.set_font_size(23.5);
	game_status_obj2.set_font_size(23.5);
	game_status_obj1.set_font(Graph_lib::Font::screen_bold);
	game_status_obj2.set_font(Graph_lib::Font::screen_bold);

	easy_scores.set_color(Color::black);
	easy_scores.set_font_size(20);
	easy_scores.set_font(Graph_lib::Font::screen_bold);
	intermediate_scores.set_color(Color::black);
	intermediate_scores.set_font_size(20);
	intermediate_scores.set_font(Graph_lib::Font::screen_bold);
	hard_scores.set_color(Color::black);
	hard_scores.set_font_size(20);
	hard_scores.set_font(Graph_lib::Font::screen_bold);
	expert_scores.set_color(Color::black);
	expert_scores.set_font_size(20);
	expert_scores.set_font(Graph_lib::Font::screen_bold);

	grid.set_color(Color::black);
	grid.set_style(Line_style(Line_style::solid,5));

	start_button_back.set_fill_color(Color::white);
	start_button_back.set_style(Line_style(Line_style::dashdot, 5));
	start_button_back2.set_fill_color(Color::black);
	start_button_text.set_font(Graph_lib::Font::screen_bold);
	start_button_text.set_font_size(30);
	start_button_text.set_color(Color::black);

	exit_button_back.set_fill_color(Color::white);
	exit_button_back.set_style(Line_style(Line_style::dash, 5));
	exit_button_back.set_color(Color::red);
	exit_button_text.set_font(Graph_lib::Font::screen_bold);
	exit_button_text.set_font_size(30);
	exit_button_text.set_color(Color::black);

	leave_button_back.set_fill_color(Color::white);
	leave_button_back.set_style(Line_style(Line_style::dash, 5));
	leave_button_back.set_color(Color::red);
	leave_button_text.set_font(Graph_lib::Font::screen_bold);
	leave_button_text.set_font_size(30);
	leave_button_text.set_color(Color::black);

	replay_button_back.set_fill_color(Color::white);
	replay_button_back.set_style(Line_style(Line_style::dash, 5));
	replay_button_back.set_color(Color::green);
	replay_button_text.set_font(Graph_lib::Font::screen_bold);
	replay_button_text.set_font_size(30);
	replay_button_text.set_color(Color::black);

	hint_button_back.set_fill_color(Color::white);
	hint_button_back.set_style(Line_style(Line_style::dash, 5));
	hint_button_back.set_color(Color::blue);
	hint_button_text.set_font(Graph_lib::Font::screen_bold);
	hint_button_text.set_font_size(17);
	hint_button_text.set_color(Color::black);
	hint_output.set_font(Graph_lib::Font::screen_bold);
	hint_output.set_font_size(17);
	hint_output.set_color(Color::black);

	easy_button_back.set_fill_color(Color::white);
	easy_button_back.set_style(Line_style(Line_style::dot, 4));
	easy_button_back.set_color(Color::white);
	easy_button_text.set_font(Graph_lib::Font::screen_bold);
	easy_button_text.set_font_size(30);
	easy_button_text.set_color(Color::black);

	intermediate_button_back.set_fill_color(Color::white);
	intermediate_button_back.set_style(Line_style(Line_style::dashdot, 6));
	intermediate_button_back.set_color(Color::dark_blue);
	intermediate_button_text.set_font(Graph_lib::Font::screen_bold);
	intermediate_button_text.set_font_size(30);
	intermediate_button_text.set_color(Color::black);

	hard_button_back.set_fill_color(Color::white);
	hard_button_back.set_style(Line_style(Line_style::dashdotdot, 8));
	hard_button_back.set_color(Color::dark_red);
	hard_button_text.set_font(Graph_lib::Font::screen_bold);
	hard_button_text.set_font_size(30);
	hard_button_text.set_color(Color::black);

	expert_button_back.set_fill_color(Color::white);
	expert_button_back.set_style(Line_style(Line_style::solid, 10));
	expert_button_back.set_color(Color::black);
	expert_button_text.set_font(Graph_lib::Font::screen_bold);
	expert_button_text.set_font_size(30);
	expert_button_text.set_color(Color::black);

	attachStart();
	
	
}

// Callbacks
void Splash_window::cb_start(Address, Address pw) {

	reference_to<Splash_window>(pw).start();
	return;
}

void Splash_window::cb_easy(Address, Address pw) {
	
	reference_to<Splash_window>(pw).easy();
	return;
}

void Splash_window::cb_intermediate(Address, Address pw) {

	reference_to<Splash_window>(pw).intermediate();
	return;
}
void Splash_window::cb_hard(Address, Address pw) {

	reference_to<Splash_window>(pw).hard();
	return;
}
void Splash_window::cb_expert(Address, Address pw) {

	reference_to<Splash_window>(pw).expert();
	return;
}

void Splash_window::cb_exit(Address, Address pw) {

	reference_to<Splash_window>(pw).exit();
	return;
}

void Splash_window::cb_enter(Address, Address pw) {

	reference_to<Splash_window>(pw).enter();
	return;
}

void Splash_window::cb_hint(Address, Address pw) {
	reference_to<Splash_window>(pw).hint();
}

void Splash_window::cb_leave(Address, Address pw) {
	reference_to<Splash_window>(pw).leave();
}

void Splash_window::cb_replay(Address, Address pw) {
	reference_to<Splash_window>(pw).replay();
	
}

// Button functions
void Splash_window::start() {

	cout << "was: " << current << endl;

	attachDifficulty();

	cout << "now: " << current << endl;
	
	return;
}

void Splash_window::exit() {

	attachSplash();
	return;
}

void Splash_window::leave() {
	
	hide();
	return;
}

void Splash_window::replay() {
	detach(gameOver);
	detach(userScore);
	attachSplash();
	return;
}

int Splash_window::find_hint(int row_num, int column_num, int row_zero, int col_zero) {/* This function calculates the manhattan distance for 
                                                                                        all the possible moves using a function called hint_value*/
	int num = 2;
	int ans;
	num = position_map[row_num][column_num];
	//cout<<num<<endl;
	if (num<0)
		ans = 1000000;
	else
		ans = hint_value(num, row_num, column_num, row_zero, col_zero);
	//cout<<ans<<endl;
	return ans;
}


int Splash_window::calc_hint(int a, int b) {/* This function calculates the hint to be given using the function find_hint 
                                               which calculates the manhattan distance for each of the four moves*/
	Vector<int> num = { 0,0,0,0 };

	num[0] = find_hint(a + 1, b, a, b);
	num[1] = find_hint(a - 1, b, a, b);
	num[2] = find_hint(a, b + 1, a, b);
	num[3] = find_hint(a, b - 1, a, b);
	Vector<int> ans1 = { 0,0,0,0 };
	ans1[0] = position_map[a + 1][b];
	ans1[1] = position_map[a - 1][b];
	ans1[2] = position_map[a][b + 1];
	ans1[3] = position_map[a][b - 1];

	int min = 1000000;
	for (int i = 0; i<4; i++) {/*This for loop finds the possible move with the lowest manhattan distance, 
	                            which is the answer to the hint*/
		if (ans1[i] == last_num)
			num[i] = min;
		if (num[i]<min)
			min = i;
	}
	last_num = ans1[min];
	return ans1[min];
}


void Splash_window::hint() { /*This function calculates the hint to be given every time the hint button is pressed.
                                  It uses the calc_hint function to do this*/
	int ans;
	int x = 0;
	int row_zero, column_zero;
	int a;
	int b;
	vector_copy();
	for (unsigned int i = 1; i<5; i++) {/* this for loop is to calculate the row and column that zero is in, in position_map*/
		for (unsigned int j = 1; j<5; j++) {
			if (x == position_map[i][j]) {
				a = i; b = j;
				row_zero = i - 1;
				column_zero = j - 1;
				break;
			}
		}
	}

	ans = calc_hint(a, b);
	//cout << "Hint!" << endl;
	detach(hint_output);
	hint_output.set_label(to_string(ans));
	attach(hint_output);
	redraw();
}

int Splash_window::hint_value(int num, int row_num, int column_num, int row_zero, int col_zero) {/* This function calculates teh manhattan distance*/
	vector_copy();
	int sum = 0;
	int number;
	copy_map[row_num][column_num] = 0;
	copy_map[row_zero][col_zero] = num;

	int row;
	int column;
	for (int i = 1; i<5; ++i) {/* This for loop is used to calculate the manhattan distance for each of the possible moves*/
		for (int j = 1; j<5; ++j) {
			row = i - 1;
			column = j - 1;
			number = copy_map[i][j];
			int a = 0;
			int b = 0;
			for (unsigned int k = 0; k<16; k++) {
				if (number == correct_order[k]) {
					b = k % 4;
					a = (k - b) / 4;
					int value = abs(row - a) + abs(column - b);
					sum = sum + value;
					break;
				}
			}
		}
	}
	return sum;
}

void Splash_window::easy() {
	// FIXME: Enter easy game mode
	cout << "Entering easy game mode..." << endl;
	attachInput(0);
	return;
}

void Splash_window::intermediate() {
	// FIXME: enter intermediate game mode
	cout << "Entering intermediate game mode..." << endl;
		attachInput(1);
	return;
}

void Splash_window::hard() {
	// FIXME: enter hard game mode
	cout << "Entering hard game mode..." << endl;
	attachInput(2);
	return;
}

void Splash_window::expert() {
	// FIXME: enter expert game mode
	cout << "Entering expert game mode... " << endl;
	attachInput(3);
	return;
}

void Splash_window::enter() {
	user_input = initials_box.get_string();
	//Makes appropriate changes to screen
	detach(initials_box);
	detach(enter_button);

	attachBackground();

	attach(exit_button);
	attach(exit_button_back);
	attach(exit_button_text);

	attach(hint_button);
	attach(hint_button_back);
	attach(hint_button_text);
	hint_exists = true;

	switch (game_diff) {
	case 0:
		easy_scores.add_current_player(user_input);
		attachEasy();break;
	case 1:
		intermediate_scores.add_current_player(user_input);
		attachIntermediate();break;
	case 2:
		hard_scores.add_current_player(user_input);
		attachHard();break;
	case 3:
		expert_scores.add_current_player(user_input);
		attachExpert();break;
	}
}

//Used for indexing map_position based on which button was pressed
int row(int i) {
	if (i >= 0 && i < 4)
		return 1;
	else if (i >= 4 && i < 8)
		return 2;
	else if (i >= 8 && i < 12)
		return 3;
	else if (i >= 12 && i < 16)
		return 4;
}

int col(int i) {
	switch (i) {
	case 0: case 4: case 8:case 12:
		return 1;
		break;
	case 1: case 5: case 9: case 13:
		return 2;
		break;
	case 2: case 6: case 10: case 14:
		return 3;
		break;
	case 3: case 7: case 11: case 15:
		return 4;
		break;
	}
}

int Splash_window::calculate_score() {
	int count = 0;
	int score = 0;
	for (unsigned int i = 1; i<5; i++) {
		for (unsigned int j = 1; j<5; j++) {
			if (position_map[i][j] == correct_order[count])    /*This function, compares the current position of the numbers to the 
			                                                    way it should be and calculates the player's score*/
				score+=10;
			count++;
		}
	}
	
	switch (game_diff) {
	case 0:
		easy_scores.set_latest_score(score);
		break;

	case 1:
		intermediate_scores.set_latest_score(score);
		break;

	case 2:
		hard_scores.set_latest_score(score);
		break;

	case 3:
		expert_scores.set_latest_score(score);
		break;
	}

	return score;
}

void Splash_window::update_order() {
	
	update_correct_position();
	--moves_remaining;
	cout << "MOVES REMAIN: " << moves_remaining << endl;
	if (moves_remaining == 0) {
		int s = calculate_score();
		userScore.set_label("Score: "+to_string(s));
		attachEnd();
		return; 
	}
	//Updates everything on screen
	update_status_labels();
	for (int i = 0; i < pieces.size(); ++i) {
		detach(pieces[i]);
	}
	constructPieces(current_order);
	detach(hint_output);
	detach(grid);
	attach(grid);
	redraw();
}


void Splash_window::move_piece(int index) {

	//cout << "Button: " << buttons[index].label << endl;
	if (position_map[row(index) + 1][col(index)] == 0) {
		position_map[row(index) + 1][col(index)] = position_map[row(index)][col(index)];
		position_map[row(index)][col(index)] = 0;
		update_order();
	}
	else if (position_map[row(index) - 1][col(index)] == 0) {
		position_map[row(index) - 1][col(index)] = position_map[row(index)][col(index)];
		position_map[row(index)][col(index)] = 0;
		update_order();
	}
	else if (position_map[row(index)][col(index) + 1] == 0) {
		position_map[row(index)][col(index) + 1] = position_map[row(index)][col(index)];
		position_map[row(index)][col(index)] = 0;
		update_order();
	}
	else if (position_map[row(index)][col(index) - 1] == 0) {
		position_map[row(index)][col(index) - 1] = position_map[row(index)][col(index)];
		position_map[row(index)][col(index)] = 0;
		update_order();
	}

}

// Member functions. All self explanatory, they attach the screens in their name.
void Splash_window::attachSplash() {
	cout << "current was: " << current << endl;
	current = splash;
	cout << "current is: " << current << endl;
	
	attachStart();

	if(leave_exists)
		detach(leave_button);
	detach(leave_button_back);
	detach(leave_button_text);

	if(replay_exists)
		detach(replay_button);
	detach(replay_button_back);
	detach(replay_button_text);

	detachInstructions();
	
	detachDiffButtons();
	
	detach(exit_button);
	detach(exit_button_back);
	detach(exit_button_text);
	
	if(hint_exists) 
		detach(hint_button); 
	detach(hint_button_back); 
	detach(hint_button_text); 
	detach(hint_output);
	
	detach(grid);

	detach(game_status_obj1);
	detach(game_status_obj2);

	detach(easy_scores);
	detach(intermediate_scores);
	detach(hard_scores);
	detach(expert_scores);

	
	for (int i = 0; i < pieces.size(); ++i) {
		detach(pieces.operator[](i));
		detach(buttons.operator[](i));
	}
	
}

void Splash_window::attachDifficulty() {
	current = difficulty;

	detachStart();

	attachInstructions();

	attachDiffButtons();

	attach(exit_button);
	attach(exit_button_back);
	attach(exit_button_text);
	
	detach(grid);

}

void Splash_window::attachInput(int difficulty) {

	game_diff = difficulty;

	detachInstructions();

	detachDiffButtons();

	detach(exit_button);
	detach(exit_button_back);
	detach(exit_button_text);

	detachBackground();

	attach(initials_box);
	attach(enter_button);

}

void Splash_window::attachEasy() {
	current = game;
	cout << "current: " <<current << endl;

	update_map(easy_order);
	update_correct_position();
	constructPieces(easy_order);
	attach(grid);

	attach(game_status_obj1);
	attach(game_status_obj2);

	attach(easy_scores);

	// Attach buttons 
	for (int i = 0; i < buttons.size(); ++i) 
		attach(buttons.operator[](i));
	

	//Update positon_map to match difficulty
	
	moves_remaining = 10;
	update_status_labels();

}

void Splash_window::attachIntermediate() {
	current = game;

	update_map(intermediate_order);
	update_correct_position();
	constructPieces(intermediate_order);
	attach(grid);

	attach(game_status_obj1);
	attach(game_status_obj2);

	attach(intermediate_scores);

	// Attach buttons 
	for (int i = 0; i < buttons.size(); ++i) {
		attach(buttons.operator[](i));
	}

	//Update positon_map to match difficulty
	
	moves_remaining = 20;
	update_status_labels();
	return;
}

void Splash_window::attachHard() {
	current = game;

	update_map(hard_order);
	update_correct_position();
	constructPieces(hard_order);
	attach(grid);

	attach(game_status_obj1);
	attach(game_status_obj2);

	attach(hard_scores);

	// Attach buttons 
	for (int i = 0; i < buttons.size(); ++i) {
		attach(buttons.operator[](i));
	}

	//Update positon_map to match difficulty
	
	moves_remaining = 40;
	update_status_labels();
	return;
}

void Splash_window::attachExpert() {
	current = game;

	update_map(expert_order);
	update_correct_position();
	constructPieces(expert_order);
	attach(grid);

	attach(game_status_obj1);
	attach(game_status_obj2);

	attach(expert_scores);

	// Attach buttons 
	for (int i = 0; i < buttons.size(); ++i) {
		attach(buttons.operator[](i));
	}

	//Update positon_map to match difficulty
	
	moves_remaining = 80;
	update_status_labels();
	return;
}

void Splash_window::attachEnd() {
	detach(exit_button);
	detach(exit_button_back);
	detach(exit_button_text);

	detach(hint_button);
	detach(hint_button_back);
	detach(hint_button_text);
	detach(hint_output);

	detach(grid);

	detach(game_status_obj1);
	detach(game_status_obj2);

	detach(easy_scores);
	detach(intermediate_scores);
	detach(hard_scores);
	detach(expert_scores);

	for (int i = 0; i < pieces.size(); ++i) {
		detach(pieces.operator[](i));
		detach(buttons.operator[](i));
	}

	attach(gameOver);
	attach(userScore);

	attach(leave_button);
	attach(leave_button_back);
	attach(leave_button_text);
	leave_exists = true;

	attach(replay_button);
	attach(replay_button_back);
	attach(replay_button_text);
	replay_exists = true; 

}

//used for identifying the row and collomn for moving the pieces around
int col2(int i) {
	switch (i)
	{
	case 1: case 5: case 9: case 13:
		return 1;
		break;
	case 2: case 6: case 10: case 14:
		return 2;
		break;
	case 3: case 7: case 11: case 15:
		return 3;
		break;
	case 4: case 8: case 12: case 16:
		return 4;
		break;
	}
}

int row2(int i) {
	if (i >= 1 && i < 5)
		return 1;
	else if (i >= 5 && i < 9)
		return 2;
	else if (i >= 9 && i < 13)
		return 3;
	else if (i >= 13 && i <= 16)
		return 4;
	else if (i == 0)
		return 0;
}

// Creates the game pieces from an image and checks what their order is in order to decide if red or green.
void Splash_window::constructPieces(Vector<int> order) {
	int ry;
	if (pieces.size() < 1) {
		for (int j = 0; j < order.size(); ++j)
			pieces.push_back(new Image(spots.operator[](j), "red_green.jpg"));
	}

	for (int i = 0; i < order.size(); ++i) {
		//cout << order.at(i);
		//cout << " " << order.at(i) << endl;

		ry = Y_PIECE[row2(order.at(i))];

		if (correct_order[i] == current_order[i])
			ry = ry + 770;

		if (order[i] == 0)
			pieces.operator[](i).set_mask(Point(1000, ry), 100, 100);
		else
			pieces.operator[](i).set_mask(Point(X_PIECE[col2(order.at(i))], ry), 100, 100);

		attach(pieces.operator[](i));
	
	}
	
}

void Splash_window::update_map(vector<int> order) {
	int count = 0;
	for (unsigned int i = 1; i < 5; ++i)
	{
		for (unsigned int j = 1; j < 5; ++j)
		{
			position_map[i][j] = order[count];
			++count;
		}
	}
}

void Splash_window::update_correct_position()
{
	//Updates current_order with the contents of position_map
	int count = 0;
	int num_incorrect = 0;
	for (unsigned int i = 1; i < 5; ++i)
	{
		for (unsigned int j = 1; j < 5; ++j)
		{
			//cout << position_map[i][j] << " ";
			current_order[count] = position_map[i][j];

			if (correct_order[count] != current_order[count])
				++num_incorrect;

			++count;
		}
		//cout << endl;
	}

	correct_position = num_incorrect;
	cout << "NUM INCORRECT: " << correct_position << endl;
}

void Splash_window::update_status_labels() {
	game_status_obj1.set_label(game_status1 + to_string(moves_remaining));
	game_status_obj2.set_label(game_status2 + to_string(correct_position));
}

void Splash_window::vector_copy() {/* This function copies the contents of poptition_map to
                                     copy_map which is used to calculate the hint*/
	copy_map = position_map;
}

void Splash_window::attachInstructions() {
	attach(instructionsObj0);
	attach(instructionsObj1);
	attach(instructionsObj2);
	attach(instructionsObj3);
	attach(instructionsObj4);
}

void Splash_window::detachInstructions() {
	detach(instructionsObj0);
	detach(instructionsObj1);
	detach(instructionsObj2);
	detach(instructionsObj3);
	detach(instructionsObj4);
}

void Splash_window::attachBackground() {
	attach(background);
	attach(backgroundBorder);
	attach(topLeft);
	attach(topRight);
	attach(bottomLeft);
	attach(bottomRight);

}

void Splash_window::detachBackground() {
	detach(background);
	detach(backgroundBorder);
	detach(topLeft);
	detach(topRight);
	detach(bottomLeft);
	detach(bottomRight);
}

void Splash_window::attachStart() {
	attach(splashText);
	attach(gameName);
	attach(Durian);
	attach(Isaac);
	attach(Ameya);
	attach(Layne);
	attach(start_button);
	attach(start_button_back2);
	attach(start_button_back);
	attach(start_button_back);
	attach(start_button_text);
}

void Splash_window::detachStart() {
	detach(start_button);
	detach(start_button_back);
	detach(start_button_back2);
	detach(start_button_text);
	detach(splashText);
	detach(gameName);
	detach(Durian);
	detach(Isaac);
	detach(Ameya);
	detach(Layne);
}

void Splash_window::attachDiffButtons() {
	attach(easy_button);
	attach(easy_button_back);
	attach(easy_button_text);

	attach(intermediate_button);
	attach(intermediate_button_back);
	attach(intermediate_button_text);

	attach(hard_button);
	attach(hard_button_back);
	attach(hard_button_text);

	attach(expert_button);
	attach(expert_button_back);
	attach(expert_button_text);
}

void Splash_window::detachDiffButtons() {
	detach(easy_button);
	detach(easy_button_back);
	detach(easy_button_text);

	detach(intermediate_button);
	detach(intermediate_button_back);
	detach(intermediate_button_text);

	detach(hard_button);
	detach(hard_button_back);
	detach(hard_button_text);

	detach(expert_button);
	detach(expert_button_back);
	detach(expert_button_text);
}
