#include "interpreter.h"

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

void pall(stack_node_t *stack)
{
	stack_node_t *current = stack;
	
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

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
