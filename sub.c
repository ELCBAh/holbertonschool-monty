#include "monty.h"

/**
 * sub - initializes prototype
 *
 * @stack: the stack to modify
 *
 * @line_number: number of the line to find the opcode
 *
 * Description: subtracts the top element of the stack
 *
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	/* Checking stack, allocation, empty and enough elements */
	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	tmp = tmp->next; /* Saving stack and moving to next node */
	tmp->n -= (*stack)->n;
	tmp->prev = NULL; /* Substracting elements and removing previous node*/
	free(*stack);
	*stack = tmp;
	(*stack)->next = tmp->next;
}
