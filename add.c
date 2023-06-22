#include "monty.h"

/**
 * add - Adds the top two values of a stack_t linked list.
 * @pline: line number
 * Description: The result is stored in the second value node
 * @doubly: head of the linked list
 * from top and the top value  is removed.
 */
void  add(stack_t **doubly, unsigned int pline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", pline);
		free_global();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	pop(doubly, pline);
}
