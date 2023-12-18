#include <stdio.h>

struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *pp = NULL;
    for (struct ListNode *p = head, *np; p != NULL; p = np)
    {
        np = p->next;
        p->next = pp;
        pp = p;
    }
    return pp;
}