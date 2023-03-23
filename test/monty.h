#ifndef MONTY_H
#define MONTY_H

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

void process_file(FILE *file, stack_node_t **stack);
void process_line(char *line, unsigned int line_number, stack_node_t **stack);
void execute_instruction(const char *opcode, const char *arg, unsigned int line_number, stack_node_t **stack);
int is_valid_number(const char *arg);
void push(stack_node_t **stack, int value);
void pall(stack_node_t *stack);
void free_stack(stack_node_t *stack);

#endif
