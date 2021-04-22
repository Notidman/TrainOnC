/*Study in C / C ++
        and algorithms*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void Buble(int*, int);
void printmass(int*, int);

int main()
{
    int mass[SIZE] = { 2,4,6,8,10,500,100,34,62,10 };
    printmass(mass, SIZE);

    printf("After:\n");
    Buble(mass, SIZE);
    printmass(mass, SIZE);
    return 0;
}

void Buble(int *mass, int s)
{
    void swap(int*, int*);
    for(int i = 0; i <= s - 1; i++)
        for (int j = 0; j <= s - 2; j++)
        {
            if (mass[j] > mass[j + 1])
                swap(&mass[j], &mass[j + 1]);
        }
}

void swap(int *f, int *s)
{
    int temp;
    temp = *f;
    *f = *s;
    *s = temp;
}

void printmass(int *p, int s)
{
    for (int i = 0; i <= s - 1; i++)
    {
        printf("index[%d], value[%3d]\n", i, *p);
        p++;
    }
}