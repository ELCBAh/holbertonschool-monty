#include "monty.h"
/**
 * pop - removes the top element of the stack
 * 
 * @stack: the stack to modify
 * 
 * @line_number: number of line where the opcode is
 * 
 * Description: removes the top element of the stack
*/
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    /* Checking if top element of the stack is empty or NULL (checking allocation and content) */
    if (!stack || !*stack)
    {
        dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    tmp = *stack; /* Holding top element of the stack */
    *stack = (*stack)->next;
    free(tmp);
    if (*stack)
        (*stack)->prev = NULL;
}