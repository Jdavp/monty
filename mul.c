#include "monty.h"
/**
* mul - fn multiplies the second top element of the stack with the top element.
* Return: 0 succesfull or EXIT_FAILURE failed
*/
int mul(void)
{
	int tmp;

	if (e.nel > 1)
	{
		tmp = e.matrix[e.nel - 1];
		e.matrix[e.nel - 1] = '\0';
		e.matrix[e.nel - 2] = e.matrix[e.nel - 2] * tmp;
		e.nel = e.nel - 1;
		return (0);
}
fprintf(stderr, "L%d: can't mul, stack too short,\n", e.nline);
return (EXIT_FAILURE);
}
