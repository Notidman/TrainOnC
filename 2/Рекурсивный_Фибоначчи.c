/*Study in C / C ++
        and algorithms*/

#include <stdio.h>
#include <stdlib.h>

long fibonacci(long);

int main() {

    int i;

    for (i = 1; i <= 10; i++)
        printf("%2d = %ld\n", i, fibonacci(i));

    return 0;
}
long fibonacci(long num) {
    if (num == 0 || num == 1)
        return num;
    else
        return fibonacci(num - 1) + fibonacci(num - 2);
}