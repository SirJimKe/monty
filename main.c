#include "monty.h"

/**
 * main - interprets Monthy ByteCode files
 * @argc: argument counter
 * @argv: argment vector
 * Return: 0 or 1
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/**
	 * Call functions to read file content
	 * Call functions to execute instructions
	 */

	return (EXIT_SUCCESS);
}
