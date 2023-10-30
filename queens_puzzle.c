#include <stdio.h>
#include <stdlib.h>

int main()
{	
	//Variables initialization
	int i, j, A[8], B[92][8], C[8][8], col, row, flag, end, n_solution, k, l, m, mirrored;

	int* D[8];
	for (i = 0; i < 8; i++)
        D[i] = (int*)malloc(1 * sizeof(int));

	for (i = 0; i < 8; i++)
	{
		A[i] = 16; //Queens initially are placed in the position 16 (out of the board)
		for (j = 0; j < 92; j++)
		{
			B[j][i] = 0;
		}
	}
	n_solution = 0;
	col = 0;
	row = 0;
	end = 0;

	//Find all solutions
	do
	{
		flag = 1;

		if ((row == 0) && (col == 8))
		{
			for (i = 0; i < 8; i++)
			{
				B[n_solution][i] = A[i];
			}
			n_solution++;
			col = col - 2;
			row = A[col] + 1;
			A[7] = 16;
			A[6] = 16;
		}

		if ((col == 0) && (row == 8))
		{
			end = 1;
		}

		if (col > 0)
		{
			for (i = 0; i < col; i++)
			{
				if ((row == A[i]) || (row == A[i] + (col - i)) || (row == A[i] - (col - i)))
				{
					flag = 0;
				}
			}
		}
		else
		{
			flag = 1;
		}

		if (row == 8)
		{
			A[col] = 16;
			col--;
			row = A[col];
		}
		else if (flag == 1)
		{
			A[col] = row;
			col++;
			row = -1;
		}

		row++;
	} while (end == 0);

	//Check and remove mirrored solutions
	for (k = 0; k < 91; k++)
	{
		if (B[k][0] != 16)
		{
			for (i = 0; i < 8; i++)
			{
				C[0][i] = B[k][i];
				C[1][7 - B[k][i]] = i;
				C[2][7 - i] = 7 - B[k][i];
				C[3][B[k][i]] = 7 - i;
				C[4][7 - i] = B[k][i];
				C[5][i] = 7 - B[k][i];
				C[6][7 - B[k][i]] = 7 - i;
				C[7][B[k][i]] = i;
			}
			for (l = 91; l > k; l--)
			{
				for (m = 1; m < 8; m++)
				{
					mirrored = 1;
					for (i = 0; i < 8; i++)
					{
						if (B[l][i] != C[m][i])
						{
							mirrored = 0;
						}
					}
					if (mirrored == 1)
					{
						for (i = 0; i < 8; i++)
						{
							B[l][i] = 16;
						}
					}
				}
			}
		}
	}

	//Print solution on stdout
	for (i = 0; i < 92; i++)
	{
		if (B[i][0] != 16)
		{
			for (j = 0; j < 8; j++)
			{
				printf("[%d] ", B[i][j]);
				if (j == 7)
				{
					printf("\n");
				}
			}
		}
	}

	return 0;
}
