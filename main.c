#include "monty.h"
/**
 * main - initializes the program
 * @argc: number of arguments
 * @argv: array of arguments
 * Description: orginizes the program and calls the functions
 * Return: 0 on success
*/
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    size_t nread;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    instruction_t instruction;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((nread = getline(&line, &len, file)) != -1)
    {
        line_number++;
        instruction = get_instruction(line, line_number);
        instruction.f(&stack, line_number);
    }
    fclose(file);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}