/*Study in C / C ++
		and algorithms*/
#include <stdio.h>
#include <math.h>

int main(void)
{
	int num, decimal = 0, i = 0;

	printf("Enter integer number: ");
	scanf_s("%d", &num);

	while (num)
	{
		decimal = num % 10;
		num /= 10;
		if (decimal == 7)
			i++;
	}

	printf("Number of sevens: %d", i);

	return 0;
}