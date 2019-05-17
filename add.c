#include <monty.h>

/**
 * add - fn adds the top two elements of the stack
 * Return: 0 succesfull or EXIT_FAILURE failed
 */
int add(void)
{
	int tmp;
	if (e.nel > 1)
	{
		tmp = e.matrix[e.nel - 1];
		e.matrix[e.nel - 1] = '\0';
		e.matrix[e.nel - 2] += tmp;
		e.nel -=1;
		return (0);
	}
	fprintf(stderr, "L%d: can't add, stack too short\n", e.nline);
	return (EXIT_FAILURE);
}
