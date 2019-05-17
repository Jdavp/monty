#include "monty.h"
/**
* mod - fn computes the rest of the division of the second top element of the stack.
* Return: 0 succesfull or EXIT_FAILURE failed
*/
int mod(void)
{
	int tmp;
        if (e.nel > 1)
        {
                tmp = e.matrix[e.nel - 1];
                if (tmp != 0)
                {
                        e.matrix[e.nel - 1] = '\0';
                        e.matrix[e.nel - 2] %= tmp;
                        e.nel -=1;
                        return (0);
                }
                fprintf(stderr, "L%d: division by zero\n", e.nline);
                return (EXIT_FAILURE);
        }
        fprintf(stderr, "L%d: can't mod, stack too short\n", e.nline);
        return (EXIT_FAILURE);
}
