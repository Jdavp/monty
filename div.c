#include "monty.h"

/**
* div2 - fn divides the second top element of the stack by the top element of the stack.
* Return: 0 succesfull or EXIT_FAILURE failed
*/
int div2(void)
{
        int tmp;
        if (e.nel > 1)
        {
                tmp = e.matrix[e.nel - 1];
        	if (tmp != 0)
		{
			e.matrix[e.nel - 1] = '\0';
                	e.matrix[e.nel - 2] /= tmp;
                	e.nel -=1;
                	return (0);
		}
        	fprintf(stderr, "L%d: division by zero\n", e.nline);
        	return (EXIT_FAILURE);
        }
        fprintf(stderr, "L%d: can't div, stack too short\n", e.nline);
        return (EXIT_FAILURE);
}
