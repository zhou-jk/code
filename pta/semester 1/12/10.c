#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *new_node(int x)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x, p->next = NULL;
    return p;
}
struct List
{
    struct Node *head, *tail;
};
void insert(struct List *l, struct Node *now, struct Node *p)
{
    if (now == l->tail)
        l->tail = p;
    p->next = now->next;
    now->next = p;
    return;
}
void init(struct List *l)
{
    l->head = l->tail = NULL;
    return;
}
void destroy(struct List l)
{
    for (struct Node *p = l.head, *np; p != NULL; p = np)
    {
        np = p->next;
        free(p);
    }
    return;
}
void solve()
{
    struct List lp, ln;
    init(&lp), init(&ln);
    int x;
    while (scanf("%d", &x) != EOF)
    {
        if (x > 0)
        {
            if (lp.head == NULL || x <= lp.head->data)
            {
                struct Node *p = new_node(x);
                p->next = lp.head;
                lp.head = p;
                if (lp.tail == NULL)
                    lp.tail = p;
            }
            else
                for (struct Node *p = lp.head; p != NULL; p = p->next)
                    if (p->next == NULL || x <= (p->next->data))
                    {
                        insert(&lp, p, new_node(x));
                        break;
                    }
        }
        else if (x < 0)
        {
            if (ln.head == NULL || x <= ln.head->data)
            {
                struct Node *p = new_node(x);
                p->next = ln.head;
                ln.head = p;
                if (ln.tail == NULL)
                    ln.tail = p;
            }
            else
                for (struct Node *p = ln.head; p != NULL; p = p->next)
                    if (p->next == NULL || x <= (p->next->data))
                    {
                        insert(&ln, p, new_node(x));
                        break;
                    }
        }
    }
    for (struct Node *p = lp.head; p != NULL; p = p->next)
    {
        if (p != lp.head)
            printf("->");
        printf("%d", p->data);
    }
    printf("\n");
    for (struct Node *p = ln.head; p != NULL; p = p->next)
    {
        if (p != ln.head)
            printf("->");
        printf("%d", p->data);
    }
    printf("\n");
    destroy(lp), destroy(ln);
    return;
}
int main()
{
    solve();
    return 0;
}