#include "monty.h"
/**
* __quit - free allocs and file descriptor and exit
* Return 0 is successfull and 1 is EXIT_FAILURE
*/
int __quit(void)
{
	if (e.buffer != NULL)
		free(e.buffer);
	if (e.fd != NULL)
		fclose(e.fd);
	if (e.cr != 0)
		exit(e.cr);
	return (0);
}
/**
* check_request - validate common errors
* Return 0 is successfull and 1 is EXIT_FAILURE
*/
int check_request(void)
{
	if (strcmp(e.step, "args") == 0 && e.argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (strcmp(e.step, "file") == 0 && e.fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", e.filename);
		return (EXIT_FAILURE);
	}
	return (0);
}
/**
* main - entry fn
* @argc: int count argv
* @argv: char with args
* Return: 0 succesfull or EXIT_FAILURE failed
*/
int main(int argc, char *argv[])
{
	int  i = 0;
	size_t bufsize = SIZEBUFFER;
	ssize_t statusfd;

	e.step = "args";
	e.argc = argc;
	e.cr = check_request();
	e.order = 's';
	if (e.cr == 0)
	{
		e.filename = argv[1];
		e.fd = fopen(e.filename, "r");
		e.step = "file";
		e.nline = 0;
		e.cr = check_request();
		if (e.cr != 0)
			__quit();
		e.buffer = malloc(sizeof(char) * SIZEBUFFER + 1);
		if (!e.buffer)
			__quit();
		e.nel = 0;
		e.matrix[0] = '\0';
		e.buffer[SIZEBUFFER] = '\0';
		statusfd = getline(&e.buffer, &bufsize, e.fd);
		while (statusfd != EOF)
		{
			i++;
			e.command = strtok(e.buffer, " \n");
			e.step = "getline";
			e.value_n = strtok(NULL, " \n");
			e.nline = i;
			e.cr = check_request();
			if (e.cr != 0)
				__quit();
			e.cr = (*search_fn())();
			if (e.cr != 0)
				__quit();
			statusfd = getline(&e.buffer, &bufsize, e.fd);
		}
		__quit();
	}
	else
		__quit();
	return (0);
}
/**
* search_fn - search function
* Return: 0 succesfull or EXIT_FAILURE failed
*/
int (*search_fn(void))()
{
	int j = 0;
	st_t lf[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sup", sup},
		{"div", div2},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};

	while (lf[j].name != NULL && e.command != NULL)
	{
		if (strcmp(lf[j].name, e.command) == 0)
			return (lf[j].f);
		j++;
	}
	return (empty);
}
