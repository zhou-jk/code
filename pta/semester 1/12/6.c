#include <stdio.h>

struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *head = NULL, *tail = NULL;
    while (list1 != NULL && list2 != NULL)
    {
        struct ListNode *p;
        if (list1->data < list2->data)
            p = list1, list1 = list1->next;
        else
            p = list2, list2 = list2->next;
        if (head == NULL)
            head = p;
        else
            tail->next = p;
        tail = p, tail->next = NULL;
    }
    while (list1 != NULL)
    {
        struct ListNode *p = list1;
        list1 = list1->next;
        if (head == NULL)
            head = p;
        else
            tail->next = p;
        tail = p, tail->next = NULL;
    }
    while (list2 != NULL)
    {
        struct ListNode *p = list2;
        list2 = list2->next;
        if (head == NULL)
            head = p;
        else
            tail->next = p;
        tail = p, tail->next = NULL;
    }
    return head;
}