#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int N=300005;
int T;
int n,k;
int a[N];
int pos[N];
int pre[N],nxt[N];
stack<int>s;
int rt;
int ls[N],rs[N];
void insert(int i)
{
    int j=0;
    while(!s.empty()&&a[i]>a[s.top()]) j=s.top(),s.pop();
    if(s.empty()) rt=i;
    else rs[s.top()]=i;
    ls[i]=j;
    s.emplace(i);
    return;
}
int l[N],r[N];
long long ans;
void dfs(int u)
{
    l[u]=r[u]=u;
    if(ls[u]) dfs(ls[u]),l[u]=l[ls[u]];
    if(rs[u]) dfs(rs[u]),r[u]=r[rs[u]];
    if(u-l[u]<r[u]-u)
    {
        for(int i=max(l[u],pre[u]);i<=u;i++)
        {
            int j=max(a[u]+i-1-k,u);
            ans+=max(min(r[u],nxt[i])-j+1,0);
        }
    }
    else
    {
        for(int i=u;i<=min(r[u],nxt[u]);i++)
        {
            int j=min(k-a[u]+i+1,u);
            ans+=max(j-max(l[u],pre[i])+1,0);
        }
    }
    return;
}
void solve()
{   
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        pos[i]=0;
    for(int i=1;i<=n;i++)
        pre[i]=pos[a[i]],pos[a[i]]=i;
    for(int i=1;i<=n;i++)
        pos[i]=n+1;
    for(int i=n;i>=1;i--)
        nxt[i]=pos[a[i]],pos[a[i]]=i;
    for(int i=2;i<=n;i++)
        pre[i]=max(pre[i-1],pre[i]);
    for(int i=n-1;i>=1;i--)
        nxt[i]=min(nxt[i+1],nxt[i]);
    for(int i=1;i<=n;i++)
        pre[i]++,nxt[i]--;
    while(!s.empty()) s.pop();
    rt=0;
    for(int i=1;i<=n;i++)
        ls[i]=rs[i]=0;
    for(int i=1;i<=n;i++)
        insert(i);
    ans=0;
    dfs(rt);
    printf("%lld\n",ans);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}