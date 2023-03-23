#include "monty.h"

/**
 * process_file - Process a Monty bytecode file
 * @file: File pointer to the Monty bytecode file
 * @stack: Double pointer to the stack
 */

void process_file(FILE *file, stack_node_t **stack)
{
	char *line = NULL;
	size_t line_size = 0;
	unsigned int line_number = 0;
	ssize_t read;

	while ((read = getline(&line, &line_size, file)) != -1)
	{
		line_number++;
		process_line(line, line_number, stack);
	}

	free(line);
}
