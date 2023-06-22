#include "monty.h"

/**
 * main - interprets Monthy ByteCode files
 * @argc: argument counter
 * @argv: argment vector
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	process_file(argv[1]);

	return (EXIT_SUCCESS);
}
