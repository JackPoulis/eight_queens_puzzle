The queens_puzzle.c is a c programm that generates all possible solutions for the 8 queens puzzle.

About the puzzle:
The puzzle takes place on a 8 by 8 chess board.
The purpose is to fit 8 queens chess pieces on the board in a way that for every possible
couple of queens the queens does not threat one another.

The output is a list of numbers [0-7] with 8 numbers on every row
Each row represents a solution to the puzzle
and each number in the row is the position of the queen at the corresponding row on the board.
The position of the number in the row is the column of the board.
For example for the solution: [0] [4] [7] [5] [2] [6] [1] [3] we place
the first queen at the bottom left corner of the board (position 0)
the second queen at the 5th (position 4) row of the 2nd column
the third queen at the 8th (postition 7) row of the 3rd column etc.

For the 8 by 8 board all the possible solutions are the below 12 rows:
[0] [4] [7] [5] [2] [6] [1] [3]  
[0] [5] [7] [2] [6] [3] [1] [4]   
[1] [3] [5] [7] [2] [0] [6] [4]   
[1] [4] [6] [0] [2] [7] [5] [3]  
[1] [4] [6] [3] [0] [7] [5] [2]  
[1] [5] [0] [6] [3] [7] [2] [4]  
[1] [5] [7] [2] [0] [3] [6] [4]  
[1] [6] [2] [5] [7] [4] [0] [3]  
[1] [6] [4] [7] [0] [3] [5] [2]  
[2] [4] [1] [7] [0] [6] [3] [5]  
[2] [4] [7] [3] [0] [6] [1] [5]  
[2] [5] [1] [4] [7] [0] [6] [3]  
Note that those are the real solutions. 
The mirror solutions for each one of them has been removed for every possible axis of the board.