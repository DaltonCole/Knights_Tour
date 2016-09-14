# Knight's Tour

This program solves the Knight's Tour problem for a n by n board where n is even.

## Algorthm Used

* A Depth First Search approach is used
* The heuristic used is Warnsdorf's rule
  * The next knight to try is the knight with the fewest future moves

## Arguments

This program accepts either 0, 1, 2, or 3 arguments.

* If 0 arguments are specified, then the initial position will be 5 5 on an 8 by 8 board
* If 1 argument is specified, then it is the size of the board
  * Example: a.out 8
    * This will use an 8 by 8 board
* If 2 arguments are specified, they are the x and y position for the initial knight
  * Example: a.out 0 0
    * The knight will start on spot 0 0
* If 3 arguments are specified, they are the board size and the x and y position for the initial knight
  * Example a.out 8 0 0
    * The knight will start on spot 0 0 on an 8 by 8 board

## Example
```
./a.out 8 0 0
```

```
|   1 |   4 |  63 |  34 |  45 |   6 |  55 |  32 | 
------------------------------------------------
|  62 |  37 |   2 |   5 |  50 |  33 |  46 |   7 | 
------------------------------------------------
|   3 |  64 |  39 |  44 |  35 |  56 |  31 |  54 | 
------------------------------------------------
|  38 |  61 |  36 |  49 |  42 |  51 |   8 |  47 | 
------------------------------------------------
|  19 |  40 |  43 |  24 |  57 |  48 |  53 |  30 | 
------------------------------------------------
|  60 |  25 |  20 |  41 |  52 |  11 |  14 |   9 | 
------------------------------------------------
|  21 |  18 |  27 |  58 |  23 |  16 |  29 |  12 | 
------------------------------------------------
|  26 |  59 |  22 |  17 |  28 |  13 |  10 |  15 | 
------------------------------------------------
Program finished in: 0.001252 seconds.
```