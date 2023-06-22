#include "monty.h"

/**
 * push - adds a new node to the top of a stack
 * @stack: a double pounter to a stack_t structure
 * @line_number: unsigned integer
 * @argument: a character pointer
 */
void push(topnode_t **stack, unsigned int line_number, char *argument)
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
	new_node->prev = (*stack)->top;
	new_node->next = NULL;

	if ((*stack)->top != NULL)
		(*stack)->top->next = new_node;

	(*stack)->top = new_node;
	(*stack)->count++;
}


/**
 * pall - prints the values of all nodes in a stack
 * @stack: a double pounter to a stack_t structure
 */
void pall(topnode_t **stack)
{
	stack_t *current = (*stack)->top;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
