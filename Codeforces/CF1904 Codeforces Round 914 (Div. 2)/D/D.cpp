#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N],b[N];
vector<int>pa[N],pb[N];
struct BIT
{
    int C[N];
    int lowbit(int x)
    {
        return x&-x;
    }
    void clear()
    {
        for(int i=1;i<=n;i++)
            C[i]=0;
        return;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=C[i];
        return res;
    }
    int query(int l,int r)
    {
        return getsum(r)-getsum(l-1);
    }
}T;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        pa[i].clear(),pb[i].clear();
    for(int i=1;i<=n;i++)
        pa[a[i]].emplace_back(i),pb[b[i]].emplace_back(i);
    T.clear();
    for(int i=1;i<=n;i++)
        T.add(i,1);
    for(int i=1;i<=n;i++)
    {
        for(int u:pa[i])
            T.add(u,-1);
        for(int u:pb[i])
        {
            if(a[u]>b[u])
            {
                cout<<"NO\n";
                return;
            }
            if(a[u]==b[u]) continue;
            int r=lower_bound(pa[i].begin(),pa[i].end(),u)-pa[i].begin();
            if(r<(int)pa[i].size()&&T.query(u,pa[i][r])==0) continue;
            if(r-1>=0&&T.query(pa[i][r-1],u)==0) continue;
            cout<<"NO\n";
            return;
        }
        for(int u:pb[i])
            T.add(u,1);
    }
    cout<<"YES\n";
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