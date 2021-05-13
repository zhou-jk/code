#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int N=100005;
const int INF=1061109567;
int n;
int h[N];
int rt;
int ls[N],rs[N];
stack<int>s;
void insert(int i)
{
    int j=0;
    while(!s.empty()&&h[i]<h[s.top()]) j=s.top(),s.pop();
    if(s.empty()) rt=i;
    else rs[s.top()]=i;
    ls[i]=j;
    s.emplace(i);
    return;
}
int mx[N],mi[N];
void dfs(int u)
{
    if(ls[u]) dfs(ls[u]);
    if(rs[u]) dfs(rs[u]);
    mx[u]=max(u,max(mx[ls[u]],mx[rs[u]]));
    mi[u]=min(u,min(mi[ls[u]],mi[rs[u]]));
    return;
}
int main()
{
    mx[0]=-INF,mi[0]=INF;
    while(true)
    {
        scanf("%d",&n);
        if(n==0) return 0;
        for(int i=1;i<=n;i++)
            ls[i]=rs[i]=0;
        while(!s.empty()) s.pop();
        rt=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&h[i]);
        for(int i=1;i<=n;i++)
            insert(i);
        dfs(rt);
        long long ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,1LL*(mx[i]-mi[i]+1)*h[i]);
        printf("%lld\n",ans);
    }
    return 0;
}