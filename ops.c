#include "monty.h"

/**
 * push_func - pushes an element to the stack
 * @h: stack
 * @line_num: line number
 *
 * Return: void
 */

void push_func(stack_t **h, unsigned int line_num)
{
	stack_t *new = NULL;

	(void) line_num;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = global_var;
	new->prev = NULL;

	if (*h == NULL)
	{
		new->next = NULL;
		*h = new;
		return;
	}

	new->next = *h;
	(*h)->prev = new;
	*h = new;
}

/**
 * pall_func - prints all the values on the stack, starting from
 * the top of the stack
 * @h: stack
 * @line_num: line number
 *
 * Return: void
 */

void pall_func(stack_t **h, unsigned int line_num)
{
	stack_t *temp = NULL;

	(void) line_num;
	temp = *h;
	
	if ((*h) == NULL)
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
