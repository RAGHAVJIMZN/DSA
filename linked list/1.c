#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start;

struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void insbeg(int x)
{
    struct node *p;
    p = getnode();
    p->info = x;
    p->next = start;
    start = p;
}
void insend(int x)
{
    struct node *q, *p;
    q = start;
    while (q->next != NULL)
    {
        q = q->next;
    }
    p = getnode();
    p->info = x;
    p->next = NULL;
    q->next = p;
}
void traverse()
{
    struct node *p;
    p = start;
    int count = 0;

    while (p != NULL)
    {

        printf("%d\n", p->info);
        p = p->next;
        count++;
    }
    printf("%d", count);
}
int main()
{
    int count;
    start = NULL;
    insbeg(100);
    insbeg(200);
    insbeg(300);
    insbeg(400);
    insend(10);
    insend(20);
    insend(30);
    traverse();
}