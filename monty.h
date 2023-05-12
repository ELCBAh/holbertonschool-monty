#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct GlobalVariables - The global variables to be free
 * @file: Descriptor of the Monty file
 * @opcode: The command to take from the Monty file
 */
struct GlobalVariables
{
	FILE *file;
	char *opcode;
} file_opcode;


/* Monty functions prototypes*/
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);

/* Auxiliar functions prototypes*/
void opcomp(stack_t **stack, unsigned int line_number, char *opcode);
bool is_number(const char *str);
void exit_free(stack_t **stack, char *line, FILE *file);
void free_stack(stack_t *stack);

#endif
