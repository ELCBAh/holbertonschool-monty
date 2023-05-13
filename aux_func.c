#include "monty.h"

/**
 * opcomp - Matchs the opcode with a function
 * @stack: Pointer to the stack
 * @line_number: Line number of the monty file
 * @opcode: The command taked from the monty file
 * Return: void
 */
void opcomp(stack_t **stack, unsigned int line_number, char *opcode)
{
	int index = 0;

	instruction_t opc[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
	};

	while (opc[index].opcode != NULL)
	{
		if (strcmp(opcode, opc[index].opcode) == 0)
		{
			opc[index].f(stack, line_number);
			return;
		}
		index++;
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, opcode);
	exit_free(stack, file_opcode.opcode, file_opcode.file);
	exit(EXIT_FAILURE);
}

/**
 * exit_free - Frees all possible allocs before exiting the program
 * @stack: Pointer to the stack
 * @line: Line taked from the file
 * @file: Descriptor of the file to be closed
 * Return: void
 */
void exit_free(stack_t **stack, char *line, FILE *file)
{
	fclose(file);

	if (line != NULL)
		free(line);

	free_stack(*stack);
}

/**
 * free_stack - Free the stack
 * @stack: The stack to be free
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
 * is_number - Checks if the string contains an int.
 * @str: The string to be check.
 * Return: True if number, false if not
 */
bool is_number(const char *str)
{
	int i = 0;

	for (i = 0; str[i] ; i++)
	{
		if (isdigit(str[i]))
			return (true);
	}

	return (false);
}

