#include "monty.h"

/**
 * get_opcodes - Its selects  correct opcode to perform.
 * @opc: opcode passed.
 * Return: pointer to the function that executes the opcode.
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
               {"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"add", add},
		{"nop", nop},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opc) == 0)
			break;
	}
