/*Study in C / C ++
        and algorithms*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>

void InsideMass(int[], int);
void generator(int[], int);
void findByLine(int[], int, int);
void findByTwoMax(int[], int);
void binSearch(int, int[], int);
int deleteRepeats(int[], int);

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {

    int SIZE;
    int *ind = NULL;
    int elem;

    srand(time(NULL));
    int x = 1 + rand() % 1000;

    do {
        printf("Enter n: ");
        scanf_s("%d", &SIZE);
        if (SIZE <= 0)
            system("cls");

    } while (SIZE <= 0);

    int* a = (int*)malloc(SIZE * sizeof(int));

    generator(a, SIZE); // Заполняем массив

    qsort(a, SIZE, sizeof(int), cmp); // Сортируем массив

    SIZE = deleteRepeats(a, SIZE); // Удаляем повторы

    InsideMass(a, SIZE); // Выводим массив

    binSearch(x, a, SIZE); // Проводим бинарный поиск
    
    return 0;
}

void InsideMass(int mass[], int s)
{
    printf("%13s\n", "List:");
    int j = 1;
    for (int i = 0; i <= s - 1; i++)
        printf("Element%2d = %5d\n", j++, mass[i]);
}

void generator(int mass[], int r)
{
    srand(time(NULL));
    for (int i = 0; i <= r - 1; i++)
        mass[i] = 1 + rand() % 1000;
}

void findByLine(int mass[], int x, int s)
{
    bool fl = false;
    for (int i = 0; i <= s - 1; i++)
    {
        if (mass[i] == x)
        {
            printf("Found %d! in %d\n", x, i);
            fl = true;
            break;
        }

    }
    if (fl == false)
        printf("Not found =(\n");
}

void findByTwoMax(int mass[], int s)
{
    int max1 = mass[0], max2 = mass[0];
    int num1 = 0, num2 = 0;
    bool fl = false;

    for (int i = 0; i <= s - 1; i++)
    {
        if (max1 < mass[i])
        {
            max2 = max1;
            num2 = num1;
            max1 = mass[i];
            num1 = i;
        }

        if (mass[i] > max2 && mass[i] != max1)
        {
            max2 = mass[i];
            num2 = i;
        }

    }

    printf("Max 1 is %d with %d\nMax 2 is %d with %d", max1, ++num1, max2, ++num2);
}

int deleteRepeats(int mass[], int s)
{
    if (s == 0 || s == 1)
        return s;

    int* temp = (int*)malloc(s * sizeof(int));

    int j = 0;
    int i;
    for (i = 0; i < s - 1; i++)
        if (mass[i] != mass[i + 1])
            temp[j++] = mass[i];
    temp[j++] = mass[s - 1];

    for (i = 0; i < j; i++)
        mass[i] = temp[i];

    return j;
}

void binSearch(int a, int mass[], int s)
{
    int low = 0, high = s - 1, middle;
    
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (a < mass[middle])
            high = middle - 1;
        else if (a > mass[middle])
            low = middle + 1;
        else
            return printf("Found %d in %d", a, middle);
    }

    return printf("Not found =(");
}