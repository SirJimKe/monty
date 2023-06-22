#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * struct data_s - lines and count
 * @lines: an array of strings (lines of text)
 * @count:  number of lines present in the lines array
 *
 * Description: stores the content of a file
 */
typedef struct data_s
{
	char **lines;
	int count;
} data_t;

/** functions in data.c file */
void free_data(data_t content);
data_t read_file(const char *filename);

/** function in execute.c file */
void find_instruction(char *opcode, stack_t **stack,
		      unsigned int line_number, char *argument);
void execute_instructions(data_t content);

/** function in push_pall.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif
