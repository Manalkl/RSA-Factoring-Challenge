#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "factor.h"

int factorize(char *buffer)
{
	uint32_t num;
	uint32_t i;

	num = atoi(buffer);

	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			printf("%d=%d*%d\n", num, num / i, i);
			break;
		}
	}

	return (0);
}
