#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include <thread>
#include <chrono>
#include "Splash_window.h"
#include "std_lib_facilities_5.h"

int main()
try {
	if (H112 != 201708L)error("Error: incorrect std_lib_facilities_5.h version ",
		H112);
	Splash_window swin1(Point(100, 100), 600, 600, "Team 39: 15 Puzzle");

	return gui_main();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}