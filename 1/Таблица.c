/*Study in C / C ++
		and algorithms*/
#include <stdio.h>

int main(void)
{
	int N = 1;

	printf("N\t10*N\t100*N\t1000*N\n");

	while (N <= 10)
	{
		printf("%d\t%d\t%d\t%d\n", N, 10*N, 100*N, 1000*N);
		N++;
	}

	return 0;
}