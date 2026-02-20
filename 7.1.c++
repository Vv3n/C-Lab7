#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
};

class LinkList {
protected:
    studentNode *start, *now;

public:
    LinkList();
    ~LinkList();

    void InsNode(char n[], int a, char s, float g);
    void GoNext();
    void DelNode();
    virtual void ShowNode();
};

class NewList : public LinkList {
public:
    void GoFirst();
    virtual void ShowNode();
};

int main() {

    LinkList listA;
    NewList listB;
    LinkList *listC;

    listA.InsNode("one", 1, 'A', 1.1);
    listB.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);

    listB.LinkList::ShowNode();

    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);

    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}

LinkList::LinkList() {
    start = NULL;
    now = NULL;
}

LinkList::~LinkList() {
    studentNode *temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void LinkList::InsNode(char n[], int a, char s, float g) {
    studentNode *p = new studentNode;

    strcpy(p->name, n);
    p->age = a;
    p->sex = s;
    p->gpa = g;

    p->next = start;
    start = p;
    now = start;
}

void LinkList::GoNext() {
    if (now != NULL)
        now = now->next;
}

void LinkList::DelNode() {
    if (now == NULL || now->next == NULL)
        return;

    studentNode *temp = now->next;
    now->next = temp->next;
    delete temp;
}

void LinkList::ShowNode() {
    if (now != NULL) {
        cout << now->name << " "
             << now->age << " "
             << now->sex << " "
             << fixed << setprecision(2)
             << now->gpa << endl;
    }
}

void NewList::GoFirst() {
    now = start;
}

void NewList::ShowNode() {
    studentNode *p = start;
    int count = 0;

    while (p != NULL && count < 2) {
        cout << p->name;
        if (count == 0) cout << " ";
        p = p->next;
        count++;
    }
    cout << endl;
}