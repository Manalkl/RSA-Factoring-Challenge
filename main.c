#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "factor.h"

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
	FILE *fptr;
	char buffer[MAX_LINE_LENGTH];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		return (1);
	}

	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		return (1);
	}

	while (fgets(buffer, sizeof(buffer), fptr) != NULL)
	{
		size_t line_length = strlen(buffer);

		if (line_length > 0 && buffer[line_length - 1] == '\n')
			buffer[line_length - 1] = '\0';
		factorize(buffer);
	}

	fclose(fptr);

	return (0);
}
