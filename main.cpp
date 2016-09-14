//////////////////////////////////////////////////////////////////////
/// @file main.cpp
/// @author Dalton Cole
/// @brief This is the driver file for the knight's tour problem
////////////////////////////////////////////////////////////////////// 

#include <iostream>
#include <stack>
#include <ctime>
#include "board.cpp"
#include "point.h"

using namespace std;

int main(int argc, char* argv[]) {
	// Keep track of program start time
	clock_t start = clock();

	// Default board size = 8
	short board_size = 8;

	// If there are 2 or 4 elements, set board size
	if(argc == 2 || argc == 4) {
		board_size = atoi(argv[1]);

		// If user wants an odd sized board, tell them that none exists
		if(board_size % 2 == 1) {
			cout << "There is no Knight's Tour for odd sized boards." << endl;
			return 0;
		}
	}

	// Current board
	board current_board(board_size);
	// Newly created board from move
	board new_board;

	// Stack for depth first search
	stack<board> depthSearch;

	// Push starter board onto stack
	depthSearch.push(current_board);

	// Empty vector of points
	vector<point> points;

	// Boolean to see if we are done
	bool get_out = false;

	while(true) {
		// If stack is empty, no solution will be found. :(
		if(depthSearch.size() == 0) {
			break;
		}

		// Pop board off of stack
		current_board = depthSearch.top();
		depthSearch.pop();

		// Calculates moves
		points = current_board.moves();

		// Sort moves in order of best to worst
		points = current_board.best_move(points);

		// Add updated boards from worst to best onto the stack
		for(int i = points.size() - 1; i >= 0; i--) {
			// Set new board equal to old board
			new_board = current_board;

			// Update new board with next knight's spot
			new_board.update(points[i].x, points[i].y, new_board.get_last() + 1);

			// If n*n + 1 moves have been completed (including initial placement), exit loop
			if(new_board.get_last() == ((board_size * board_size) + 1)) {
				// Update so the n*n+1 spot says 1 again
				new_board.update(points[i].x, points[i].y, 1);
				// WE WIN, SO WE'RE DONE!
				get_out = true;
				break;
			}
			// Add board to stack
			depthSearch.push(new_board);
		}

		// WE WIN, SO WE'RE DONE!
		if(get_out == true) {
			break;
		}
	}

	if(get_out == true) {
		// If user wants the starting position as a certain point, set it
		if(argc == 3) {
			if(atoi(argv[1]) < board_size && atoi(argv[2]) < board_size) {
				new_board.normalize(atoi(argv[1]), atoi(argv[2]));
			} else {
				cout << "Board cannot be normalized" << endl;
			}
		} else if (argc == 4) {
			if(atoi(argv[2]) < board_size && atoi(argv[3]) < board_size) {
				new_board.normalize(atoi(argv[2]), atoi(argv[3]));
			} else {
				cout << "Board cannot be normalized" << endl;
			}
		} 

		new_board.print();
	} else {
		cout << "NO BOARD FOUND" << endl;

		// If user wants the starting position as a certain point, set it
		if(argc == 3) {
			if(atoi(argv[1]) < board_size && atoi(argv[2]) < board_size) {
				current_board.normalize(atoi(argv[1]), atoi(argv[2]));
			} else {
				cout << "Board cannot be normalized" << endl;
			}
		} else if (argc == 4) {
			if(atoi(argv[2]) < board_size && atoi(argv[3]) < board_size) {
				current_board.normalize(atoi(argv[2]), atoi(argv[3]));
			} else {
				cout << "Board cannot be normalized" << endl;
			}
		} 

		current_board.print();
	}

	// Print how long program took
	cout << "Program finished in: " << ((std::clock() - start) / (double) CLOCKS_PER_SEC) << " seconds." << endl;

	return 0;
}

