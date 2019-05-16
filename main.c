#include "monty.h"

/**
* main - entry fn
* @argc: int count argv
* @argv: char with args
* Return: 1 success, 2 error
*/
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t bufsize = SIZEBUFFER;
	ssize_t statusfd;
	char *filename;
	char *buffer;
	char *command;
	char *value_n;

	if (argc == 2)
	{
		filename = argv[1];
		fd = fopen(filename, "r");
		if (fd == NULL)
		{
			perror("Error: Can't open file ");
			perror(filename);
			perror("\n");
			exit(EXIT_FAILURE);
		}

		buffer = malloc(sizeof(char) * SIZEBUFFER + 1);
		if (!buffer)
			exit(2);
		matrix[0] = '\0';
		buffer[SIZEBUFFER] = '\0';
		statusfd = getline(&buffer, &bufsize, fd);
		while (statusfd != EOF)
		{
			command = strtok(buffer, " \n");
			value_n = strtok(NULL, " \n");
			search_fn(command, value_n);
			statusfd = getline(&buffer, &bufsize, fd);
		}
		free(buffer);
		fclose(fd);
	}
	return (1);
}

/**
* search_fn - search function
* @command: arg to search fn
* @value_n: add value n
* Return: 1 success, 2 error
*/
int search_fn(char *command, char *value_n)
{
	if (strcmp(command, "push") == 0)
		return (push(atoi(value_n)));
	else if (strcmp(command, "pall") == 0)
		return (pall());
	return (1);
}

/**
* push - fn to add node at head
* @value_n: add value n
* Return: 1 success, 2 error
*/
int push(int value_n)
{
	int i = 0;

	while (matrix[i] != '\0')
		i++;
	matrix[i] = value_n;
	i++;
	matrix[i] = '\0';
	return (1);

}

/**
* pall - fn print all nodes of head
* Return: 1 success, 2 error
*/
int pall(void)
{
	int i = 0;

	while (matrix[i] != '\0')
		i++;

	for (i = i - 1; i >= -1; i--)
		printf("%d\n", matrix[i]);
	return (1);
}
