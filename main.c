#include "main.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	process_file(argv[1]);
	return (EXIT_SUCCESS);
}

