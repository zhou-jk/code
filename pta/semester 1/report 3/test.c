#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mAnalysis.h"

#define malloc smalloc
#define free sfree

struct Triple
{
    int x, y;
    int val;
};

struct Node
{
    struct Triple position;
    struct Node *down, *right;
};

struct Line
{
    struct Node *head, *tail;
};

struct Matrix
{
    int n, m;
    struct Line *row, *column;
};

int cmp(const void *a, const void *b)
{
    if (((struct Triple *)a)->x != ((struct Triple *)b)->x)
        return (((struct Triple *)a)->x - ((struct Triple *)b)->x);
    else
        return (((struct Triple *)a)->y - ((struct Triple *)b)->y);
}

struct Matrix init_zero_matrix(const int n, const int m)
{
    struct Matrix mat;
    mat.n = n, mat.m = m;
    mat.row = (struct Line *)malloc(sizeof(struct Line) * n);
    mat.column = (struct Line *)malloc(sizeof(struct Line) * m);
    for (int i = 0; i < n; i++)
        mat.row[i].head = mat.row[i].tail = NULL;
    for (int i = 0; i < m; i++)
        mat.column[i].head = mat.column[i].tail = NULL;
    return mat;
}

void destroy_matrix(struct Matrix *mat)
{
    for (int i = 0; i < mat->n; i++)
        for (struct Node *p = mat->row[i].head, *np; p != NULL; p = np)
        {
            np = p->right;
            free(p);
        }
    free(mat->row);
    free(mat->column);
    return;
}

struct Matrix create_matrix(const struct Triple a[], const int size, const int n, const int m)
{
    if (n <= 0 || m <= 0)
    {
        fprintf(stderr, "The number of rows and columns must be greater than 0");
        exit(EXIT_FAILURE);
    }
    struct Triple *b = (struct Triple *)malloc(sizeof(struct Triple) * size);
    for (int i = 0; i < size; i++)
        b[i].x = a[i].x - 1, b[i].y = a[i].y - 1, b[i].val = a[i].val;
    for (int i = 0; i < size; i++)
    {
        if (b[i].x < 0 || b[i].x >= n || b[i].y < 0 || b[i].y >= m)
        {
            fprintf(stderr, "Illegal element");
            free(b);
            exit(EXIT_FAILURE);
        }
        if (i > 1 && b[i].x == b[i - 1].x && b[i].y == b[i - 1].y)
        {
            fprintf(stderr, "Duplicate nodes");
            free(b);
            exit(EXIT_FAILURE);
        }
    }
    qsort(b, size, sizeof(struct Triple), cmp);
    struct Matrix mat = init_zero_matrix(n, m);
    for (int i = 0; i < size; i++)
    {
        if (b[i].val == 0)
            continue;
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->position = b[i];
        p->down = p->right = NULL;
        if (mat.row[b[i].x].tail == NULL)
            mat.row[b[i].x].head = mat.row[b[i].x].tail = p;
        else
            mat.row[b[i].x].tail->right = p;
        mat.row[b[i].x].tail = p;
        if (mat.column[b[i].y].tail == NULL)
            mat.column[b[i].y].head = mat.column[b[i].y].tail = p;
        else
            mat.column[b[i].y].tail->down = p;
        mat.column[b[i].y].tail = p;
    }
    free(b);
    return mat;
}

void print_matrix(const struct Matrix mat)
{
    for (int i = 0; i < mat.n; i++)
        for (struct Node *p = mat.row[i].head; p != NULL; p = p->right)
            printf("(%d,%d,%d)\n", p->position.x + 1, p->position.y + 1, p->position.val);
    return;
}

