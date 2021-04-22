/*Study in C / C ++
		and algorithms*/
#include <stdio.h>

int main(void)
{
	float interest = 0, principal, rate, days;

	printf("Enter the principal amount of the loan (-1 if the entry is complete): ");
	scanf_s("%f", &principal);

	while (principal != -1)
	{
		printf("Enter the interest rate: ");
		scanf_s("%f", &rate);

		printf("Enter the loan term in days: ");
		scanf_s("%f", &days);

		interest = principal * rate * days / 365;
		printf("Simple interest payments are $%.2f\n", interest);

		printf("Enter the principal amount of the loan (-1 if the entry is complete): ");
		scanf_s("%f", &principal);
	}

	return 0;
}