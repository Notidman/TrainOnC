/*Study in C / C ++
        and algorithms*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void Bubble(int*, const int, int (*) (int,int));
int ascending(const int, const int);
int descending(const int, const int);
void printm(int*);

int main(void)
{
    int a[SIZE] = { 2,6,4,8,10,12,89,68,45,37 };
    int order;

    printf("1 - ascending; 2 - descending: ");
    scanf_s("%d", &order);

    printf("\nData items in ordinal order: \n\n");
    printm(a);
    printf("\n");

    if (order == 1)
    {
        Bubble(a, SIZE, ascending);
        printf("\nData items in ascending order: \n\n");
    }
    else
    {
        Bubble(a, SIZE, descending);
        printf("\nData items in descending order: \n\n");
    }
    printm(a);
    printf("\n");

    return 0;
}

void printm(int* m)
{
    for (int i = 0; i <= SIZE - 1; i++)
        printf("%4d", m[i]);
}

void Bubble(int* mass, const int s, int (*choise) (int, int))
{
    void swap(int*, int*);
    for (int i = 0; i <= s - 1; i++)
        for (int j = 0; j <= s - 2; j++)
        {
            if ((*choise) (mass[j],mass[j + 1]))
            {
                swap(&mass[j], &mass[j + 1]);
            }
        }
}

int ascending(const int a, const int b)
{
    return b < a;
}
int descending(const int a, const int b)
{
    return b > a;
}

void swap(int* f, int* s)
{
    int temp;
    temp = *f;
    *f = *s;
    *s = temp;
}