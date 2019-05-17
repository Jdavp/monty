#include "monty.h"
int check_request();
int check_request()
{
	printf("check_request >>currently is pass, is need update file errors\n");
	return (1);
}

/**
* main - entry fn
* @argc: int count argv
* @argv: char with args
* Return: 1 success, 2 error
*/
int main(int argc, char *argv[])
{
	int  i = 0;
	size_t bufsize = SIZEBUFFER;
	ssize_t statusfd;
	char *buffer;

	e.step = "args";
	e.argc = argc;
	e.cr = check_request();
	e.order = 's';
	if (e.cr == 1)
	{
		e.filename = argv[1];
		e.fd = fopen(e.filename, "r");
		e.step = "file";
		e.nline = 0;
		e.cr = check_request();
		if (e.cr != 1)
			exit(e.cr);

		buffer = malloc(sizeof(char) * SIZEBUFFER + 1);
		if (!buffer)
			exit(2);
		e.nel = 0;
		e.matrix[0] = '\0';
		buffer[SIZEBUFFER] = '\0';
		statusfd = getline(&buffer, &bufsize, e.fd);
		while (statusfd != EOF)
		{
			i++;
			e.command = strtok(buffer, " \n");
			e.step = "getline";
			e.value_n = strtok(NULL, " \n");
			e.nline = i;
			e.cr = check_request();
			if (e.cr != 1)
				exit(e.cr);
			e.cr = (*search_fn())();
			if (e.cr != 1)
				exit(e.cr);
			statusfd = getline(&buffer, &bufsize, e.fd);
		}
		free(buffer);
		fclose(e.fd);
	}
	else
		exit(e.cr);
	return (1);
}

/**
* search_fn - search function
* Return: 1 success, 2 error
*/
int (*search_fn(void))()
{
	int j = 0, ef = 0;
	st_t lf[] = {
                {"push", push},
                {"pall", pall},
                /*{"pint", pint},
                {"pop", pop},
                {"swap", swap},
                {"add", add},
                {"nop", nop},*/
                {NULL, NULL}
        };

	printf("fn is %s \n", e.command);
	while (lf[j].name != NULL)
	{
		if (strcmp(lf[j].name, e.command) == 0)
			return (lf[j].f);
		j++;
	}
	return (empty);
}

/**
* push - fn to add node at head
* Return: 1 success, 2 error
*/
int push(void)
{
	e.matrix[e.nel] = atoi(e.value_n);
	e.nel += 1;
	e.matrix[e.nel + 1] = '\0';
	return (1);

}

/**
* pall - fn print all nodes of head
* Return: 1 success, 2 error
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
	return (1);
}

/**
* empty - fn print error when not find functios allow
* Return: EXIT_FAILURE
*/
int empty(void)
{
	fprintf(e.fd, "L%d: unknown instruction %s", e.nline, e.command);
	return (EXIT_FAILURE);
}
