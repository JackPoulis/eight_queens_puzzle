#include <stdio.h>

int main()
{	
	//Variables initialization
	int i, j, A[8], B[92][8], C[8][8], col, row, flag, end, c, k, l, m, issame;

	for (i = 0; i <= 7; i++)
	{
		A[i] = 16;
		for (j = 0; j <= 91; j++)
		{
			B[j][i] = 0;
		}
	}
	c = 0;
	col = 0;
	row = 0;
	end = 0;

	//Find all solutions
	do
	{
		flag = 1;

		if ((row == 0) && (col == 8))
		{
			for (i = 0; i <= 7; i++)
			{
				B[c][i] = A[i];
			}
			c++;
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
			for (i = 0; i <= (col - 1); i++)
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
	for (k = 0; k <= 90; k++)
	{
		if (B[k][0] != 16)
		{
			for (i = 0; i <= 7; i++)
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
				for (m = 1; m <= 7; m++)
				{
					issame = 1;
					for (i = 0; i <= 7; i++)
					{
						if (B[l][i] != C[m][i])
						{
							issame = 0;
						}
					}
					if (issame == 1)
					{
						for (i = 0; i <= 7; i++)
						{
							B[l][i] = 16;
						}
					}
				}
			}
		}
	}

	//Print solution on stdout
	for (i = 0; i <= 91; i++)
	{
		if (B[i][0] != 16)
		{
			for (j = 0; j <= 7; j++)
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
