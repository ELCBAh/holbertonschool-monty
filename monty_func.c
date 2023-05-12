#include "monty.h"

/**
 * push - Pushes a new node to the stack
 * @stack: Pointer to the head of the stack
 * @line_number: The current line number in the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *tok = strtok(NULL, " \t\n");
	stack_t *new_node = NULL;
	int n = 0;

	if (!tok || !is_number(tok) || *tok == '-')
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit_free(stack, file_opcode.opcode, file_opcode.file);
		exit(EXIT_FAILURE);
	}

	n = atoi(tok);

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit_free(stack, file_opcode.opcode, file_opcode.file);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (!*stack)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pall - Prints all the values of the stack
 * @stack: Pointer to the the stack
 * @line_number: The current line number in the Monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the the stack
 * @line_number: The current line number in the Monty file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit_free(stack, file_opcode.opcode, file_opcode.file);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
