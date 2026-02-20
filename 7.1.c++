#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void InsNode(struct studentNode **start, struct studentNode **now,
             char n[], int a, char s, float g)
{
    struct studentNode *newNode =
        (struct studentNode*)malloc(sizeof(struct studentNode));

    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = *now = newNode;
    } else {
        newNode->next = *start;
        *start = newNode;
    }
}

void InsertNode(struct studentNode **start, struct studentNode **now,
                char n[], int a, char s, float g)
{
    struct studentNode *newNode =
        (struct studentNode*)malloc(sizeof(struct studentNode));

    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = *now = newNode;
    } else {
        newNode->next = *start;
        *start = newNode;
    }
}

void GoNext(struct studentNode **now)
{
    if (*now != NULL && (*now)->next != NULL)
        *now = (*now)->next;
}

void DelNode(struct studentNode **start, struct studentNode **now)
{
    struct studentNode *temp, *walk;

    if (*start == NULL) return;

    if (*start == *now) {
        temp = *start;
        *start = (*start)->next;
        *now = *start;
        free(temp);
    } else {
        walk = *start;
        while (walk->next != *now)
            walk = walk->next;

        temp = *now;
        walk->next = (*now)->next;
        *now = walk->next;
        free(temp);
    }
}

void ShowNode(struct studentNode *now)
{
    if (now != NULL)
        printf("%s %d %c %.2f\n",
               now->name, now->age,
               now->sex, now->gpa);
}


int main()
{
    struct studentNode *listA_start=NULL, *listA_now=NULL;
    struct studentNode *listB_start=NULL, *listB_now=NULL;
    struct studentNode *listC_start=NULL, *listC_now=NULL;

    InsNode(&listA_start,&listA_now,"one",1,'A',1.1);
    InsNode(&listA_start,&listA_now,"two",2,'B',2.2);
    InsNode(&listA_start,&listA_now,"three",3,'C',3.3);
    GoNext(&listA_now);
    ShowNode(listA_now);

    InsertNode(&listB_start,&listB_now,"four",4,'D',4.4);
    InsertNode(&listB_start,&listB_now,"five",5,'E',5.5);
    InsertNode(&listB_start,&listB_now,"six",6,'F',6.6);
    GoNext(&listB_now);
    DelNode(&listB_start,&listB_now);
    printf("%s %s\n", listB_start->name,
                      listB_start->next->name);

    listC_start = listA_start;
    listC_now   = listC_start;
    GoNext(&listC_now);
    ShowNode(listC_now);

    listC_start = listB_start;
    listC_now   = listC_start;
    printf("%s %s\n", listC_start->name,
                      listC_start->next->name);

    return 0;
}
