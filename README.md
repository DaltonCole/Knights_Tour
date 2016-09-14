# Knight's Tour

This program solves the Knight's Tour problem for a n by n board where n is even.

## Algorthm Used

* A Depth First Search approach is used
* The heuristic used is Warnsdorf's rule
  * The next knight to try is the knight with the fewest future moves

## Arguments

This program accepts either 0, 1, 2, or 3 arguments.

* If 1 argument is specified, then it is the size of the board
  * Example: a.out 8
    This will use an 8 by 8 board
* If 2 arguments are specified, they are the x and y position for the initial knight
  * Example: a.out 0 0
    The knight will start on spot 0 0
* If 3 arguments are specified, they are the board size and the x and y position for the initial knight
  * Example a.out 8 0 0
    The knight will start on spot 0 0 on an 8 by 8 board