#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    int n;

    /* Checking, allocation, empty and atleast 2 elements */
    if (!stack || !*stack || !(*stack)->next)
    {
        dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    tmp = *stack;
    n = tmp->n; /* Saving n value before swap */
    tmp->n = tmp->next->n;
    tmp->next->n = n; /* Swapping n values */
}