#include "monty.h"

/**
 * pop - fn remove last node that add
 * Return: 0 succesfull or EXIT_FAILURE failed
 */
int pop(void)
{
	if (e.nel > 0)
	{
		e.matrix[e.nel - 1] = '\0';
		e.nel -=1;
		return (0);
	}
	fprintf(stderr, "L%d: can't pop an empty stack\n", e.nline);
	return (EXIT_FAILURE);
}
