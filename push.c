#include "monty.h"

/**
 * push - fn to add node at head
 * Return: 0 succesfull or EXIT_FAILURE failed
 */
int push(void)
{
	int prev_value = atoi(e.value_n);

	e.len_value_n = strlen(e.value_n);
	if (prev_value <= INT_MAX && prev_value >= INT_MIN)
	{
		if ((prev_value == 0 && e.len_value_n == 1) || prev_value != 0)
		{
			e.matrix[e.nel] = prev_value;
			e.nel += 1;
			e.matrix[e.nel + 1] = '\0';
			return (0);
		}
	}
	fprintf(stderr, "L%d: usage: push integer\n", e.nline);
	return (EXIT_FAILURE);
}
