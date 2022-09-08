#include "monty.h"

/**
 * push_func - pushes an element to the stack
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */

void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	(void) line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = global_var;
	new->prev = NULL;

	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
		return;
	}

	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

/**
 * pall_func - prints all the values on the stack, starting from
 * the top of the stack
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */

void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	(void) line_number;
	temp = *stack;

	if ((*stack) == NULL)
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint_func - prints the value at the top of the stack,
 * followed by a new line
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */

void pint_func(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	printf("%d\n", top->n);
}

/**
 * pop_func - removes the top element of the stack
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */

void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;

	if (*stack == NULL || stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}
