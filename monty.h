#ifndef _MONTY_H_
#define _MONTY_H_

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

/** PROTOTYPES **/
void op_re_file(char **argv);
char **tokenizer(char *s, char *delim);
int count_words(char *str);
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void invalid_instrution(void);
void open_error(char **argv);
void malloc_error(void);
void error_argv(void);

void (*get_op_code(char *token, unsigned int line))(stack_t **, unsigned int);

/**
 *
 *
 *
 */

static const instruction_t list[] = {
	{"push", push},
	{"pall", pall},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{NULL, NULL}};

#endif /* _MONTY_H_ */
