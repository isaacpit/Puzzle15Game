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

#include "Window.h"
#include "std_lib_facilities_5.h"
#include "Graph.h"
#include "GUI.h"
#include "Graph.h"
#include "GUI.h"
#include "Scoreboard.h"
#include "std_lib_facilities_5.h"

using namespace Graph_lib;

enum State
{
	splash = 0, difficulty, game
};

class Splash_window : Graph_lib::Window { 
public:
	// Constructor 
	Splash_window(Point xy, int w, int h, const string title);

private:

	// Functions used to switch screens 
	void attachDifficulty();
	void attachSplash();
	void attachEasy();
	void attachIntermediate();
	void attachHard();
	void attachExpert();
	void attachInput(int difficulty);
	void attachEnd();
	void constructPieces(Vector<int> order); // Creates gamepieces

	// Vectors used for game pieces and buttons
	Vector_ref<Point> spots;
	Vector_ref<Image> pieces;
	Vector_ref<Button> buttons;
	
	
	// Keeps track of all the pieces. NOTE: position_map is 6x6 not 4x4.
	vector<vector<int>> position_map = {
		{-1,-1,-1,-1,-1,-1 },
		{-1, 0, 1, 2, 3,-1 },
		{-1, 4, 5, 6, 7,-1 },
		{-1, 8, 9,10,11,-1 },
		{-1,12,13,14,15,-1 },
		{-1,-1,-1,-1,-1,-1 }			};

	Vector<Vector<int>> copy_map = {
		{ -1,-1,-1,-1,-1,-1 },
		{ -1, 10, 1, 2, 3,-1 },
		{ -1, 4, 5, 6, 7,-1 },
		{ -1, 8, 9,0,11,-1 },
		{ -1,12,13,14,15,-1 },
		{ -1,-1,-1,-1,-1,-1 } };
									
	// Used to initialize or compare orders of game pieces
	// 0 symbolizes, empty piece.
	vector<int> current_order = { 1,  2,  3, 4,
								  5,  6,  7, 8,
								  9, 10, 11, 12,
								 13, 14, 15, 0 };
	const Vector<int> correct_order = { 1,  2,  3, 4,
										5,  6,  7, 8,
										9, 10, 11, 12,
									    13, 14, 15, 0 };
	const Vector<int> easy_order = { 1,  2,  3,  4,
									5,  6,  12,  7,
									9,  10, 0, 15,
									13, 14, 8, 11 };
	const Vector<int> intermediate_order = { 1,  6,  3,  4,
											5,  0,  2,  11,
											9,  10, 14,  7,
											13, 15, 12, 8 };
	const Vector<int> hard_order = { 4,  8, 12, 15,
									 3, 0,  7, 11,
									 9, 2,  1, 10,
									 13, 14,  5,  6 };
	
	const Vector<int> expert_order = { 0, 12,  11, 13,
									   15, 14,  10,  9,
										3,  7,  6,  2,
										4,  8,  5,  1 };

	// Constants for image masking
	const Vector <int> X_PIECE = { 0, 25, 155, 285, 415 };
	const Vector <int> Y_PIECE = { 0, 25, 170, 325, 475 };
	
	int moves_remaining = 0;	//Tracks number of moves til game over
	int correct_position = 0; //Keeps track of the number of pieces in incorrect positions
	int game_diff = 0; 

	// Text Objects
	Text splashText;
	Text gameName;
	Text Durian;
	Text Isaac;
	Text Ameya;
	Text Layne;

	Text gameOver;
	Text userScore;

	// Constants for  graphical objects
	const int X_BUFFER = x_max() / 6;
	const int Y_BUFFER = y_max() / 6;
	const int BUTTON_WIDTH = x_max() / 4;
	const int BUTTON_HEIGHT = y_max() / 8;
	const int PIECE_WIDTH = (x_max() - 2 * X_BUFFER) / 4;
	const int PIECE_HEIGHT = (y_max() - 2 * Y_BUFFER) / 4; 

