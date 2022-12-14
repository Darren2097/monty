#define _GNU_SOURCE
#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: stack to be freed
 *
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *temp = NULL;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

/**
 * check_int - Checks if input is a number
 * @str: input to check
 *
 * Return: 1 if it is number, 0 if it is not
 */

int check_int(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= '0' && *(str + i) <= '9')
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
 * @line_number: line number
 *
 * Return: integer value
 */

char *tokens(char *line, unsigned int line_number)
{
	char delim[2] = "\n ";
	char *str = NULL;
	char *token = NULL;

	token = strtok(line, delim);
	if (token == NULL)
		return (NULL);
	str = strtok(NULL, delim);
	if (str != NULL)
	{
		if (check_int(str))
			global_var = atoi(str);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else if (str == NULL && strcmp(token, "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (token);
}


/**
 * func_type - Searches the opcode in struct and checks if it matches with
 * user input
 * @op: opcode to check
 * @stack: stack
 * @line_number: line number
 *
 * Return: Pointer to function or NULL if it fails
 */

void func_type(char *op, stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{NULL, NULL}
	};

	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, op) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
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
	char *line = NULL;
	char *token = NULL;
	unsigned int line_num = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fd = fopen(argv[1], "r");
		if (fd == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			while ((num_bytes = getline(&line, &len, fd)) != -1)
			{
				line_num++;
				token = tokens(line, line_num);
				if (token != NULL)
					func_type(token, &head, line_num);
			}
			free(line);
			free_stack(head);
			fclose(fd);
		}
	}
	return (0);
}
