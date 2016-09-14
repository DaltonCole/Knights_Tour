#ifndef BOARD_H
#define BOARD_H

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
		vector<vector<short> > b;
		short last;
		short boardSize;
		short previous_x;
		short previous_y;
};

#endif