	// Strings used for graphical purposes
	string instructions0 = "Goal: get game pieces in ascending order ";
	string instructions1 = "  from left to right with the empty piece";
	string instructions2 = "  in the bottom right corner.";
	string instructions3 = "1) Click a game piece adjacent to empty square.";
	string instructions4 = "2) Repeat until moves run out.";

	string game_status1 = "Moves Remaining: ";
	string game_status2 = "Tiles Remaining: ";

	string user_input = "";

	// Text used for graphical purposes
	Text instructionsObj0;
	Text instructionsObj1;
	Text instructionsObj2;
	Text instructionsObj3;
	Text instructionsObj4;

	Text game_status_obj1;
	Text game_status_obj2;

	Text hint_output;

	// Aesthetics
	Graph_lib::Rectangle background;
	Graph_lib::Rectangle backgroundBorder;
	Graph_lib::Circle topLeft;
	Graph_lib::Circle topRight;
	Graph_lib::Circle bottomLeft;
	Graph_lib::Circle bottomRight;

	// Format:
	// Button 
	// Rectangular Background 
	// Text
	Button easy_button;
	Graph_lib::Rectangle easy_button_back;
	Text easy_button_text;

	Button intermediate_button;
	Graph_lib::Rectangle intermediate_button_back;
	Text intermediate_button_text;

	Button hard_button;
	Graph_lib::Rectangle hard_button_back;
	Text hard_button_text;

	Button expert_button;
	Graph_lib::Rectangle expert_button_back;
	Text expert_button_text;

	Button start_button;
	Graph_lib::Rectangle start_button_back;
	Graph_lib::Rectangle start_button_back2;
	Text start_button_text;

	Button exit_button;
	Graph_lib::Rectangle  exit_button_back;
	Text exit_button_text;

	Button hint_button;
	Graph_lib::Rectangle hint_button_back;
	Text hint_button_text;
	bool hint_exists = false; //Prevents a crash when trying to exit from difficulty screen for the first time

	Button replay_button;
	Graph_lib::Rectangle replay_button_back;
	Text replay_button_text;
	bool replay_exists = false;

	Button leave_button;
	Graph_lib::Rectangle leave_button_back;
	Text leave_button_text;
	bool leave_exists = false;

	In_box initials_box;
	Button enter_button;

	Lines grid;
	
	State current = splash;

	Scoreboard easy_scores;
	Scoreboard intermediate_scores;
	Scoreboard hard_scores;
	Scoreboard expert_scores;

	// Callbacks 
	static void cb_start(Address, Address window);
	static void cb_easy(Address, Address window);
	static void cb_intermediate(Address, Address window);
	static void cb_hard(Address, Address window);
	static void cb_expert(Address, Address window);
	static void cb_exit(Address, Address window);
	static void cb_enter(Address, Address window);
	static void cb_hint(Address, Address window);
	static void cb_leave(Address, Address window);
	static void cb_replay(Address, Address window);
	
	// Functions used by callbacks
	void start();
	void easy();
	void intermediate();
	void hard();
	void expert();
	void exit();
	void enter();
	void hint();
	void leave();
	void replay();

	//int find_num(int row_num,int column_num);
	//int hint_value(int num, int row_zero, int col_zero);
	void vector_copy();
	int find_hint(int row_num, int column_num, int row_zero, int col_zero);
	int hint_value(int num, int row_num, int column_num, int row_zero, int col_zero);
	int last_num = -2;

	void move_piece(int index);
	void update_order();
	void update_map(vector<int> order);
	void update_correct_position();
	void update_status_labels();
	int calculate_score();
	int calc_hint(int a, int b);
	//Functions for making code neater
	void attachInstructions();
	void detachInstructions();
	void attachBackground();
	void detachBackground();
	void attachStart();
	void detachStart();
	void attachDiffButtons();
	void detachDiffButtons();
};

