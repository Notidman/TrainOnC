/*Study in C / C ++
        and algorithms*/

#include <stdio.h>
#include <stdlib.h>

float calculateCharges(float);
float foundSum(float, float);

int main() {

    int global = 3, j = 0;
    float Hours[] = { 1.5, 4.0, 24.00};
    float Charge = 0;
    float sum = 0;
    printf("%-10s%10s%10s\n", "Car", "Hours", "Charge");
    for (int i = 1; i <= global; i++)
    {
        printf("%-10d%10.2f%10.2f\n", i, Hours[j++], Charge = calculateCharges(Hours[j]));
        sum += Charge;
    }
    printf("%-10s%10.2f%10.2f", "TOTAL", Hours[0] + Hours[1] + Hours[2], sum);
    return 0;
}

float calculateCharges(float h)
{
    float res = 2.00;
    if (h <= 3)
        return res;
    else
        if (h == 24)
        return 10.00;
        else
        {
            return res = foundSum(res,h);
        }

}

float foundSum(float r, float h)
{
    int timer = h;
    for (; timer >= 3; timer -= 2)
    {
        r += 0.50;
    }
    return r;
}