#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * add - adds the top two elements of the stack
 *
 * @stack: the stack to modiy
 *
 * @line_number: number of the line where opcode is
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !*stack || !(*stack)->next) /*checks if there are at least 2  elements*/
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	tmp = tmp->next; /*2nd value to add*/
	tmp->n += (*stack)->n; /*adds the values*/
	tmp->prev = NULL; /*deletes last value of stack*/
	free(*stack);
	*stack = tmp;
	(*stack)->next = tmp->next;/*allocates the stack new value*/
}
