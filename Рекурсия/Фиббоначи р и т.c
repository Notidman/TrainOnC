/*Study in C / C ++
        and algorithms*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

unsigned int Fib(unsigned int);
unsigned int FibR(unsigned int);

int main()
{
    unsigned int n;

    do
    {
        printf("Enter number: ");
        scanf_s("%d", &n);

        if (n < 1 || n > 40)
        {
            system("cls");
            printf("Incorrect number!");
            Sleep(1000);
            system("cls");
        }

    } while (n < 1 || n > 40);

    printf("\n%21s", "Fibonacci: ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", Fib(i));
        if (i == 24)
            printf("\n");
    }

    printf("\n%21s", "Recursive fibonacci: ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", FibR(i));
        if (i == 24)
            printf("\n");
    }
    printf("\n");

    return 0;
}

unsigned int Fib(unsigned int n)
{
    int x = 1, y = 0, res = 0;

    for (int i = 1; i <= n; i++)
    {
        y = x;
        x = res;
        res = x + y;
    }

    return res;
}

unsigned int FibR(unsigned int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return FibR(n - 1) + FibR(n - 2);
}