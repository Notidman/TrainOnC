/*Study in C / C ++
        and algorithms*/
#include <stdio.h>
#define SIZE 10

int main()
{
    float numbers[SIZE] = { 0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9 };

    float* nPtr;

    for (int i = 0; i <= SIZE - 1; i++)
        printf("%.1f\n", numbers[i]);

    nPtr = numbers;
    nPtr = &numbers[0];

    for (int i = 0; i <= SIZE - 1; i++)
        printf("%s/%f\n", "nPtr", *(nPtr + i));

    for (int i = 0; i <= SIZE - 1; i++)
        printf("%s/%f\n", "nPtr", *(numbers + i));

    for (int i = 0; i <= SIZE - 1; i++)
        printf("%s/%f\n", "nPtr", nPtr[i]);

    numbers[4];
    *(numbers + 4);
    nPtr[4];
    *(nPtr + 4);

    return 0;
}