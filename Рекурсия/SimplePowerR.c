/*Study in C / C ++
        and algorithms*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

double power(double, int);

int main()
{
    double a, res;
    int n;

    printf("Enter number and degree: ");
    do
    {
        scanf_s("%lf", &a);
        scanf_s("%d", &n);

        if (a < 0)
        {
            system("cls");
            printf("Incorrect number!");
            Sleep(1000);
            system("cls");
            printf("Enter number and degree: ");
        }
        if (n < 0)
        {
            system("cls");
            printf("Incorrect degree!");
            Sleep(1000);
            system("cls");
            printf("Enter number and degree: ");
        }

    } while (a < 0 || n < 0);

    res = power(a, n);

    printf("Number [%.2f] to the power of [%d] = %.2f\n", a, n, res);

    return 0;
}

double power(double a, int n)
{
    if (n == 0) return 1;
    if (n < 0) return power(1.0 / a, -n);
    return a * power(a, n - 1);
}