#include "monty.h"
/**
 * get_instruction - initializes prototype
 * @line: line to be read
 * @line_number: line number
 * Description: function that reads the line and executes the instruction
 * Return: instruction
*/
instruction_t get_instruction(char *line, unsigned int line_number)
{
    instruction_t instruction = {NULL, NULL};
    char *opcode = strtok(line, " \t\n");
    if (opcode && opcode[0] != '#')
    {
        if (strcmp(opcode, "push") == 0)
        {
            instruction.opcode = "push";
            instruction.f = push;
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            instruction.opcode = "pall";
            instruction.f = pall;
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }
    return (instruction);
}