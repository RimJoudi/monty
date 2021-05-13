
#include "monty.h"
/**
 *pchar - prints the char at the top of the stack
 *@stack: the pointer to the top of the stack
 *@line_number: the line number
 *
 *Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack  == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
