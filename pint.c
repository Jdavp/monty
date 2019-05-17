#include "monty.h"
/**
 * pint - fn print last node that add
 * Return: 0 succesfull or EXIT_FAILURE failed
 */
int pint(void)
{
	if (e.nel > 0)
	{
		printf("%d\n", e.matrix[e.nel - 1]);
		return (0);
	}
	fprintf(stderr, "L%d: can't pint, stack empty\n", e.nline);
	return (EXIT_FAILURE);
}
