#ifndef POINT_H
#define POINT_H

struct point {
	short x;
	short y;
	short possible_moves;
};

struct point_sort {
	bool operator() (point i, point j) { return (i.possible_moves < j.possible_moves);}
} sort_please;

#endif