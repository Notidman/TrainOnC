/*Study in C / C ++
        and algorithms*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printmass(int*, int);
void GenerateNumber(int*, int);
void Shuffle(int, int*, int, int);

int main()
{
    int n;

    printf("Enter number(1-1000): ");
    do
    {
        scanf_s("%d", &n);
        if (n > 1000 || n <= 0)
        {
            system("cls");
            printf("Enter number(1-1000): ");
        }
    } while (n > 1000 || n <= 0);

    int* mass = (int*)malloc(n * sizeof(int));

    Shuffle(n, mass, 1, 1000);

    printmass(mass,n);

    return 0;
}

void Shuffle(int arr_size, int* parr, int range_min, int range_max) {
    srand(time(NULL));

    int i, j;
    int dup_flag;
    int rand_val;

    for (i = 0; i < arr_size; i++)
    {
        while(1)
        {
            rand_val = range_min + rand() % arr_size;
            dup_flag = 0;
            for (j = 0; j < i; j++)
            {
                if (rand_val == parr[j]) { dup_flag = 1; break; }
            }
            if (!dup_flag) { break; }
        }
        parr[i] = rand_val;
    }

}

void printmass(int* p, int s)
{
    printf("%13s\n", "List:");
    int j = 1;
    for (int i = 0; i <= s - 1; i++)
        printf("Element[%d] = [%d]\n", j++, p[i]);
}

void GenerateNumber(int *p, int s)
{
    for (int i = 0; i <= s - 1; i++)
    {
        p[i] = 1 + rand() % s;
    }
}

void swap(int* f, int* s)
{
    int temp;
    temp = *f;
    *f = *s;
    *s = temp;
}