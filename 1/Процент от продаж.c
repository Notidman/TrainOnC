/*Study in C / C ++
        and algorithms*/
#include <stdio.h>

int main(void)
{
	float sum, result = 0;

	printf("Enter the amount of sales in dollars (-1 if the entry is complete): ");
	scanf_s("%f", &sum);

	while (sum != -1)
	{
		result = 200 + ((9 * sum) / 100);
		printf("Salary: $%.2f\n", result);

		printf("Enter the amount of sales in dollars (-1 if the entry is complete): ");
		scanf_s("%f", &sum);
	}

	return 0;
}