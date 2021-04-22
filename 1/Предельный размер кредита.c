/*Study in C / C ++
        and algorithms*/
#include <stdio.h>

int main()
{

	int number = 0;
	float balance, globalSum, globalCred, limit, predel = 0;

	printf("Enter the account number (-1 if the entry is complete): ");
	scanf_s("%d", &number);

	while (number != -1)
	{
		printf("Enter your starting balance: ");
		scanf_s("%f", &balance);

		printf("Enter the total amount of expenses: ");
		scanf_s("%f", &globalSum);

		printf("Enter the total amount of credits: ");
		scanf_s("%f", &globalCred);

		printf("Enter your loan limit: ");
		scanf_s("%f", &limit);

		predel = balance + globalSum - globalCred;

		if (predel > limit)
		{
			printf("Score: %d\n", number);
			printf("Loan limit: %.2f\n", limit);
			printf("Balance: %.2f\n", balance);
			printf("The loan limit has been exceeded.\n");
		}

		printf("Enter the account number (-1 if the entry is complete):");
		scanf_s("%d", &number);
	}

	return 0;

}