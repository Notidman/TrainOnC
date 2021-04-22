/*Study in C / C ++
        and algorithms*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10

void AddCurMass(float[], int[]);

int i = 0;

int main() {

    int rounded[SIZE];
    float unrounded[SIZE];

    AddCurMass(unrounded, rounded);

    printf("%-10s%10s\n", "Unrounded", "Rounded");
    for (int j = 0; j < i; j++)
    {
        printf("%-10.2f=%5d\n", unrounded[j], rounded[j]);
    }

    return 0;
}

void AddCurMass(float mass1[], int mass2[])
{
    int n = 1;
    float number;

    do {
        printf("%d: ", n++);
        scanf_s("%f", &number);

        mass1[i] = number;
        mass2[i] = floor(number + .5);

        i++;
    } while (i != 10);
    system("cls");
}