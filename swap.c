#include "monty.h"
/**
 * swap - fn swaps the top two elements of the stack
 * Return: 0 succesfull or EXIT_FAILURE failed
 */
int swap(void)
{
	int tmp;

	if (e.nel > 1)
	{
		tmp = e.matrix[e.nel - 1];
		e.matrix[e.nel - 1] = e.matrix[e.nel - 2];
		e.matrix[e.nel - 2] = tmp;
		return (0);
	}
	fprintf(stderr, "L%d: can't swap, stack too short\n", e.nline);
	return (EXIT_FAILURE);
}
