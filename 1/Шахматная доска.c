/*Study in C / C ++
		and algorithms*/
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i = 8;
	while (i)
	{
		int j = 10;
		while (j)
		{
			if (i % 2 == 0)
				printf("* ");
			if (i % 2 != 0)
				printf(" *");
			--j;
		}
		--i;
		printf("\n");
	}
	
	return 0;
}