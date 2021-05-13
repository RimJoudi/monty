#include "monty.h"
/**
*get_func - compares opcodes and runs associated functions
*@stack: pointer to the top of the stack
*@line_number: line number of command
*@opcode: the opcode
*Return: void
*/
void get_func(stack_t **stack, unsigned int line_number, char *opcode)
{
	int i = 0;

	instruction_t func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", division},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	while (func[i].opcode != NULL)
	{
		if (strcmp(opcode, func[i].opcode) == 0)
		{
			func[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr,"L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
