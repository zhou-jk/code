#include <stdio.h>
#include <stdlib.h>

void input()
{
    while (1)
    {
        struct stud_node *p;
        int num;
        scanf("%d", &num);
        if (num == 0)
            break;
        p = (struct stud_node *)malloc(sizeof(struct stud_node));
        p->num = num;
        scanf("%s%d", p->name, &p->score);
        if (tail != NULL)
            tail->next = p;
        else
            head = p;
        tail = p;
        tail->next = NULL;
    }
    return;
}
