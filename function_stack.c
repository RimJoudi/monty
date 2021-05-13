#include "monty.h"
/**
 *push - pushes an element to the stack.
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command interpted
 *
 *Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *value;
	int i = 0, j = 0;

	value = malloc(sizeof(char));
	if (value == NULL)
		return;

	while (line[i] < '0' || line[i] > '9')
	{
		if (line[i] == '\0')
		{
			printf("L%u: usage: push integer\n", line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		if (line[i] == '-')
		{
			value[j] = line[i];
			j++;
		}
		i++;
	}
	while (line[i] != ' ' && line[i] != '\0'
	       && line[i] >= '0' && line[i] <= '9')
	{
		value[j] = line[i];
		i++;
		j++;
	}
	if (line[i] != ' ' && line[i] != '\0')
	{
		printf("L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	value[j] = '\0';
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(value);
	node->prev = NULL;
	if (*stack == NULL)
		node->next = NULL;
	else
	{
		node->next = *stack;
		(*stack)->prev = node;
	}
	*stack = node;
	free(value);
}

/**
 *pop -  removes the top element of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command interpted
 *
 *Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;
	free(tmp);
}

/**
 *swap - swaps the top two values of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command interpted
 *
 *Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;
	int count = 0;
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	if (count < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}