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
	printf("check_request >>currently is pass, is need update file errors\n");
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
			printf("cr is %d\n", e.cr);
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
                /*{"pop", pop},
                {"swap", swap},
                {"add", add},
                {"nop", nop},*/
                {NULL, NULL}
        };

	printf("fn is %s \n", e.command);
	while (lf[j].name != NULL && e.command != NULL)
	{
		if (strcmp(lf[j].name, e.command) == 0)
			return (lf[j].f);
		j++;
	}
	return (empty);
}

/**
* push - fn to add node at head
* Return: 0 succesfull or EXIT_FAILURE failed
*/
int push(void)
{
	int prev_value = atoi(e.value_n);
	
	e.len_value_n = strlen(e.value_n);
	if (INT_MAX >= prev_value && prev_value >= INT_MIN)
	{
		if ((prev_value == 0 && e.len_value_n == 1) || prev_value != 0)
		{
			e.matrix[e.nel] = prev_value;
			e.nel += 1;
			e.matrix[e.nel + 1] = '\0';
			return (0);
		}
	}
	return (EXIT_FAILURE);
}

/**
* pall - fn print all nodes of head
* Return: 0 succesfull or EXIT_FAILURE failed
*/
int pall(void)
{
	int j;
	
	if (e.order == 'q')
	{
		for (j = 0 ; j < e.nel; j++)
			printf("%d\n", e.matrix[j]);
	}
	else
	{
		for (j = e.nel - 1; j >= 0; j--)
			printf("%d\n", e.matrix[j]);
	}
	return (0);
}


/**
* pint - fn print last node that add
* Return: 0 succesfull or EXIT_FAILURE failed
*/
int pint(void)
{
	if (e.nel > 0)
	{
		printf("%d\n", e.matrix[e.nel - 1]);
		return (0);
	}
	fprintf(stderr, "L%d: can't pint, stack empty\n", e.nline);
	return (EXIT_FAILURE);
}
/**
* empty - fn print error when not find functios allow
* Return: EXIT_FAILURE
*/
int empty(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", e.nline, e.command);
	return (EXIT_FAILURE);
}
