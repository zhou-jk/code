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

struct ListNode *getodd(struct ListNode **L)
{
    struct ListNode *odd_head = NULL, *odd_tail = NULL;
    struct ListNode *even_head = NULL, *even_tail = NULL;
    for (struct ListNode *p = *L, *np; p != NULL; p = np)
    {
        np = p->next;
        if ((p->data) & 1)
        {
            if (odd_head == NULL)
                odd_head = odd_tail = p;
            else
                odd_tail->next = p, odd_tail = p, odd_tail->next = NULL;
        }
        else
        {
            if (even_head == NULL)
                even_head = even_tail = p;
            else
                even_tail->next = p, even_tail = p, even_tail->next = NULL;
        }
    }
    *L = even_head;
    return odd_head;
}