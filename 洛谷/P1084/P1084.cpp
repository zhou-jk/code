#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1061109567;
struct Edge
{
    int to,val,next;
}edge[100001];
int head[50001],cnt;
int n,m;
bool vis[50001];
int cnt1,cnt2;
int pos[50001],f[50001][16],dep[50001];
long long d[50001][16];
struct Node
{
    int pos;
    long long val;
}a[50001],b[50001];
bool cmp(Node x,Node y)
{
    return x.val<y.val;
}
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void dfs(int u,int father)
{
    f[u][0]=father;
    dep[u]=dep[father]+1;
    for(int i=1;(1<<i)<=n;i++)
        f[u][i]=f[f[u][i-1]][i-1],d[u][i]=d[u][i-1]+d[f[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        d[v][0]=edge[i].val;
        dfs(v,u);
    }
    return;
}
bool find(int u,int father)
{
    bool f1=0,f2=0;
    if(vis[u]) return true;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        f2=true;
        if(!find(v,u))
        {
            f1=true;
            if(u==1) b[++cnt2]=(Node){v,edge[i].val};
            else return false;
        }
    }
    return f2?(!f1):false;
}
bool check(long long x)
{
    cnt1=cnt2=0;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=m;i++)
    {
        int t=pos[i];
        long long sum=0;
        for(int j=log2(n);j>=0;j--)
            if(f[t][j]>1&&sum+d[t][j]<=x) sum+=d[t][j],t=f[t][j];
        if(f[t][0]==1&&sum+d[t][0]<=x) a[++cnt1]=(Node){t,x-sum-d[t][0]};
        else vis[t]=true;
    }
    if(find(1,0)) return true;
    int sum=1;
    memset(vis,0,sizeof(vis));
    sort(a+1,a+cnt1+1,cmp);
    sort(b+1,b+cnt2+1,cmp);
    for(int i=1;i<=cnt2;i++)
        vis[b[i].pos]=1;
    for(int i=1;i<=cnt1;i++)
    {
        if(vis[a[i].pos]) vis[a[i].pos]=false;
        else
        {
            while(sum<=cnt2&&!vis[b[sum].pos]) sum++;
            if(sum>cnt2) return true;
            if(a[i].val>=b[sum].val) vis[b[sum].pos]=false,sum++;
            if(sum>cnt2) return true;
        }
    }
    while(sum<=cnt2&&!vis[b[sum].pos]) sum++;
    return sum>cnt2;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    dfs(1,0);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&pos[i]);
    long long l=0,r=INF,ans=-1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%lld",ans);
    return 0;
}