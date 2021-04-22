/*Study in C / C ++
        and algorithms*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printmass(int*, int);
void GenerateNumber(int*, int);
void Shuffle(int, int*, int, int);
void PlaceSort(int*,int);

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
    printf("%13s\n", "Sort:");
    printmass(mass, n);

    PlaceSort(mass,n);

    return 0;
}

void PlaceSort(int* m, int s)
{
    int newElement, location;

    for (int i = 1; i < s; i++)
    {
        newElement = m[i];
        location = i - 1;
        while (location >= 0 && m[location] > newElement)
        {
            m[location + 1] = m[location];
            location = location - 1;
        }
        m[location + 1] = newElement;
        printmass(m, s);
    }
}

void Shuffle(int arr_size, int* parr, int range_min, int range_max)
{
    srand(time(NULL));

    int i, j;
    int dup_flag;
    int rand_val;

    for (i = 0; i < arr_size; i++)
    {
        while (1)
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
    for (int i = 0; i <= s - 1; i++)
        printf("%2d ", p[i]);
    printf("\n");
}

void GenerateNumber(int* p, int s)
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