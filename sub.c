#include "monty.h"
/**
* sub - fn subtracts the top element of the stack from the second top
* Return: 0 succesfull or EXIT_FAILURE failed
*/
int sub(void)
{
	int tmp;

	if (e.nel > 1)
	{
		tmp = e.matrix[e.nel - 1];
		if (tmp != 0)
		{
			e.matrix[e.nel - 1] = '\0';
			e.matrix[e.nel - 2] = e.matrix[e.nel - 2] - tmp;
			e.nel = e.nel - 1;
			return (0);
		}
	}
	fprintf(stderr, "L%d: can't sub, stack too short\n", e.nline);
	return (EXIT_FAILURE);
}
