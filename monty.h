#ifndef _MONTY_H
#define _MONTY_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SIZEBUFFER 1024
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct st
{
	char *name;
	int (*f)();
} st_t;

typedef struct s_error
{
	char *step;
	char *filename;
	FILE *fd;
	int argc;
	char *command;
	char *value_n; 
	int nline;
	int matrix[1024];
	char order; /* s = stack, q = queue */
	int nel; /* number of nodes */
	int cr; /* get last instance */
} s_errors;
s_errors e;
int empty(void);
int pall(void);
int push(void);
int (*search_fn(void))();
#endif /* _MONTY_H */
