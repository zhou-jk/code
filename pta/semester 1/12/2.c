#include <stdio.h>
#include <stdlib.h>

struct stud_node *createlist()
{
    struct stud_node *head = NULL, *tail = NULL;
    while (1)
    {
        int num;
        scanf("%d", &num);
        if (num == 0)
            break;
        struct stud_node *p = (struct stud_node *)malloc(sizeof(struct stud_node));
        p->num = num;
        scanf("%s%d", p->name, &p->score);
        if (tail != NULL)
            tail->next = p;
        else
            head = p;
        tail = p;
        tail->next = NULL;
    }
    return head;
}

struct stud_node *deletelist(struct stud_node *head, int min_score)
{
    struct stud_node *pp = NULL;
    for (struct stud_node *p = head, *np; p != NULL; p = np)
    {
        np = p->next;
        if(p->score<min_score)
        {
            if (p == head)
                head = p->next;
            else
                pp->next = p->next;
        }
        else pp = p;
    }
    return head;
}