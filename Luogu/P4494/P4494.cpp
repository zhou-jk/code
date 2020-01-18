#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200001;
const int MOD=1000000007;
int T,n,m;
char s[N];
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}
struct Edge
{
    int to,next;
}edge[N<<1];
int head[N],cnt;
int in[N];
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dfn[N],low[N],Index;
bool book[N];
bool iscut[N];
int belong[N];
int num[N],root,color[N];
int size[N],siz[N];
void tarjan(int u,int father)
{
    dfn[u]=low[u]=++Index;
    belong[u]=root;
    book[u]=true;
    siz[u]=size[u];
    int flag=0;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        flag++;
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            size[u]+=size[v];
            if(low[v]>=dfn[u])
            {
                book[u]&=!(size[v]&1);
                num[u]++;
                iscut[u]=true;
                siz[u]+=size[v];
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
    if(father) num[u]++;
    if(!flag) iscut[u]=true;
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cnt=0;
        memset(head,0,sizeof(head));
        memset(size,0,sizeof(size));
        memset(in,0,sizeof(in));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(belong,0,sizeof(belong));
        memset(book,false,sizeof(book));
        memset(iscut,false,sizeof(iscut));
        memset(num,0,sizeof(num));
        memset(siz,0,sizeof(siz));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add_edge(x,y);
            add_edge(y,x);
            in[x]++,in[y]++;
        }
        scanf("%s",s+1);
        for(int i=1;i<=n;i++)
            size[i]=color[i]=s[i]-'0';
        int tot=0,res=0;
        for(int i=1;i<=n;i++)
            if(!dfn[i])
            {
                root=i;
                tarjan(i,0);
                tot++;
                res+=size[i]&1;
            }
        for(int i=1;i<=n;i++)
            book[i]&=!((size[belong[i]]-siz[i])&1);
        if(res) printf("0 ");
        else printf("%lld ",ksm(2,m-n+tot));
        for(int i=1;i<=n;i++)
        {
            if(!in[i]) printf("%lld ",res-size[i]?0:ksm(2,m-n+tot));
            else if(!iscut[i]) printf("%lld ",res-(size[belong[i]]&1)+((size[belong[i]]-color[i])&1)?0:ksm(2,m-in[i]-n+tot+1));
            else if(book[i]&&!(res-(size[belong[i]]&1))) printf("%lld ",ksm(2,m-in[i]-n+num[i]+tot));
            else printf("0 ");
        }
        printf("\n");
    }
    return 0;
}