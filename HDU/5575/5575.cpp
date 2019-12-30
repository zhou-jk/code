#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
const int N=200005;
__gnu_pbds::priority_queue<pair<int,int>,greater<pair<int,int> > >q[N];
int T,n,m;
pair<int,int> a[N];
int fa[N];
int dp[N][2];
int getf(int v)
{
    if(v==fa[v]) return v;
    fa[v]=getf(fa[v]);
    return fa[v];
}
int solve(int u,int val)
{
    int res=dp[u][1];
    while(!q[u].empty())
    {
        pair<int,int> p=q[u].top();
        if(p.first>val) break;
        res+=p.second;
        dp[u][0]=max(dp[u][0],res);
        q[u].pop();
    }
    return res;
}
int main()
{
    int Case=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<n;i++)
        {
            scanf("%d",&a[i].first);
            a[i].second=i;
        }
        for(int i=1;i<=n;i++)
            fa[i]=i;
        sort(a+1,a+n);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++)
        {
            int id,h,op;
            scanf("%d%d%d",&id,&h,&op);
            q[id].push(pair<int,int>(h+1,op==1?1:-1));
            if(!op)dp[id][0]++,dp[id][1]++;
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int f1=getf(a[i].second),f2=getf(a[i].second+1);
            dp[f2][1]=solve(f1,a[i].first)+solve(f2,a[i].first);
            dp[f2][0]=dp[f1][0]+dp[f2][0];
            fa[f1]=f2;
            q[f2].join(q[f1]);
        }
        int u=getf(1);
        dp[u][1]=solve(u,1000000000);
        printf("Case #%d: %d\n",++Case,max(dp[u][0],dp[u][1]));
    }
    return 0;
}