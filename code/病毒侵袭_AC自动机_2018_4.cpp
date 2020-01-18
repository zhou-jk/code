//HDU 2896
#include <cstdio>
#include <cstring>
#include <queue>

using std::queue;

const char FIRST_CH=' ',LAST_CH=126; //ACSII可见字符（不包含回车）
const int N_PAT=500,LEN_STR=10000,LEN_PAT=200,N_KIND_CH=LAST_CH-FIRST_CH+1;
char str[LEN_STR+1],pat[LEN_PAT+1];
bool vis[N_PAT+1];

class Node
{
public:
    Node()
    {
        k_end=0;
        fail=NULL;
        for (int i=0; i<N_KIND_CH; i++) p[i]=NULL;
    }
    ~Node()
    {
        for (int i=0; i<N_KIND_CH; i++)
            if (p[i]!=NULL) delete p[i];
    }
    friend void insert(const char *const str,const int id);
    friend void make_fail();
    friend int solve(const char *const str);
private:
    int k_end;
    Node *fail,*p[N_KIND_CH];
} trie;

void insert(const char *const str,const int id)
{
    Node *p=&trie;
    int k;
    for (int i=0; str[i]; i++)
    {
        k=str[i]-FIRST_CH;
        if (p->p[k]==NULL) p->p[k]=new Node;
        p=p->p[k];
    }
    p->k_end=id;
}

void make_fail()
{
    queue<Node*> q;
    Node *p1,*p2;
    q.push(&trie);
    while (!q.empty())
    {
        p1=q.front(); q.pop();
        for (int i=0; i<N_KIND_CH; i++)
            if (p1->p[i]!=NULL)
            {
                if (p1==&trie) p1->p[i]->fail=&trie;
                else
                {
                    p2=p1->fail;
                    while (p2!=NULL)
                    {
                        if (p2->p[i]!=NULL)
                        {
                            p1->p[i]->fail=p2->p[i];
                            break;
                        }
                        p2=p2->fail;
                    }
                    if (p2==NULL) p1->p[i]->fail=&trie;
                }
                q.push(p1->p[i]);
            }
    }
}

int solve(const char *const str)
{
    memset(vis,false,sizeof vis);
    Node *p1=&trie,*p2;
    int ret=0,k;
    for (int i=0; str[i]; i++)
    {
        k=str[i]-FIRST_CH;
        while (p1->p[k]==NULL&&p1!=&trie) p1=p1->fail;
        p1=p1->p[k]==NULL?&trie:p1->p[k];
        p2=p1;
        while (p2!=&trie&&!vis[p2->k_end])
        {
            if (p2->k_end)
            {
                ret++;
                vis[p2->k_end]=true;
            }
            p2=p2->fail;
        }
    }
    return ret;
}

int main()
{
    int n_pat,n_str,ans=0;
    scanf("%d%*c",&n_pat);
    for (int i=0; i<n_pat; i++)
    {
        gets(pat);
        insert(pat,i+1);
    }
    make_fail();
    scanf("%d%*c",&n_str);
    for (int i=0; i<n_str; i++)
    {
        gets(str);
        if (solve(str))
        {
            ans++;
            printf("web %d:",i+1);
            for (int j=1; j<=n_pat; j++)
                if (vis[j]) printf(" %d",j);
            printf("\n");
        }
    }
    printf("total: %d\n",ans);
    return 0;
}