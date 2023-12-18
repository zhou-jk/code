#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int a, n;
    struct Node *next;
};
int main()
{
    struct Node *head = NULL, *tail = NULL;
    int a, n;
    while (scanf("%d%d", &a, &n) != EOF)
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->a = a, p->n = n;
        if (head == NULL)
            head = p;
        else
            tail->next = p;
        tail = p, tail->next = NULL;
    }
    struct Node *pp = NULL;
    for (struct Node *p = head, *np; p != NULL; p = np)
    {
        np = p->next;
        if (p->n != 0)
        {
            p->a *= p->n;
            p->n--;
            pp = p;
        }
        else
        {
            if (p == head)
                head = np;
            else
                pp->next = np;
            free(p);
        }
    }
    if (head == NULL)
        printf("0 0");
    else
        for (struct Node *p = head; p != NULL; p = p->next)
        {
            if (p != head)
                printf(" ");
            printf("%d %d", p->a, p->n);
        }
    return 0;
}