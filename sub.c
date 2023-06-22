#include "monty.h"
/**
* sub - Subtracts 2nd value from  top of stack_t linked list by top value.
* @pline: Line number.
 * @head: Head node.
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */

void  sub(stack_t **head, unsigned int pline)
{
	int m = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", pline);
		free_global();
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n -= (*head)->n;
	pop(head, pline);
}
