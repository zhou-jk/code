#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
const long long MOD=(1ll<<32);
int A,B,C,P;
inline int rnd(){return A=(A*B+C)%P;}
struct Edge
{
    int to,next;
}edge[N];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int n,m,q,type;
int pre[N];
int a[N];
int dfn[N],End[N],Index;
void dfs(int u)
{
    dfn[u]=++Index;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        dfs(v);
    }
    End[u]=++Index;
    return;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&q,&type);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        pre[i]=(a[i]&1)?i:pre[i-1];
    for(int i=1;i<=m;i++)
        if(a[i]&1) add_edge(0,i);
    for(int i=m+1;i<=n;i++)
        if(a[i]&1) add_edge(pre[i-m-1],i);
    dfs(0);
    if(type) scanf("%d%d%d%d",&A,&B,&C,&P);
    long long ans=0;
    for(int i=1;i<=q;i++)
    {
        int l,r;
        if(type)l=rnd()%n+1,r=rnd()%n+1;
        else scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        if(a[l]&1)
        {
            if(dfn[l]>dfn[pre[r]]||End[pre[r]]>End[l]) ans=(ans+(long long)i*i)%MOD;
        }
        else ans=(ans+(long long)i*i)%MOD;
    }
    printf("%lld",ans);
    return 0;
}