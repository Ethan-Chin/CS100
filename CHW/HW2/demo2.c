#include<stdio.h>
#include<malloc.h>
int main()
{
    char blank;
    int i, j = 0, size = 5, xuehao, m, n, txue, *pArray2 = NULL;
    float sum = 0, *pArray1 = NULL, shuru, tshu;
    pArray1 = (float *)malloc(sizeof(float) * size);
    pArray2 = (int *)malloc(sizeof(int) * size);
    printf("Please type scores to be calculated:\n");
    for (;;)
    {
        while(j < size)
        {
            scanf("%d%c%f", &xuehao, &blank, &shuru);
            getchar();
            if (shuru == -1)
                break;
            pArray1[j] = shuru;
            pArray2[j] = xuehao;
            j++;
        }
        if (shuru == -1)
            break;
        size = size * 2;
        pArray1 = (float *)realloc(pArray1, sizeof(float) * size);
        pArray2 = (int *)realloc(pArray2, sizeof(int) * size);
        printf("(resize) from %d to %d\n", size/2, size);
        printf("(resize) from %d to %d\n", size/2, size);
    }
    puts("---Result---");
    for(m = 0; m < j; m++)
	{
		for(n = 1; n < j; n++)
		{
			if(pArray1[n -1] > pArray1[n])
			{
				tshu = pArray1[n -1];
				pArray1[n - 1] = pArray1[n];
				pArray1[n] = tshu;
                txue = pArray2[n - 1];
				pArray2[n - 1] = pArray2[n];
				pArray2[n] = txue;
			}
            if ((pArray1[n - 1] == pArray1[n]) && (pArray2[n - 1] > pArray2[n]))
            {
                tshu = pArray1[n - 1];
				pArray1[n - 1] = pArray1[n];
				pArray1[n] = tshu;
                txue = pArray2[n - 1];
				pArray2[n - 1] = pArray2[n];
				pArray2[n] = txue;
            }
            
		}
	}
    for (i = 0; i < j; i++)
    {
        printf("%d %.1f\n", pArray2[i], pArray1[i]);
    }
    free(pArray1);
    free(pArray2);
    getchar();
    return 0;
}