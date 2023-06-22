#include "monty.h"
/**
 * pint - print the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @pline: line number
 * Return: no return
 */
void  pint(stack_t **doubly, unsigned int pline)
{
void pline();
    if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", pline);
		dprintf(2, "can't pint, stack empty\n");
		free_global();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}
