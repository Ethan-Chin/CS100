#include <stdio.h>

int main()
{
    int num;
    char** data;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%s", (data + i));
    }
    
    return 0;
}