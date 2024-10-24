#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=300005;
int n;
int a[N],d[N];
int pre[N],suf[N];
bool vis[N];
void del(int x)
{
    suf[pre[x]]=suf[x];
    pre[suf[x]]=pre[x];
    vis[x]=true;
    return;
}
int res[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>d[i];
    a[0]=a[n+1]=0;
    for(int i=1;i<=n;i++)
        pre[i]=i-1,suf[i]=i+1,vis[i]=false;
    vector<int>pos(n);
    iota(pos.begin(),pos.end(),1);
    for(int t=1;t<=n;t++)
    {
        vector<int>cur,np;
        for(int u:pos)
            if(a[pre[u]]+a[suf[u]]>d[u])
            {
                cur.emplace_back(u);
                if(pre[u]>=1) np.emplace_back(pre[u]);
                if(suf[u]<=n) np.emplace_back(suf[u]);
            }
        sort(np.begin(),np.end());
        np.erase(unique(np.begin(),np.end()),np.end());
        res[t]=cur.size();
        for(int u:cur)
            del(u);
        pos.clear();
        for(int u:np)
            if(!vis[u]) pos.emplace_back(u);
    }
    for(int i=1;i<=n;i++)
        cout<<res[i]<<" ";
    cout<<"\n";
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