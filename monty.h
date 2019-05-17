#ifndef _MONTY_H
#define _MONTY_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
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

/**
 *struct st - stored functions
 *@name: name of the function
 *@f: function
 *
 */
typedef struct st
{
	char *name;
	int (*f)();
} st_t;

/**
 *struct s_error - stores all the main variables of the program
 *@buffer: space to store the input from the file
 *@step: indentifies the place in the program
 *@filename: name of the file
 *@fd: file descriptor
 *@argc: number of arguments
 *@command: order given in the document
 *@value_n: value number to add
 *@len_value_n: length of the value
 *@nline: line number
 *@matrix: scale vector
 *@order: valuets if is stack or queue
 *@nel: number of nodes
 *@cr: store last instance
 */
typedef struct s_error
{
	char *buffer;
	char *step;
	char *filename;
	FILE *fd;
	int argc;
	char *command;
	char *value_n;
	int len_value_n;
	int nline;
	int matrix[1024];
	char order;
	int nel;
	int cr;
} s_errors;
s_errors e;
int check_request(void);
int __quit(void);
int pint(void);
int empty(void);
int pall(void);
int push(void);
int pop(void);
int swap(void);
int add(void);
int nop(void);
int sub(void);
int div2(void);
int mul(void);
int mod(void);
int (*search_fn(void))();
#endif /* _MONTY_H */
