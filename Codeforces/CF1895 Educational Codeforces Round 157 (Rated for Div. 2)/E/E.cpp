#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=300005;
int n,m;
pair<int,int>a[N],b[N];
pair<int,int>sufa[N],sufb[N];
int toa[N],tob[N];
int to[N];
int ans[N];
int dfs(int u)
{
    if(ans[u]) return ans[u];
    ans[u]=2;
    ans[u]=dfs(to[u]);
    return ans[u]; 
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first;
    for(int i=1;i<=n;i++)
        cin>>a[i].second;
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>b[i].first;
    for(int i=1;i<=m;i++)
        cin>>b[i].second;
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    sufa[n+1]={0,0};
    for(int i=n;i>=1;i--)
        sufa[i]=max(sufa[i+1],{a[i].second,i});
    sufb[m+1]={0,0};
    for(int i=m;i>=1;i--)
        sufb[i]=max(sufb[i+1],{b[i].second,i});
    for(int i=1;i<=m;i++)
    {
        int p=lower_bound(a+1,a+n+1,make_pair(b[i].second+1,0))-a;
        if(p>n) tob[i]=0;
        else tob[i]=sufa[p].second;
    }
    for(int i=1;i<=n;i++)
    {
        int p=lower_bound(b+1,b+m+1,make_pair(a[i].second+1,0))-b;
        if(p>m) toa[i]=0;
        else toa[i]=sufb[p].second;
    }
    for(int u=1;u<=n;u++)
    {
        if(!toa[u]) to[u]=0,ans[u]=1;
        else if(!tob[toa[u]]) to[u]=0,ans[u]=3;
        else to[u]=tob[toa[u]],ans[u]=0;
    }
    for(int i=1;i<=n;i++)
        if(!ans[i]) dfs(i);
    int res[4]={};
    for(int i=1;i<=n;i++)
        res[ans[i]]++;
    cout<<res[1]<<" "<<res[2]<<" "<<res[3]<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}