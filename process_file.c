#include "monty.h"


/**
 * process_file - read contents of a file
 * @filename: monty file as input
 * Return: data_t structure containing file lines
 */
void process_file(const char *filename)
{
	FILE *file;
	char line[256];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		opcode = strtok(line, " \n");

		if (opcode && opcode[0] != '#')
		{
			execute_instructions(opcode, line_number, &stack);
		}
	}

	fclose(file);
	free_stack(stack);
}

/**
 * free_stack - frees memory allocated for a structure
 * @stack: content
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
