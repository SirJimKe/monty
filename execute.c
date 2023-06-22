#include "monty.h"

/**
 * execute_instructions - executes a sequence of instruction in file
 * @opcode: opcode
 * @line_number: line_number
 * @stack: stack
 */
void execute_instructions(char *opcode, unsigned int line_number,
			  stack_t **stack)
{
	int valid_opcode = 0;
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		/* Add more opcodes here */
		{NULL, NULL}};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			valid_opcode = 1;
			instructions[i].f(stack, line_number);
			break;
		}
	}

	if (!valid_opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number,
			opcode);
		exit(EXIT_FAILURE);
	}
}
