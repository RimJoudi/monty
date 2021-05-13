#include "monty.h"
/**
 *free_stack - frees the stack
 *@stack: the head of the stack
 *
 *Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	tmp = stack->next;
	while (tmp != NULL)
	{
		free(stack);
		stack = tmp;
		tmp = tmp->next;
	}
	free(stack);
}
