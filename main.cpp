#include <iostream>
#include <stack>
#include "board.cpp"
#include "point.h"

using namespace std;

int main() {
	// Current board
	board current_board;
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
		if(depthSearch.size() == 0) {
			break;
		}
		// Pop board off of stack
		current_board = depthSearch.top();
		depthSearch.pop();

		//cout << depthSearch.size() << endl;
		//cout << current_board.get_last() << endl;
		//current_board.print();
		
		/*
		if(current_board.get_last() > 40) {
			current_board.print();
			cout << current_board.get_last() << endl;
		}
		*/

		// Calculates moves
		points = current_board.moves();

		// Sort moves in order of best to worst
		points = current_board.best_move(points);

		// Add boards from worst to best updates onto the stack
		for(int i = points.size() - 1; i >= 0; i--) {
			// Set new board equal to old board
			new_board = current_board;

			// Update new board with next knight's spot
			new_board.update(points[i].x, points[i].y, new_board.get_last() + 1);
			// If 65 moves have been completed (including initial placement), exit loop
			if(new_board.get_last() == 8*8 + 1) {
				new_board.update(points[i].x, points[i].y, 1);
				get_out = true;
				break;
			}
			depthSearch.push(new_board);
		}

		if(get_out == true) {
			break;
		}
	}
cout << endl;
	if(get_out == true) {
		new_board.print();
	} else {
		cout << "NO BOARD FOUND" << endl;
		current_board.print();
	}

	return 0;
}