#include "monty.h"

/**
 * find_instruction - finds the corresponding instruction function
 * @opcode: opcode string
 * @stack: pointer to the stack
 * @line_number: current line number
 * @argument: instruction argument
 */
void find_instruction(char *opcode, stack_t **stack,
		      unsigned int line_number, char *argument)
{
	int j = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	(void) argument;
	while (instructions[j].opcode != NULL)
	{
		if (strcmp(opcode, instructions[j].opcode) == 0)
		{
			instructions[j].f(stack, line_number);
			return;
		}
		j++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * execute_instructions - executes a sequence of instructions on a file
 * @content: component of data_t structure
 */
void execute_instructions(data_t content)
{
	stack_t *stack = NULL;
	stack_t *temp;
	int i;

	char *line, *opcode, *argument;

	for (i = 0; i < content.count; i++)
	{
		line = content.lines[i];
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		argument = strtok(NULL, "\t\n");

		find_instruction(opcode, &stack, i + 1, argument);
	}

	while (stack != NULL)
	{
		temp = stack->prev;
		free(stack);
		stack = temp;
	}
}
