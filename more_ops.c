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

/**
 * nop_func - does nothing
 * @stack: stack
 * @line_number: line_number
 *
 * Return: void
 */

void nop_func(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * sub_func - subtracts the top element of the stack from
 * the second top element of the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: void
 */

void sub_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int diff = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = temp->n - temp->next->n;
	temp->next->n = diff;

	pop_func(stack, line_number);
}

/**
 * div_func - divides the second top element of the stack by
 * the top element of the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: void
 */

void div_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int div = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = temp->n / temp->next->n;
	temp->next->n = div;

	pop_func(stack, line_number);
}

/**
 * mul_func - multiplies the second top element of the stack with
 * the top element of the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: void
 */

void mul_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int mul = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul = temp->n * temp->next->n;
	temp->next->n = mul;

	pop_func(stack, line_number);
}
