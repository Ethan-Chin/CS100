#include <stdio.h>

int main()
{
    int a[16667], b[16667], c[16667], d[16667], e[16667], pi[5000], x, i, j, y = 0, z;
    char dot = '.';
    for (x = 0; x < 16667; x++)
    {
      a[x] = x;
      b[x] = x * 2 + 1;
      c[x] = 2;
    }
    b[0] = 10;
    for ( j = 0; j < 5000; j++)
    {
        for (i = 0; i < 16667; i++)
        {
            c[i] = c[i] * 10;
        }   
        e[16666] = c[16666];
        c[16666] = e[16666] % b[16666];
        for ( i = 16665; i >= 0; i--)
        {
            d[i] = (e[i+1] / b[i+1]) * a[i+1];
            e[i] = c[i] + d[i];
            c[i] = e[i] % b[i];
        }
        pi[j] = e[0] / 10;
        if ((e[0] / 10) == 9)
        {
            y = y + 1;
        }
        else if ((e[0] / 10) == 10)
        {
            pi[j - (y + 1)] = pi[j - (y + 1)] + 1;
            for (z = 0; z <= y; z++)
            {
                pi[j - y + z] = 0;
            }
        }
        else
        {
            y = 0;
        }
    }
    for ( j = 0; j < 5000; j++)
    {
        printf("%d", pi[j]);
        if (j > 0)
            continue;
        printf("%c", dot);
    }
    printf("\n");
    getchar();
    return 0;
}
