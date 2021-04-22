/*Study in C / C ++
        and algorithms*/

#include <stdio.h>
#include <stdlib.h>

long factorial(long);

int main() {

    int i;

    for (i = 1; i <= 10; i++)
        printf("%2d! = %ld\n", i, factorial(i));

    return 0;
}
long factorial(long num) {
    if (num <= 1)
        return 1;
    else
        return num * factorial(num - 1);
}