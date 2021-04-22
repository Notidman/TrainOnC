/*Study in C / C ++
        and algorithms*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

long int factorial(int);
long int factorial_1(int);

int main()
{
    int n;
    long int res, res2;

    printf("Enter number: ");
    do
    {
        scanf_s("%d", &n);

        if (n < 0)
        {
            system("cls");
            printf("Incorrect number!");
            Sleep(1000);
            system("cls");
            printf("Enter number: ");
        }

    } while (n < 0);
    printf("\n");

    clock_t begin = clock();
    res = factorial(n);
    clock_t end = clock();
    printf("Factorial seconds:\n%10f\n\n", (double)(end - begin) / CLOCKS_PER_SEC);

    begin = clock();
    res2 = factorial_1(n);
    end = clock();
    printf("Factorial_1 seconds:\n%10f\n\n", (double)(end - begin) / CLOCKS_PER_SEC);

    printf("%s%15s\n", "factorial","factorial_1");
    printf("%5d%15d\n", res, res2);
    return 0;
}

long int factorial(int n)
{
    return (n < 2) ? 1 : n * factorial(n - 1);
}

long int factorial_1(int n)
{
    int i;
    for (i = 1; n > 1; i *= (n--));

    return i;
}