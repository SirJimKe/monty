#include "monty.h"

/**
 * open_file - opens a file
 * @filename: monty file as input
 * Return: FILE pointer to the opened file
 */
FILE *open_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * read_file - read contents of a file
 * @filename: monty file as input
 * Return: data_t structure containing file lines
 */
data_t read_file(const char *filename)
{
	FILE *file = open_file(filename);
	data_t content;
	char line[MAX_LINE_LENGTH];
	int length;

	content.lines = malloc(sizeof(char *) * MAX_LINE_LENGTH);
	if (content.lines == NULL)
	{
		fclose(file);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	content.count = 0;
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		length = strlen(line);
		if (line[length - 1] == '\n')
			line[length - 1] = '\0';

		content.lines[content.count] = malloc(sizeof(char)
						      * (length + 1));
		if (content.lines[content.count] == NULL)
		{
			fclose(file);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		strcpy(content.lines[content.count], line);
		content.count++;
	}

	printf("FIle opened and read successfully!\n");
	fclose(file);
	return (content);
}

/**
 * free_data_t - frees memory allocated for data_t structure
 * @content: data_t content
 */
void free_data_t(data_t content)
{
	int i;

	for (i = 0; i < content.count; i++)
		free(content.lines[i]);
	free(content.lines);
}
