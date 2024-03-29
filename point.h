//////////////////////////////////////////////////////////////////////
/// @file point.h
/// @author Dalton Cole
/// @brief This header file declares the point struct.s
////////////////////////////////////////////////////////////////////// 

#ifndef POINT_H
#define POINT_H

struct point {
	// X position
	short x;
	// Y position
	short y;
	// Number of possible moves from that point
	short possible_moves;
};

#endif