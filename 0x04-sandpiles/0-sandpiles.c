#include "sandpiles.h"
/**
 * print_grid_per - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid_per(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * pop - pop a pile
 * @grid: sandpile
 * @i: position i
 * @j: position j
 * Return: None
 */
void pop(int grid[3][3], int i, int j)
{
	grid[i][j] -= 4;
	if (i + 1 < 3)
	{
		grid[i + 1][j] += 1;
	}
	if (i - 1 >= 0)
	{
		grid[i - 1][j] += 1;
	}
	if (j + 1 < 3)
	{
		grid[i][j + 1] += 1;
	}
	if (j - 1 >= 0)
	{
		grid[i][j - 1] += 1;
	}
}
/**
 * fill - fill two sandpiles
 * @grid1: sandpile 1
 * @grid2: sandpile 2
 * Return: None
 */
void fill(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
			{
				printf("=\n");
				print_grid_per(grid1);
				i = 4;
				break;
			}

	if (grid2[1][1] == 1)
		pop(grid1, 1, 1);


	if (grid2[1][0] == 1)
		pop(grid1, 1, 0);
	if (grid2[1][2] == 1)
		pop(grid1, 1, 2);
	if (grid2[0][1] == 1)
		pop(grid1, 0, 1);
	if (grid2[2][1] == 1)
		pop(grid1, 2, 1);


	if (grid2[0][0] == 1)
		pop(grid1, 0, 0);
	if (grid2[2][2] == 1)
		pop(grid1, 2, 2);
	if (grid2[0][2] == 1)
		pop(grid1, 0, 2);
	if (grid2[2][0] == 1)
		pop(grid1, 2, 0);


}
/**
 * sandpiles_sum - sum of two sandpiles
 * @grid1: sandpile 1
 * @grid2: sandpile 2
 * Return: None
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];


	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				grid2[i][j] = 1;
			else
				grid2[i][j] = 0;
		}

	fill(grid1, grid2);

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid2[i][j] = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				sandpiles_sum(grid1, grid2);
}
