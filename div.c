#include "monty.h"

/**
 *div -Divides 2nd value from the top of stack_t linkedlist by the top value.
 * @pline: Line number;
 * @doubly: Head of the linked list
 * Return: no return
 */

void div(stack_t **doubly, unsigned int pline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", pline);
		free_global();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", pline);
		free_global();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	pop(doubly, pline);
}
