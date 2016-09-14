//////////////////////////////////////////////////////////////////////
/// @file board.cpp
/// @author Dalton Cole
/// @brief This cpp file defines the board class.
////////////////////////////////////////////////////////////////////// 

#include "board.h"

board::board() {
	// Default board size of 8
	boardSize = 8;

	// Vector to go inside the big vector
	vector<short> subVector;

	// Put zeros in small vector
	for(int i = 0; i < boardSize; i++) {
		subVector.push_back(0);
	}

	// Put 8 small vectors in the big vector
	for(int i = 0; i < boardSize; i++) {
		b.push_back(subVector);
	}

	// Place a 1 on the board at the starting position
	last = 1;
	previous_x = boardSize/2;
	previous_y = boardSize/2;
	b[previous_x][previous_y] = 1;
}

board::board(short n) {
	// Set boardSize to n
	boardSize = n;

	// Vector to go inside the big vector
	vector<short> subVector;

	// Put zeros in small vector
	for(int i = 0; i < boardSize; i++) {
		subVector.push_back(0);
	}

	// Put 8 small vectors in the big vector
	for(int i = 0; i < boardSize; i++) {
		b.push_back(subVector);
	}

	// Place a 1 on the board at the starting position
	last = 1;
	previous_x = boardSize/2;
	previous_y = boardSize/2;
	b[previous_x][previous_y] = 1;
}

board & board::operator =(const board & rhs) {
	// Set all variables equal to the rhs's variables
	b = rhs.b;
	last = rhs.last;
	boardSize = rhs.boardSize;
	previous_x = rhs.previous_x;
	previous_y = rhs.previous_y;

	return *this;
}

void board::print() {
	// For every y point
	for(int i = 0; i < boardSize; i++) {
		// Print left hand most boarder
		cout << "| ";

		// For every x point
		for(int j = 0; j < boardSize; j++) {
			// Print point and divider
			cout << setw(3) << b[j][i] << " | ";
		}
		// Go to next line
		cout << endl;
		// Add y axis divider
		for(int j = 0; j < boardSize; j++) {
			cout << "------";
		}
		cout << endl;
	}
	return;
}

void board::update(short x, short y, short next_number) {
	// Update last
	last++;
	
	// Place knight
	b[x][y] = next_number;

	// Update last placed positions
	previous_x = x;
	previous_y = y;

	return;
}

vector<point> board::moves() {
	// Vector of possible moves
	vector<point> moves;

	// Point to place in moves vector
	point p;

	// ------------------------------------------------------------------------
	// left up up
	short x = previous_x - 1;
	short y = previous_y - 2;

	// If in board range
	if(x >= 0 && y >= 0) {
		// If spot is not occupied or if it will complete the tour
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			// Add point to moves vector
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// right up up
	x = previous_x + 1;
	y = previous_y - 2;

	// If in board range
	if(x < boardSize && y >= 0) {
		// If spot is not occupied or if it will complete the tour
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			// Add point to moves vector
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// left down down
	x = previous_x - 1;
	y = previous_y + 2;

	// If in board range
	if(x >= 0 && y < boardSize) {
		// If spot is not occupied or if it will complete the tour
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			// Add point to moves vector
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// right down down
	x = previous_x + 1;
	y = previous_y + 2;

	// If in board range
	if(x < boardSize && y < boardSize) {
		// If spot is not occupied or if it will complete the tour
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			// Add point to moves vector
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// left left up
	x = previous_x - 2;
	y = previous_y - 1;

	// If in board range
	if(x >= 0 && y >= 0) {
		// If spot is not occupied or if it will complete the tour
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			// Add point to moves vector
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// left left down
	x = previous_x - 2;
	y = previous_y + 1;

	// If in board range
	if(x >= 0 && y < boardSize) {
		// If spot is not occupied or if it will complete the tour
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			// Add point to moves vector
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// right right up
	x = previous_x + 2;
	y = previous_y - 1;

	// If in board range
	if(x < boardSize && y >= 0) {
		// If spot is not occupied or if it will complete the tour
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			// Add point to moves vector
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// right right down
	x = previous_x + 2;
	y = previous_y + 1;

	// If in board range
	if(x < boardSize && y < boardSize) {
		// If spot is not occupied or if it will complete the tour
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			// Add point to moves vector
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}
	// ------------------------------------------------------------------------

	return moves;
}

short board::get_last() {
	// Return last move number
	return last;
}

// Sort function to sort possible moves from least likely to most likely
// Used by sort()
bool sort_function (point i, point j) { return (i.possible_moves < j.possible_moves); }

vector<point> board::best_move(vector<point> moves) {
	// Initial x and y
	short remember_x = previous_x;
	short remember_y = previous_y;

	// Find number of moves the next knight will be able to do
	for(int i = 0; i < moves.size(); i++) {
		previous_x = moves[i].x;
		previous_y = moves[i].y;

		moves[i].possible_moves = (this -> moves()).size();
	}

	// Sort the moves from least number of future moves to most
	sort(moves.begin(), moves.end(), sort_function);

	// Reset x and y to initial x and y
	previous_x = remember_x;
	previous_y = remember_y;

	return moves;
}

void board::normalize(short x, short y) {
	// Upper limit of move changes
	for(int max = 0; max < (boardSize * boardSize); max++) {
		// If initial spot is 1, we're done
		if(b[x][y] == 1) {
			break;
		} else {
			// Add one to each spot
			for(int i = 0; i < boardSize; i++) {
				for(int j = 0; j < boardSize; j++) {
					b[j][i] = (b[j][i] % (boardSize * boardSize)) + 1;
				}
			}
		}
	}

	return;
}