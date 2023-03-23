#include "monty.h"

/**
 * push - Push a value onto the stack
 * @stack: Double pointer to the stack
 * @value: Value to push onto the stack
 */

void push(stack_node_t **stack, int value)
{
	stack_node_t *new_node = malloc(sizeof(stack_node_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
       	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * pall - Print all values on the stack
 * @stack: Pointer to the stack
 */

void pall(stack_node_t *stack)
{
	stack_node_t *current = stack;
	
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

/**
 * free_stack - Free the memory allocated for the stack
 * @stack: Pointer to the stack
 */

void free_stack(stack_node_t *stack)
{
	stack_node_t *temp;
	
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
