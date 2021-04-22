/*Study in C / C ++
		and algorithms*/
#include <stdio.h>
#include <math.h>

int main(void)
{
	int digit = 0, num, sum = 0, i = 0; /*variable
                                            initialization */

	printf("Enter a binary number: "); 
	scanf_s("%d", &num); /*read binary
                                    number */

	while (num) /* Until the stack is zero*/
	{
		digit = num % 10; /* pop a number from the stack */
		num /= 10; /* decreasing the stack */ 
		sum += digit * pow(2, i); /* decimal conversion */
		i++;
	}


	printf("Result = %d", sum); /* result output */
    
	return 0;
}