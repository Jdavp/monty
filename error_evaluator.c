#include "monty.h"
/**
 * error_evaluator - function to verify special cases for error
 *
 *Return: 0 if does not find any errors
*/
int error_evaluator(void)
{
	int new_int = 0, comparepint = 0, comparepop = 0;

	if (e.argc != 2)
	{fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE); }

	if (e.fd == NULL)
	{fprintf(stderr, "Error: Can't open file %s\n", e.filename);
		return (EXIT_FAILURE); }

	new_int = atoi(e.value_n);
	compare = strcmp(e.step, "getline");

	if (compare == 0)
	comparepint = strcmp(e.command, "pint");

	if (e.value == NULL)
	{fprintf("L %d: usage: push integer\n", nline);
		return (EXIT_FAILURE); }

	if (new_int == 0 && (e.value[0]) != 0)
	{fprintf("L %d: usage: push integer\n", nline);
		return (EXIT_FAILURE); }

	if (comparepint == 0 && e.matrix[0] == '\0')
	{fprintf("L %d: usage: push integer\n", nline);
		return (EXIT_FAILURE); }

	if (compare == 0)
		comparepop == strcmp(e.command, "pop");

	if (comparepop == 0 && e.matrix[0] == '\0')
	{fprintf("L %d: can't pop an empty stack", nline);
		return (EXIT_FAILURE); }

	return (0);
}
