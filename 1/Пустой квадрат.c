/*Study in C / C ++
		and algorithms*/
#include <stdio.h>

int main(void)
{
	int colums = 1, row, count;

	printf("Enter the size of the square: ");
	scanf_s("%d", &count);

	while (colums <= count)
	{
		row = 1;
		while (row <= count)
		{
			if (colums == 1 || colums == count)
				printf("%s", "*");
			else
			{
				if (row == 1 || row == count)
					printf("%s", "*");
				else
					printf(" ");
			}
			row++;
		}
		printf("\n");
		colums++;
	}

	return 0;
}