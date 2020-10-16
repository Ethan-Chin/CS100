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

typedef struct node
{
    Student *data;
    struct node *next;
}
Node;

typedef struct 
{
    Node *head;
    Node *tail;
    int size;
}
LinkedList;

//part00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

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

/*void string_sort (char* strings[], int size)
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
}*/

Student* new_student(const char* _name, float _score)
{
    Student* p = (Student*)malloc(sizeof(Student));
    strcpy(p -> name, _name);
    p -> score = _score;
    return p;
}
//part111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

void list_init(LinkedList* l)
{
    l -> head = NULL;
    l -> tail = NULL;    
    l -> size = 0;
}

void list_insert(LinkedList* l, Student* stu_ptr)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p -> data = stu_ptr;
    p -> next = NULL;
    if (l -> head)
    {
        (l -> tail) -> next = p;
        l -> tail = p;
    }
    else
    {
        l -> head = p;
        l -> tail = p;
    }
    l -> size += 1;
}

void list_erase(LinkedList* l)
{
    Node *pEr = l -> head, *qEr = pEr -> next;
    while (qEr)
    {
        qEr = pEr -> next;
        free(pEr);
        pEr = qEr;
    }
    if (l -> size == 1)
        free(pEr);
    l -> head = NULL;
    l -> tail = NULL;
    l -> size = 0;
}

Node* list_remove(LinkedList* l, Node* target)
{
    Node *p = NULL, *q = l -> head, *r = l ->head;
    int search = 0;
    while(r)
    {
        if (r == target)
        {
            search += 1;
        }
        r = r -> next;
    }
    if (search != 0)
    {   
        if(l -> size != 1)
        {
            if((q != target) && (l -> tail != target))
            {
                while (q != target)
                {
                    p = q;
                    q = q -> next;
                }
                p -> next = q -> next;
                free(q);
                l -> size -= 1;
                return (p -> next);
            }
            else if (l -> tail == target)
            {
                while (q != target)
                {
                    p = q;
                    q = q -> next;
                }
                p -> next = NULL;
                l -> tail = p;
                free(q);
                l -> size -= 1;
                return NULL;
            }
            else
            {
                p = q;
                q = q -> next;
                l -> head = q;
                free(p);
                l -> size -= 1;
                return(q);
            }
            
        }
        else
        {
            free(q);
            l -> head = NULL;
            l -> tail = NULL;
            l -> size = 0;
            return NULL;
        }
        
    }
    else
    {
        return NULL;
    }
}

//part2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
int main()
{
    /*char* str[] = {"qw", "ed", "fg", "ty", "ui", "hj"};
    string_sort (str, 6);
    for (int n = 0; n < 6; n++)
    {
        printf("%s\n", str[n]);
    }
    Student* geziwang = new_student("Gezi Wang", 0.0);
    printf("%s %f\n", geziwang -> name, geziwang -> score);
    free(geziwang);
    getchar();*/
    char name1[] = "Adele";
    float a = 1.2f;
    Student *Adele = new_student(name1, a);
    LinkedList *test;
    list_init(test);
    list_insert(test, Adele);
    Node* target1 = l -> head;
    list_remove(test, target1);
    printf("head name %s\n", test ->head->data->name);
    printf("tail name%s\n", test ->tail->data->name);
    printf("before size %d\n", test -> size);
    list_erase(test);
    printf("after size %d\n", test -> size);
    getchar();
    return 0;
}