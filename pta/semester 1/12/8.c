#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};
int main()
{
    int n;
    scanf("%d", &n);
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &p->val);
        if (head == NULL)
            head = p;
        else
            tail->next = p;
        tail = p, tail->next = NULL;
    }
    struct Node *a = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &a->val);
    if (head == NULL)
        head = tail = a;
    else if ((a->val) < (head->val))
        a->next = head, head = a;
    else
    {
        if ((a->val) > (head->val))
            for (struct Node *p = head; p != NULL; p = p->next)
            {
                if (p->next == NULL || (a->val) < (p->next->val))
                {
                    a->next = p->next, p->next = a;
                    break;
                }
                else if ((a->val) == (p->next->val))
                    break;
            }
    }
    for (struct Node *p = head; p != NULL; p = p->next)
    {
        if (p != head)
            printf(" ");
        printf("%d", p->val);
    }
    return 0;
}