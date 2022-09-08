#include "monty.h"

/**
 * add_func - adds the top two elements of the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: void
 */

void add_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int sum = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = temp->n + temp->next->n;
	temp->next->n = sum;

	pop_func(stack, line_number);
}
