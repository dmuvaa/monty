#include "monty.h"

/**
 * process_line - Process a line from the Monty bytecode file
 * @line: Line to process
 * @line_number: Line number in the bytecode file
 * @stack: Double pointer to the stack
 */

void process_line(char *line, unsigned int line_number, stack_node_t **stack)
{
	char *opcode;
	char *arg;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
	{
		return;
	}

	arg = strtok(NULL, " \t\n");

	execute_instruction(opcode, arg, line_number, stack);
}
