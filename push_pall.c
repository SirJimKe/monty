#include "monty.h"

/**
 * push - pushes an element ontop of stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value_str = strtok(NULL, " \n");
	int value;
	size_t i;
	stack_t *new_node;

	if (!value_str)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; value_str[i] != '\0'; i++)
	{
		if (value_str[i] == '-' && i == 0)
			continue;
		if (value_str[i] < '0' || value_str[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n",
				line_number);
			exit(EXIT_FAILURE);
		}
	}

	value = atoi(value_str);
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - prints all values on the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void) line_number;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
