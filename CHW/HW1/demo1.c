#include <stdio.h>
int main()
{
    int i, times;
    float m, n, c;
    printf("Please type number of inputs: ");
    scanf("%d", &times);
    fflush(stdin);
    scanf("%f", &m);
    fflush(stdin);
    scanf("%f", &n);
    fflush(stdin);
    if (m < n)
    {
        c = m;
        m = n;
        n = c;
    }
    for (i = 2; i < times; i++)
    {
        scanf("%f", &c);
        fflush(stdin);
        if (m < c)
        {
            m = c;
        }
        if (c < n)
        {
            n = c;
        }
    }
    printf("Max value: %.1f\n", m);
    printf("Min value: %.1f\n", n);
    getchar();
    return 0;
}