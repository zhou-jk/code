#include <stdio.h>
#include <stdlib.h>

struct ListNode *createlist()
{
    struct ListNode *head = NULL;
    while (1)
    {
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        int num;
        scanf("%d", &num);
        if (num == -1)
            break;
        p->data = num;
        p->next = head;
        head = p;
    }
    return head;
}