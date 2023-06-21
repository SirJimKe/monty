#include "monty.h"

/**
 * main - interprets Monthy ByteCode files
 * @argc: argument counter
 * @argv: argment vector
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	const char *filename = argv[1];
	data_t content;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/**
	 * Call functions to read file content
	 * Call functions to execute instructions
	 */
	content = read_file(filename);
	free_data_t(content);


	return (EXIT_SUCCESS);
}
