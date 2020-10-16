#include<stdio.h>
#include<math.h>
#include<malloc.h>
int main()
{
    int i, j, r, sizeA = 5, sizeB = 5, *pArrayA = NULL, *pArrayB = NULL, shuru, jA = 0, jB = 0, diff, tem_diff, first_i;
    pArrayA = (int *)malloc(sizeof(int) * sizeA);
    pArrayB = (int *)malloc(sizeof(int) * sizeB);
    printf("Please input the set A:\n");
    for (;;)
    {
        while(jA < sizeA)
        {
            scanf("%d", &shuru);
            getchar();
            if (shuru == -1)
                break;
            pArrayA[jA] = shuru;
            jA++;
        }
        if (shuru == -1)
            break;
        sizeA = sizeA * 2;
        pArrayA = (int *)realloc(pArrayA, sizeof(int) * sizeA);
        printf("(resize) from %d to %d\n", sizeA/2, sizeA);
    }
    printf("Please input the set B:\n");
    for (;;)
    {
        while(jB < sizeB)
        {
            scanf("%d", &shuru);
            getchar();
            if (shuru == -1)
                break;
            pArrayB[jB] = shuru;
            jB++;
        }
        if (shuru == -1)
            break;
        sizeB = sizeB * 2;
        pArrayB = (int *)realloc(pArrayB, sizeof(int) * sizeB);
        printf("(resize) from %d to %d\n", sizeB/2, sizeB);
    }
    for (i = 0; i < (jA - jB + 1); i++)
    {
        tem_diff = 0;
        for (j = 0; j < jB; j++)
        {
            tem_diff += fabs(pArrayA[i + j] - pArrayB[j]);
        }
        if((tem_diff < diff) || (i == 0))
        {
            diff = tem_diff;
            first_i = i;
        }
    }
    puts("---Result---");
    for (r = 0; r < jB; r++)
    {
        pArrayB[r] = pArrayA[first_i + r];
        printf("%d ", pArrayB[r]);
    }
    free(pArrayA);
    free(pArrayB);
    return 0;
}