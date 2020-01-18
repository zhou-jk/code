//HDU 2896
#include <cstdio>
#include <cstring>

const char FIRST_CH=' ',LAST_CH=126; //ACSII可见字符（不包含回车）
const int N_PAT=500,LEN_STR=10000,LEN_PAT=200,N_KIND_CH=LAST_CH-FIRST_CH+1;
char str[LEN_STR+1],pat[LEN_PAT+1];
bool vis[N_PAT+1];
int q[N_PAT*LEN_PAT+1],n_node=1;

struct Node
{
//public:
    inline void init()
    {
        k_end=fail=0;
        for (int i=0; i<N_KIND_CH; i++) k[i]=0;
    }
    /*friend void insert(const char *const str,const int id);
    friend void make_fail();
    friend int solve(const char *const str);*/
//private:
    int k_end,fail,k[N_KIND_CH];
} trie[N_PAT*LEN_PAT+1];

void insert(char * str,int id)
{
    int k1=0,k2;
    for (int i=0; str[i]; i++)
    {
        k2=str[i]-FIRST_CH;
        if (!trie[k1].k[k2])
        {
            trie[n_node].init();
            trie[k1].k[k2]=n_node++;
        }
        k1=trie[k1].k[k2];
    }
    trie[k1].k_end=id;
}

void make_fail()
{
    int k1,k2;
    q[0]=0;
    for (int l=0,r=1; l<r; l++)
    {
        k1=q[l];
        for (int i=0; i<N_KIND_CH; i++)
            if (trie[k1].k[i])
            {
                if (k1)
                {
                    k2=trie[k1].fail;
                    while (true)
                    {
                        //printf("%d\n",k2);
                        if (trie[k2].k[i])
                        {
                            trie[trie[k1].k[i]].fail=trie[k2].k[i];
                            //printf("%d %d\n",trie[k1].k[i],trie[k2].k[i]);
                            break;
                        }
                        if (!k2) break;
                        k2=trie[k2].fail;
                    }
                }
                q[r++]=trie[k1].k[i];
            }
    }
}

int solve(char * str)
{
    memset(vis,false,sizeof vis);
    int ret=0,k1=0,k2,k3;
    for (int i=0; str[i]; i++)
    {
        k3=str[i]-FIRST_CH;
        while (!trie[k1].k[k3]&&k1) k1=trie[k1].fail;
        k2=k1=trie[k1].k[k3];
        while (k2&&!vis[trie[k2].k_end])
        {
            //printf("%d %d\n",i,k2);
            if (trie[k2].k_end)
            {
                ret++;
                vis[trie[k2].k_end]=true;
            }
            k2=trie[k2].fail;
        }
    }
    return ret;
}

int main()
{
    int n_pat,n_str,ans=0;
    scanf("%d%*c",&n_pat);
    trie[0].init();
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