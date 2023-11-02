The queens_puzzle.c is a c programm that generates all fundamental solutions for the 8 queens puzzle using a brute force variant.

About the puzzle:
The purpose is to fit 8 queens chess pieces on the 8 by 8 chess board in a way that no two queens threaten each other.
Wikipedia article: https://en.wikipedia.org/wiki/Eight_queens_puzzle
 
The output is a list of the 12 fundamental solutions using the chess coordinates system.

The output:<br>
1: [A,1] [B,5] [C,8] [D,6] [E,3] [F,7] [G,2] [H,4]<br>
2: [A,1] [B,6] [C,8] [D,3] [E,7] [F,4] [G,2] [H,5]<br>
3: [A,2] [B,4] [C,6] [D,8] [E,3] [F,1] [G,7] [H,5]<br>
4: [A,2] [B,5] [C,7] [D,1] [E,3] [F,8] [G,6] [H,4]<br>
5: [A,2] [B,5] [C,7] [D,4] [E,1] [F,8] [G,6] [H,3]<br>
6: [A,2] [B,6] [C,1] [D,7] [E,4] [F,8] [G,3] [H,5]<br>
7: [A,2] [B,6] [C,8] [D,3] [E,1] [F,4] [G,7] [H,5]<br>
8: [A,2] [B,7] [C,3] [D,6] [E,8] [F,5] [G,1] [H,4]<br>
9: [A,2] [B,7] [C,5] [D,8] [E,1] [F,4] [G,6] [H,3]<br>
10: [A,3] [B,5] [C,2] [D,8] [E,1] [F,7] [G,4] [H,6]<br>
11: [A,3] [B,5] [C,8] [D,4] [E,1] [F,7] [G,2] [H,6]<br>
12: [A,3] [B,6] [C,2] [D,5] [E,8] [F,1] [G,7] [H,4]<br>

All the solutions are 92. The rotated (by 90,180,270) and reflected (on horizontal, vertical and the 2 diagonal axies) solutions for each fundamental solution are not included. 