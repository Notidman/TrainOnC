/*Study in C / C ++
        and algorithms*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

long int d_factorial(int);
long int d_factorial_2(int);

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
    res = d_factorial(n);
    clock_t end = clock();
    printf("D_factorial seconds:\n%10f\n\n", (double)(end - begin) / CLOCKS_PER_SEC);

    begin = clock();
    res2 = d_factorial_2(n);
    end = clock();
    printf("D_factorial_2 seconds:\n%10f\n\n", (double)(end - begin) / CLOCKS_PER_SEC);

    printf("%s%15s\n", "d_factorial","d_factorial_2");
    printf("%5d%15d\n", res, res2);
    return 0;
}

long int d_factorial(int n)
{
    if (n < 3)
    {
        return n;
    }
    else
    {
        return n * d_factorial(n - 2);
    }
}

long int d_factorial_2(int n)
{
    int f = 1;
    if (n % 2 == 0)
    {
        for (int i = 2; i <= n; i += 2)
        {
            f *= i;
        }
    }
    else
    {
        for (int i = 1; i <= n; i += 2)
        {
            f *= i;
        }
    }

    return f;
}