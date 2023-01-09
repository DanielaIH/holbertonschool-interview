#include "sandpiles.h"

/**
 * is_stable - Check if the sandpile is stable
 * @grid1: Sandpile to check
 * Return: 0 if the sandpile is stable, 1 if not.
 */
bool is_stable(int grid1[3][3])
{
	bool unstable = true;
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (unstable);
		}
	}
	unstable = false;
	return (unstable);
}

/**
 * _print_grid - print the grid
 * @grid: grid
 * Return: Nothing
 */
void _print_grid(int grid[3][3])
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
 * stabilize - stabilize the sandpile
 * @grid1: The grid to stabilize.
 * Return: Nothing
 */
void stabilize(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i > 0)
					grid1[i - 1][j]++;
				if (i < 2)
					grid1[i + 1][j]++;
				if (j > 0)
					grid1[i][j - 1]++;
				if (j < 2)
					grid1[i][j + 1]++;
			}
		}
	_print_grid(grid1);
	}
}
/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: First grid
 * @grid2: Second grid
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (is_stable(grid1))
	{
		printf("=\n");
		_print_grid(grid1);
		stabilize(grid1);
	}
}
