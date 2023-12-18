#include <stdio.h>
#include <stdlib.h>

struct ListNode *readlist()
{
    struct ListNode *head = NULL, *tail = NULL;
    while (1)
    {
        int num;
        scanf("%d", &num);
        if (num == -1)
            break;
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->data = num;
        if (tail != NULL)
            tail->next = p;
        else
            head = p;
        tail = p;
        tail->next = NULL;
    }
    return head;
}

struct ListNode *deletem(struct ListNode *L, int m)
{
    struct ListNode *pp = NULL;
    for (struct ListNode *p = L, *np; p != NULL; p = np)
    {
        np = p->next;
        if (p->data == m)
        {
            if (p == L)
                L = p->next;
            else
                pp->next = p->next;
            free(p);
        }
        else
            pp = p;
    }
    return L;
}