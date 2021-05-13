#include "monty.h"
/**
 *get_opcode - get the opcode of a Monty file
 *
 *Return: pointer to a string containing the opcode
 */
char *get_opcode(void)
{
	int i = 0, j = 0;
	char *buffer;
	size_t len = 20;

	buffer = malloc(sizeof(char) * len);
	if (buffer == NULL)
		return (NULL);

	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i] != '\0')
	{
		buffer[j] = line[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	return (buffer);
}
