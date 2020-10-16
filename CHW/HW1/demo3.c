#include <stdio.h>
int main()
{
    int times, i;
    float mood = 100, rtimes, ltimes, hour1, minute1, hour2, minute2, preh2, prem2;
    char a, b, c;
    printf("How many lectures today?\n");
    scanf("%d", &times);
    fflush(stdin);
    for (i = 0; i < times; i++)
    {
        scanf("%f%c%f%c%f%c%f", &hour1, &a, &minute1, &b, &preh2, &c, &prem2);
        fflush(stdin);
        if (i == 0)
        {
            rtimes = (hour1 - 8) * 60 + minute1;
        }
        else
        {
            rtimes = (hour1 - hour2) * 60 + (minute1 - minute2);
        }
        mood = mood + rtimes * 0.5;
        if (mood > 100)
        {
            mood = 100;
        }
        hour2 = preh2;
        minute2 = prem2;
        ltimes = (hour2 - hour1) * 60 + (minute2 - minute1);
        if (ltimes > 60)
        {
            mood = mood - 24 - (ltimes - 60) * 0.8;
        }
        else
        {
            mood = mood - ltimes * 0.4;
        }
        if (mood <= 0)
            break;
    }
    if (mood > 0)
    {   
        mood = mood + ((22 - hour2) * 60 + (0 - minute2)) * 0.5;
        if (mood > 100)
        {
            mood = 100;
        }
        printf("His mood level is %.1f at the end of the day.\n", mood);
    }
    else
    {
        printf("Gezi Wang has been sent to hospital.\n");
    }
    getchar();
    return 0;
}