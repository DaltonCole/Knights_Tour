//////////////////////////////////////////////////////////////////////
/// @file board.h
/// @author Dalton Cole
/// @brief This header file declares the board class.
////////////////////////////////////////////////////////////////////// 

#ifndef BOARD_H
#define BOARD_H

//////////////////////////////////////////////////////////////////////
/// @class board
/// @brief This class stores the board for the Knight's touring problem
/// along with calculating moves that the knights can do.
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn board()
/// @brief This function creates the initial starting board of all zeros
///		and a 1 in starting position
/// @post board is created and all class variables are set
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn board(short n)
/// @brief This function creates the initial starting board of size n by n
/// 	with all zeros and a 1 in starting position
/// @post board is created and all class variables are set
/// @param n is the size of the board
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn void print()
/// @brief This function prints the board
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn void update(short x, short y, short next_number)
/// @brief This function updates the board with the next number
/// @pre next_number contains the previous number + 1
/// @post The board is updated such that b[x][y] = next_number
/// @param x is the x axis point
/// @param y is the y axis point
/// @param is the number to put into b[x][y]
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn vector<point> moves()
/// @brief This function finds all possible moves from the previous x and y position
/// @pre previous_x and previous_y are the previous x and y moves
/// @post Possible moves are returned
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn short get_last()
/// @brief Gets the last variable
/// @post this -> last is returned
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn vector<point> best_move(vector<point> moves)
/// @brief This function orders the moves from best to worse according to
/// 	which move has the least possible moves afterwards (Warnsdorf's rule)
/// @pre moves are valid moves
/// @post The moves are returned is order from least future moves to most
/// @param moves holds a vector of possible moves
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn void normalize(short x, short y)
/// @brief This function normalizes the board such that b[x][y] = 1 and
///		all other positions are changed respecively
/// @pre x and y are on the board
/// @post b is updated such that b[x][y] = 1
/// @param x is the x axis point to be 1
/// @param y is the y axix point to be 1
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn board & operator =(const board & rhs)
/// @brief This function sets the board equal to the rhs
/// @post this = rhs;
/// @param rhs is the desired board to set this board equal to
////////////////////////////////////////////////////////////////////// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "point.h"
using namespace std;

class board {
	public:
		board();
		board(short n);
		void print();
		void update(short x, short y, short next_number);
		vector<point> moves();
		short get_last();
		vector<point> best_move(vector<point> moves);
		void normalize(short x, short y);

		board & operator =(const board & rhs);

	private:
		// The board
		vector<vector<short> > b;
		// The last intager to be placed on the board
		short last;
		// The board size
		short boardSize;
		// The last x position a knight was placed
		short previous_x;
		// The last y position a knight was placed
		short previous_y;
};

#endif