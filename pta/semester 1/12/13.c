#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    struct Node *head = NULL, *tail = NULL;
    for (int i = 1; i <= n; i++)
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = i;
        if (tail != NULL)
            tail->next = p;
        else
            head = p;
        tail = p;
        tail->next = NULL;
    }
    tail->next = head;
    struct Node *p = tail, *pp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            pp = p, p = p->next;
        printf("%4d", p->data);
        pp->next = p->next;
        free(p);
        p = pp;
    }
    return 0;
}