void print_complete_matrix(const struct Matrix mat)
{
    for (int i = 0; i < mat.n; i++)
    {
        if (mat.row[i].head == NULL)
        {
            for (int j = 0; j < mat.m; j++)
            {
                printf("0");
                if (j + 1 < mat.m)
                    printf(" ");
                else
                    printf("\n");
            }
        }
        else
        {
            if (0 < mat.row[i].head->position.y)
            {
                for (int j = 0; j <= mat.row[i].head->position.y - 1; j++)
                    printf("0 ");
            }
            for (struct Node *p = mat.row[i].head; p != NULL; p = p->right)
            {
                struct Node *np = p->right;
                printf("%d", p->position.val);
                if (p->position.y == mat.m - 1)
                    printf("\n");
                else
                    printf(" ");
                if (np != NULL)
                {
                    for (int j = p->position.y + 1; j <= np->position.y - 1; j++)
                        printf("0 ");
                }
                else
                {
                    for (int j = p->position.y + 1; j < mat.m; j++)
                    {
                        printf("0");
                        if (j + 1 < mat.m)
                            printf(" ");
                        else
                            printf("\n");
                    }
                }
            }
        }
    }
    return;
}

struct Matrix add(const struct Matrix a, const struct Matrix b)
{
    if (a.n != b.n || a.m != b.m)
    {
        fprintf(stderr, "The two matrices being added must have the same number of rows and columns");
        exit(EXIT_FAILURE);
    }
    struct Matrix c = init_zero_matrix(a.n, a.m);
    for (int i = 0; i < a.n; i++)
    {
        struct Node *l = a.row[i].head, *r = b.row[i].head;
        while (l != NULL || r != NULL)
        {
            struct Node *p = (struct Node *)malloc(sizeof(struct Node));
            p->down = p->right = NULL;
            if (r == NULL || l->position.y < r->position.y)
                p->position.x = l->position.x, p->position.y = l->position.y, p->position.val = l->position.val, l = l->right;
            else if (l == NULL || l->position.y > r->position.y)
                p->position.x = r->position.x, p->position.y = r->position.y, p->position.val = r->position.val, r = r->right;
            else
                p->position.x = l->position.x, p->position.y = r->position.y, p->position.val = l->position.val + r->position.val, l = l->right, r = r->right;
            if (p->position.val == 0)
            {
                free(p);
                continue;
            }
            if (c.row[p->position.x].tail == NULL)
                c.row[p->position.x].head = c.row[p->position.x].tail = p;
            else
                c.row[p->position.x].tail->right = p;
            c.row[p->position.x].tail = p;
            if (c.column[p->position.y].tail == NULL)
                c.column[p->position.y].head = c.column[p->position.y].tail = p;
            else
                c.column[p->position.y].tail->down = p;
            c.column[p->position.y].tail = p;
        }
    }
    return c;
}

struct Matrix minus(const struct Matrix a, const struct Matrix b)
{
    if (a.n != b.n || a.m != b.m)
    {
        fprintf(stderr, "The two matrices being minused must have the same number of rows and columns");
        exit(EXIT_FAILURE);
    }
    struct Matrix c = init_zero_matrix(a.n, a.m);
    for (int i = 0; i < a.n; i++)
    {
        struct Node *l = a.row[i].head, *r = b.row[i].head;
        while (l != NULL || r != NULL)
        {
            struct Node *p = (struct Node *)malloc(sizeof(struct Node));
            p->down = p->right = NULL;
            if (r == NULL || l->position.y < r->position.y)
                p->position.x = l->position.x, p->position.y = l->position.y, p->position.val = l->position.val, l = l->right;
            else if (l == NULL || l->position.y > r->position.y)
                p->position.x = r->position.x, p->position.y = r->position.y, p->position.val = -r->position.val, r = r->right;
            else
                p->position.x = l->position.x, p->position.y = r->position.y, p->position.val = l->position.val - r->position.val, l = l->right, r = r->right;
            if (p->position.val == 0)
            {
                free(p);
                continue;
            }
            if (c.row[p->position.x].tail == NULL)
                c.row[p->position.x].head = c.row[p->position.x].tail = p;
            else
                c.row[p->position.x].tail->right = p;
            c.row[p->position.x].tail = p;
            if (c.column[p->position.y].tail == NULL)
                c.column[p->position.y].head = c.column[p->position.y].tail = p;
            else
                c.column[p->position.y].tail->down = p;
            c.column[p->position.y].tail = p;
        }
    }
    return c;
}

