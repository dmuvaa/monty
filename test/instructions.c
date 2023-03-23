#include "monty.h"

/**
 * execute_instruction - Execute a Monty instruction
 * @opcode: Opcode to execute
 * @arg: Argument for the opcode
 * @line_number: Line number in the bytecode file
 * @stack: Double pointer to the stack
 */

void execute_instruction(const char *opcode, const char *arg, unsigned int line_number, stack_node_t **stack)
{
	int value;

	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL || !is_valid_number(arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		value = atoi(arg);
		push(stack, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(*stack);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_valid_number - Check if a string represents a valid integer
 * @arg: String to check
 *
 * Return: 1 if the string represents a valid integer, 0 otherwise
 */

int is_valid_number(const char *arg)
{
	if (arg == NULL)
	{
		return (0);
	}

	for (int i = 0; arg[i]; i++)
	{
		if (!isdigit(arg[i]))
		{
			return (0);
		}
	}

	return (1);
}
