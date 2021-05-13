#include "monty.h"
/**
 *add - adds the top two elements of the stack.
 *@stack: pointer to the top of the stack
 *@line_number: the line number intrepted
 *
 *Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sum;
	int count = 0;
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 *sub - subtracts the top element by the second top element of the stack.
 *@stack: pointer to the top of the stack
 *@line_number: the line number intrepted
 *
 *Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sub;
	int count = 0;
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = sub;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 *division - divides the second top element by the top element of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number intrepted
 *
 *Return: void
 */
void division(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int div;
	int count = 0;
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = div;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 *mul - multiplies the top two elements of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number intrepted
 *
 *Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int mul;
	int count = 0;
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = mul;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 *mod - the rest of the division of the second top element by the top elemnt
 *@stack: pointer to the top of the stack
 *@line_number: the line number intrepted
 *
 *Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int mod;
	int count = 0;
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = mod;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
