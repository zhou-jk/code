#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    struct Node *head = NULL, *tail = NULL;
    for (int i = 1; i <= n; i++)
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = i;
        p->prev = tail;
        if (tail != NULL)
            tail->next = p;
        else
            head = p;
        tail = p;
        tail->next = NULL;
    }
    tail->next = head;
    head->prev = tail;
    struct Node *p = head;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            for (int j = 1; j < m; j++)
                p = p->prev;
            printf("%d ", p->data);
            p->prev->next = p->next;
            p->next->prev = p->prev;
            struct Node *np = p->prev;
            free(p);
            p = np;
        }
        else
        {
            for (int j = 1; j < k; j++)
                p = p->next;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            printf("%d ", p->data);
            struct Node *np = p->next;
            free(p);
            p = np;
        }
    }
    return 0;
}