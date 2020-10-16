#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define RES_SIZE 128
#define NAME_SIZE 64
typedef struct
{
    char name[NAME_SIZE];
    float score;
}
Student;
int compare (const char* str1, const char* str2)
{
    while (*str1 == *str2 && *str1 != '\0')
    {
        str1++;
        str2++;
    }
    if ((*str1 - *str2) < 0)
        return -1;
    else if ((*str1 - *str2) > 0)
        return 1;
    else
        return 0;
}
void string_sort (char* strings[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (compare(strings[j - 1], strings[j]) == 1)
            {
                char* t;
                t = strings[j];
                strings[j] = strings[j - 1];
                strings[j - 1] = t;
            }
        }
        
    }
}
Student* new_student(const char* _name, float _score)
{
    Student* p = (Student*)malloc(sizeof(Student));
    strcpy (p -> name, _name);
    p -> score = _score;
    return p;
}
int main()
{
    char* str[] = {"qw", "ed", "fg", "ty", "ui", "hj"};
    string_sort (str, 6);
    for (int n = 0; n < 6; n++)
    {
        printf("%s\n", str[n]);
    }
    Student* geziwang = new_student("Gezi Wang", 0.0);
    printf("%s %f\n", geziwang -> name, geziwang -> score);
    free(geziwang);
    getchar();
    return 0;
}