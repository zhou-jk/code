#include <cstdio>

class Node
{
public:
    Node()
    {
        n_end=0;
        fail=NULL;
        for (int i=0;i<N_KIND_CH;i++) p[i]=NULL;
    }
    ~Node()
    {
        for (int i=0;i<N_KIND_CH;i++)
            if (p[i]!=NULL) delete p[i];
    }
} *q[],*trie;

void insert(const char *const str)
{
    Node *p=trie;
    int k;
    for (int i=0;str[i];i++)
    {
        k=str[i]-FIRST_CH;
        if (p->p[k]==NULL) p->p[k]=new Node;
        p=p->p[k];
    }
}

int main()
{
    scanf("%d",&n_pat);
    for (int i=0;i<n_pat;i++)
    {
        scanf("%s",pat);
        insert(pat);
    }
    make_fail();
    scanf("%d",&n_str);
    for (int i=0;i<n_str;i++)
    {
        scanf("%s",str);
        printf("%d\n",solve(str));
    }
    return 0;
}