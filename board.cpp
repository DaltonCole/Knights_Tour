#include "board.h"

board::board() {
	boardSize = 8;
	vector<short> subVector;

	for(int i = 0; i < boardSize; i++) {
		subVector.push_back(0);
	}
	for(int i = 0; i < boardSize; i++) {
		b.push_back(subVector);
	}
	last = 1;
	previous_x = boardSize/2;
	previous_y = boardSize/2;
	b[previous_x][previous_y] = 1;
}

board::board(short n) {
	boardSize = n;
	vector<short> subVector;
	for(int i = 0; i < boardSize; i++) {
		b.push_back(subVector);
		for(int j = 0; j < boardSize; j++) {
			b[i][j] = 0;
		}
	}
	last = 1;
	previous_x = boardSize/2;
	previous_y = boardSize/2;
	b[previous_x][previous_y] = 1;
}

board & board::operator =(const board & rhs) {
	b = rhs.b;
	last = rhs.last;
	boardSize = rhs.boardSize;
	previous_x = rhs.previous_x;
	previous_y = rhs.previous_y;

	return *this;
}

void board::print() {
	for(int i = 0; i < boardSize; i++) {
		cout << "| ";
		for(int j = 0; j < boardSize; j++) {
			if(b[j][i] < 10) {
				cout << b[j][i] << "  | ";
			}
			else {
				cout << b[j][i] << " | ";
			}
		}
		cout << endl;
		for(int j = 0; j < boardSize; j++) {
			cout << "-----";
		}
		cout << endl;
	}
	return;
}

void board::update(short x, short y, short next_number) {
	last++;
	
	b[x][y] = next_number;
	previous_x = x;
	previous_y = y;

	return;
}

vector<point> board::moves() {
	vector<point> moves;
	point p;

	// left up up
	short x = previous_x - 1;
	short y = previous_y - 2;

	if(x >= 0 && y >= 0) {
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}

	// right up up
	x = previous_x + 1;
	y = previous_y - 2;

	if(x < boardSize && y >= 0) {
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}

	// left down down
	x = previous_x - 1;
	y = previous_y + 2;

	if(x >= 0 && y < boardSize) {
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}

	// right down down
	x = previous_x + 1;
	y = previous_y + 2;

	if(x < boardSize && y < boardSize) {
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}

	// left left up
	x = previous_x - 2;
	y = previous_y - 1;

	if(x >= 0 && y >= 0) {
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}

	// left left down
	x = previous_x - 2;
	y = previous_y + 1;

	if(x >= 0 && y < boardSize) {
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}

	// right right up
	x = previous_x + 2;
	y = previous_y - 1;

	if(x < boardSize && y >= 0) {
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}

	// right right down
	x = previous_x + 2;
	y = previous_y + 1;

	if(x < boardSize && y < boardSize) {
		if(b[x][y] == 0 || (b[x][y] == 1 && last == (boardSize * boardSize))) {
			p.x = x;
			p.y = y;
			moves.push_back(p);
		}
	}

	return moves;
}

short board::get_last() {
	return last;
}

bool sort_function (point i, point j) { return (i.possible_moves < j.possible_moves); }

vector<point> board::best_move(vector<point> moves) {
	short remember_x = previous_x;
	short remember_y = previous_y;

	for(int i = 0; i < moves.size(); i++) {
		previous_x = moves[i].x;
		previous_y = moves[i].y;

		moves[i].possible_moves = (this -> moves()).size();
	}

	sort(moves.begin(), moves.end(), sort_function);

	previous_x = remember_x;
	previous_y = remember_y;

	return moves;
}