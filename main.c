#include "monty.h"

int pall(void);
int push(int value_n);
int search_fn(char *command, char *value_n);
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
			exit(98);

		buffer[SIZEBUFFER] = '\0';
		statusfd = getline(&buffer, &bufsize, fd);
		while (statusfd != EOF)
		{
			command = strtok(buffer, " \n");
			value_n = strtok(NULL, " \n");
			if (strcmp(command, "push") == 0)
				push(atoi(value_n));
			else if (strcmp(command, "pall") == 0)
				pall();
			statusfd = getline(&buffer, &bufsize, fd);
		}
		free(buffer);
		fclose (fd);
	}
	return (0);
}

int search_fn(char *command, char *value_n)
{
	if (strcmp(command, "push") == 0)
		push(atoi(value_n));
	else if (strcmp(command, "pall") == 0)
		pall();
	return (0);
}

int push(int value_n)
{
	int i = 0;

	while (matrix[i] != '\0')
	{
		i++;
	}
	matrix[i] = value_n;
	matrix[i+1] = '\0';
	return (0);

}
int pall(void)
{
	int i = 0;
	
	while (matrix[i] != '\0')
		i++;

	for (i = i - 1; i >= 0; i--)
		printf("%d\n", matrix[i]);
	return (0);
}
