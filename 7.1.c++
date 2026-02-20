#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
} StudentNode;

StudentNode* createNode(char n[], int a, char s, float g) {
    StudentNode *newNode = (StudentNode*)malloc(sizeof(StudentNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    return newNode;
}

void insertFront(StudentNode **start, StudentNode **now,
                 char n[], int a, char s, float g)
{
    StudentNode *newNode = createNode(n, a, s, g);

    if (*start == NULL) {
        *start = *now = newNode;
    } else {
        newNode->next = *start;
        *start = newNode;
    }
}

void goNext(StudentNode **now) {
    if (*now != NULL && (*now)->next != NULL)
        *now = (*now)->next;
}

void deleteCurrent(StudentNode **start, StudentNode **now) {
    if (*start == NULL || *now == NULL) return;

    StudentNode *temp;

    if (*start == *now) {
        temp = *start;
        *start = (*start)->next;
        *now = *start;
        free(temp);
        return;
    }

    StudentNode *walk = *start;
    while (walk->next != NULL && walk->next != *now)
        walk = walk->next;

    if (walk->next == NULL) return;

    temp = *now;
    walk->next = (*now)->next;
    *now = walk->next;
    free(temp);
}

void showNode(StudentNode *now) {
    if (now != NULL)
        printf("%s %d %c %.2f\n",
               now->name,
               now->age,
               now->sex,
               now->gpa);
}

int main() {
    StudentNode *listA_start = NULL, *listA_now = NULL;
    StudentNode *listB_start = NULL, *listB_now = NULL;
    StudentNode *listC_start = NULL, *listC_now = NULL;

    insertFront(&listA_start, &listA_now, "one",   1, 'A', 1.1);
    insertFront(&listA_start, &listA_now, "two",   2, 'B', 2.2);
    insertFront(&listA_start, &listA_now, "three", 3, 'C', 3.3);

    goNext(&listA_now);
    showNode(listA_now);

    insertFront(&listB_start, &listB_now, "four", 4, 'D', 4.4);
    insertFront(&listB_start, &listB_now, "five", 5, 'E', 5.5);
    insertFront(&listB_start, &listB_now, "six",  6, 'F', 6.6);

    goNext(&listB_now);
    deleteCurrent(&listB_start, &listB_now);

    printf("%s %s\n",
           listB_start->name,
           listB_start->next->name);

    listC_start = listA_start;
    listC_now   = listC_start;
    goNext(&listC_now);
    showNode(listC_now);

    listC_start = listB_start;
    listC_now   = listC_start;

    printf("%s %s\n",
           listC_start->name,
           listC_start->next->name);

    return 0;
}
