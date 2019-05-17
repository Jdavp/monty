#include "monty.h"

/**
 * pall - fn print all nodes of head
 * Return: 0 succesfull or EXIT_FAILURE failed
 */
int pall(void)
{
	int j;

	if (e.order == 'q')
	{
		for (j = 0 ; j < e.nel; j++)
			printf("%d\n", e.matrix[j]);
	}
	else
	{
		for (j = e.nel - 1; j >= 0; j--)
			printf("%d\n", e.matrix[j]);
	}
	return (0);
}
