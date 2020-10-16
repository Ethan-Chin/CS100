#include<stdio.h>
#include<malloc.h>
int main()
{
    int i, j = 0, size = 5;
    float sum = 0, *pArray = NULL, shuru;
    pArray = (float *)malloc(sizeof(float) * size);
    printf("Please type scores to be calculated:\n");
    for (;;)
    {
        while(j < size)
        {
            scanf("%f", &shuru);
            getchar();
            if (shuru == -1)
                break;
            pArray[j] = shuru;
            j++;
        }
        if (shuru == -1)
            break;
        size = size * 2;
        pArray = (float *)realloc(pArray, sizeof(float) * size);
        printf("(resize) from %d to %d\n", size/2, size);
    }
    for(i = 0; i < j; i++)
    {
        sum = sum + pArray[i];
    }
    printf("Average score: %.2f\n", sum / j);
    free(pArray);
    getchar();
    return 0;
}