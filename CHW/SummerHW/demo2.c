#include <stdio.h>
int main(){
    float no1, no2;
    char ways, b;
    int a;
    for(a = 1; a > 0; a = a)
    {
        printf("Enter the arithmetic expression to be evaluated (e.g. 5 + 6):\n");
        scanf("%f %c %f", &no1, &ways, &no2);
        fflush(stdin);
        if (ways == '+'||ways == '-'||ways == '*'||ways == '/')
        {
    
            if (ways == '+')
            {
                float result = no1 + no2;
                printf("%f\n",result);
            }
            else if (ways == '-')
            {
                float result = no1 - no2;
                printf("%f\n",result);
            }
            else if (ways == '*')
            {
                float result = no1 * no2;
                printf("%f\n",result);
            }
            else
            {
                float result = no1 / no2;
                printf("%f\n",result);
            }
        }
        else
        {
            printf("Error\n");
        }
        printf("Did you want to enter another expression? (Enter 'y' or 'n'): ");
        scanf("%c", &b);
        fflush(stdin);
        if (b == 'y')
        {
           a = a;
        }
        else
        {
            a = a - 1;
        }
        
    } 
    return 0;
}