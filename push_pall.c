#include "monty.h"

/**
 * push - adds a new node to the top of a stack
 * @stack: a double pounter to a stack_t structure
 * @line_number: unsigned integer
 * @argument: a character pointer
 */
void push(stack_t **stack, unsigned int line_number, char *argument)
{
	int value = atoi(argument);
	stack_t *new_node = malloc(sizeof(stack_t));

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (value == 0 && strcmp(argument, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}


/**
 * pall - prints the values of all nodes in a stack
 * @stack: a double pounter to a stack_t structure
 * @line_number: unsigned integer
 * @argument: a character pointer
 */
void pall(stack_t **stack, unsigned int line_number, char *argument)
{
	stack_t *current = *stack;

	(void)line_number;
	(void)argument;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