struct Matrix multiply(const struct Matrix a, const struct Matrix b)
{
    if (a.m != b.n)
    {
        fprintf(stderr, "The number of columns in the first matrix is not equal to the number of rows in the second matrix");
        exit(EXIT_FAILURE);
    }
    struct Matrix c = init_zero_matrix(a.n, b.m);
    for (int i = 0; i < a.n; i++)
        for (struct Node *pa = a.row[i].head; pa != NULL; pa = pa->right)
        {
            int k = pa->position.y;
            for (struct Node *pb = b.row[k].head; pb != NULL; pb = pb->right)
            {
                int j = pb->position.y;
                if (c.column[j].tail != NULL && c.column[j].tail->position.x == i)
                    c.column[j].tail->position.val += pa->position.val * pb->position.val;
                else
                {
                    struct Node *pc = (struct Node *)malloc(sizeof(struct Node));
                    pc->down = pc->right = NULL;
                    pc->position.x = i, pc->position.y = j, pc->position.val = pa->position.val * pb->position.val;
                    if (pc->position.val == 0)
                    {
                        free(pc);
                        continue;
                    }
                    if (c.column[pc->position.y].tail == NULL)
                        c.column[pc->position.y].head = c.column[pc->position.y].tail = pc;
                    else
                        c.column[pc->position.y].tail->down = pc;
                    c.column[pc->position.y].tail = pc;
                }
            }
        }
    for (int j = 0; j < b.m; j++)
    {
        while (c.column[j].head != NULL && c.column[j].head->position.val == 0)
        {
            struct Node *np = c.column[j].head->down;
            free(c.column[j].head);
            c.column[j].head = np;
        }
        for (struct Node *p = c.column[j].head; p != NULL; p = p->down)
        {
            for (struct Node *np = p->down; np != NULL && np->position.val == 0; np = p->down)
            {
                p->down = np->down;
                free(np);
            }
        }
        for (struct Node *p = c.column[j].head; p != NULL; p = p->down)
        {
            if (c.row[p->position.x].tail == NULL)
                c.row[p->position.x].head = c.row[p->position.x].tail = p;
            else
                c.row[p->position.x].tail->right = p;
            c.row[p->position.x].tail = p;
        }
    }
    return c;
}

struct Matrix transpose(const struct Matrix a)
{
    struct Matrix t = init_zero_matrix(a.m, a.n);
    for (int i = 0; i < a.n; i++)
        for (struct Node *p = a.row[i].head; p != NULL; p = p->right)
        {
            struct Node *q = (struct Node *)malloc(sizeof(struct Node));
            q->down = q->right = NULL;
            q->position.x = p->position.y, q->position.y = p->position.x, q->position.val = p->position.val;
            if (t.row[q->position.x].tail == NULL)
                t.row[q->position.x].head = t.row[q->position.x].tail = q;
            else
                t.row[q->position.x].tail->right = q;
            t.row[q->position.x].tail = q;
            if (t.column[q->position.y].tail == NULL)
                t.column[q->position.y].head = t.column[q->position.y].tail = q;
            else
                t.column[q->position.y].tail->down = q;
            t.column[q->position.y].tail = q;
        }
    return t;
}

int main()
{
    int n, p, m;
    scanf("%d%d%d", &n, &p, &m);
    struct Triple a[n * p], b[p * m];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            int val;
            scanf("%d", &val);
            a[(i - 1) * p + j - 1] = (struct Triple){i, j, val};
        }
    }

    for (int i = 1; i <= p; i++)
        for (int j = 1; j <= m; j++)
        {
            int val;
            scanf("%d", &val);
            b[(i - 1) * m + j - 1] = (struct Triple){i, j, val};
        }

    struct Matrix A = create_matrix(a, n * p, n, p), B = create_matrix(b, p * m, p, m);
    struct Matrix C = multiply(A, B);
    print_complete_matrix(C);
    destroy_matrix(&A);
    destroy_matrix(&B);
    destroy_matrix(&C);
    return 0;
}