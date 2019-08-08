# Sudoku

<img src = "https://github.com/oddek/Sudoku/blob/master/Sudoku/img/sudo1.png" width ="50%">

Sudoku generator and solver made with C++ and SFML

The algorithm for solving is straight forward brute force, nothing clever.

Algorithm for generating:
1. Fill valid sudoku grid.
2. Then for each number in grid (random order), remove it, check if sudoku has more than one solution, if true: insert number back in.

This takes anywhere from 0.1 seconds to 3-4 seconds.


### Screenshots:
<img src = "https://github.com/oddek/Sudoku/blob/master/Sudoku/img/sudo2.png" width ="50%"> <img src = "https://github.com/oddek/Sudoku/blob/master/Sudoku/img/sudo3.png" width ="50%"> <img src = "https://github.com/oddek/Sudoku/blob/master/Sudoku/img/sudo4.png" width ="50%">


### Kent Odde, August 2019
