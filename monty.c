#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Main function to interpretates Monty ByteCodes files
 * @argc: the number of the arguments passed to the program
 * @argv: the Monty program name, and the name of the file to be read
 * Return: nothing
*/

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	int line_number = 1;

	/* Check arguments */
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open file */
	file_opcode.file = fopen(argv[1], "r");
	if (file_opcode.file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Read file line by line and call the functions */
	while (getline(&line, &len, file_opcode.file) != -1)
	{
		line_number++;
		file_opcode.opcode = strtok(line, " \n\t$");
		if (file_opcode.opcode == NULL)
			continue;
		opcomp(&stack, line_number, file_opcode.opcode);
		len = 0;
		free(line);
	}
	/* Free memory and close file */
	exit_free(&stack, line, file_opcode.file);
	exit(EXIT_SUCCESS);
}
