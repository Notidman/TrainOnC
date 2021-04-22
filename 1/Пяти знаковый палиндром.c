/*Study in C / C ++
		and algorithms*/
#include <stdio.h>

int main(void)
{
	int count, last, first, prefirst, prelast;

	printf("Enter a five-digit number: ");
	scanf_s("%d", &count);

	first = count / 10000;
	prefirst = (count / 1000) % 10;
	last = count % 10;
	prelast = (count % 100) / 10;

	if (first == last && prefirst == prelast)
		printf("%d - Palindrome", count);
	else
		printf("%d - Not palindrome", count);

	return 0;
}