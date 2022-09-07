#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

/**
 * check_int - Checks if input is a number
 * @str: input to check
 *
 * Return: 1 if it is number, 0 if it is not
 */

int check_int(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;
	while (*(str + i) != '\0')
	{
		if ((*(str + i) >= '0') && (*(str + i) <= '9'))
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

/**
 * tokens - tokenize the line
 * @line: line from file
 * @line_num: line number
 *
 * Return: integer value
 */

char *tokens(char *line, unsigned int line_num)
{
	char *str = NULL, *token = NULL;

	token = strtok(line, "\n ");
	if (token == NULL)
		return (NULL);
	str = strtok(NULL, "\n ");
	if (str != NULL)
	{
		if (check_int(str) == 1)
			global_var = atoi(str);
		else
		{
			printf("L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	else if (str == NULL && strcmp(token, "push") == 0)
	{
		printf("L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	return (token);
}


/**
 * func_type - Searches the opcode in struct and checks if it matches with
 * user input
 * @op: opcode to check
 * @h: stack
 * @line_num: line number
 *
 * Return: Pointer to function or NULL if it fails
 */

void func_type(char *op, stack_t **h, unsigned int line_num)
{
	int i;

	instruction_t ops[] = {
		{"push", push_func},
		{"pall", pall_func},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, op) == 0)
		{
			ops[i].f(h, line_num);
			return;
		}
	}
	printf("L%d: unknown instruction %s\n", line_num, op);
	exit(EXIT_FAILURE);
}

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
	char *line = NULL, *token = NULL;
	int line_num = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fd = fopen(argv[1], "r");
		if (fd == NULL)
		{
			printf("Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			num_bytes = getline(&line, &len, fd);
			while (num_bytes != -1)
			{
				line_num++;
				token = tokens(line, line_num);
				if (token != NULL)
					func_type(token, &head, line_num);
			}
			fclose(fd);
		}
	}
	return (0);
}
