#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int** iso_g; //Isometry group 2D array

void generate_isometry_group(int a[]){
    int i;
    for (i = 0; i < 8; i++){
        /*Generate all possible versions of the solution "a"
		with rotation and translation (isometry group) */
        iso_g[0][i] = a[i];
        iso_g[1][7 - a[i]] = i;
        iso_g[2][7 - i] = 7 - a[i];
        iso_g[3][a[i]] = 7 - i;
        iso_g[4][7 - i] = a[i];
        iso_g[5][i] = 7 - a[i];
        iso_g[6][7 - a[i]] = 7 - i;
        iso_g[7][a[i]] = i;
    }
}

bool identical(int a[], int b[]){
	//Checks is two chess board solutions are identical
    int i;
    bool identical = true;
    for (i = 0; i < 8; i++){
        /*If one position is different then the
    	two arrays are different*/
        if (a[i] != b[i]){
            identical = false;
            break;
        }
    }
    return identical;
}

int main(){	
	//Variables initialization
	int i, j, A[8], col, row, n_solution, k, l, m;
    bool threat, end;

    int** B = (int**) malloc(sizeof(int*));
	iso_g = (int**) malloc(8*sizeof(int*));
	for (i = 0; i < 8; i++){
		iso_g[i] = (int*) malloc(8*sizeof(int));
	}

	for (i = 0; i < 8; i++)
	{
		A[i] = 16; //Queens initially are placed in the position 16 (out of the board)
	}
	n_solution = 0;
	col = 0;
	row = 0;
	end = false;

	//Find all solutions
	do{
        //If row is 0 column is 8 then a solution is found
		if ((row == 0) && (col == 8)){ 
            generate_isometry_group(A);
			/*All 8 possible rotations and reflections 
			of a solution consist an isometry group*/
            bool discard = false; //Flag to discard solution if not unique
            for (i=0;i<n_solution;i++){ //For each previously found solution
                for (j=0;j<8;j++){ //For each of the current isometry solutions
                    if (identical(B[i],iso_g[j])){ //Check if the solutions are identical
						/*Identical solutions are considered two solutions 
						that belong to the same isometry group*/
                        discard = true;
                        break;
                    }
                }
                if(discard == true)break;
            }

            if(discard == false){ //Save the unique solution
                B = (int**)realloc(B, (n_solution+1) * sizeof(int*));
                B[n_solution] = (int*) malloc(8 * sizeof(int));
                for (i = 0; i < 8; i++){
                    B[n_solution][i] = A[i];
                }
                n_solution++;
            
                col = col - 2;
                row = A[col] + 1;
                A[7] = 16;
                A[6] = 16;
            }
		}

		if ((col == 0) && (row == 8)) end = true; //All possible solutions have been found 

        threat = false;
		if (col > 0){
			for (i = 0; i < col; i++){ //Check if position (col,row) is threatened
				if ((row == A[i]) || (row == A[i] + (col - i)) || (row == A[i] - (col - i))){
					threat = true;
				}
			}
		}

		if (row == 8){ //Dead end reached
			A[col] = 16;
			col--; //Backtrack to previous column
			row = A[col];
		}else if (threat == false){ //Valid position found
			A[col] = row; //Save the position
			col++; //Move to next column
			row = -1; //Reset row variable
		}
		row++;
	} while (end == false);

	// Print solution on stdout
	for (i = 0; i < n_solution; i++){
        for (j = 0; j < 8; j++){
            printf("[%d] ", B[i][j]);
        }
        printf("\n");
	}

    //Free allocated memory
    for (i=0; i<n_solution; ++i) {
        free(B[i]);
    }
    free(B);

	for(i=0; i<8; i++){
		free(iso_g[i]);
	}
	free(iso_g);

	return 0;
}
