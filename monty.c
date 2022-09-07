#include "monty.h"
#include <stdlib.h>

/**
 * main - Opens monty file and reads arguments
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0 (success)
 */

int main(int argc, char *argv[])
{
	FILE *fd;
	ssize_t num_bytes;
	size_t len = 0;
	char *line = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fd = fopen(argv[1], O_RDONLY);
		if (fd == NULL)
		{
			printf("Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			num_bytes = getline(&line, &len, fd);
		}
	}
}
