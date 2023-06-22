#include "monty.h"
/**
 * mul -Multiplies 2nd value from the top of stack_t linked list by top value.
 * @pline: Line number
 * @head: Head node
 * info:The result is stored in the 2nd value node
 * from the top and top value removed.
 */

void  mul(stack_t **head, unsigned int pline)
{
	int m = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", pline);
		free_global();
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n *= (*head)->n;
	pop(head, pline);
}
