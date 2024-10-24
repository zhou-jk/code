#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005,K=11;
const int INF=1061109567;
int n,m,k;
vector<pair<int,int>>seg[N];
int f[N][K];
struct ST
{
    int n;
    int mx[N][18];
    void clear()
    {
        n=0;
        memset(mx[0],0,sizeof(mx[0]));
        return;
    }
    void push_back(int v)
    {
        n++;
        mx[n][0]=v;
        for(int j=1;n-(1<<j)+1>=0;j++)
            mx[n][j]=max(mx[n][j-1],mx[n-(1<<(j-1))][j-1]);
        return;
    }
    int query(int l,int r)
    {
        if(l>r) return -INF;
        int k=__lg(r-l+1);
        return max(mx[r][k],mx[l+(1<<k)-1][k]);
    }
}st[K];
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        seg[i].clear();
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        seg[l].emplace_back(l,1);
        if(r+1<=n) seg[r+1].emplace_back(l,-1);
    }
    for(int i=0;i<=k;i++)
    {
        st[i].clear();
        if(i>0)
            for(int j=0;(1<<j)<=n;j++)
                st[i].mx[0][j]=-INF;
    }
    multiset<int>s;
    for(int i=1;i<=n;i++)
    {
        for(auto [p,v]:seg[i])
            if(v>0) s.insert(p);
            else s.erase(s.lower_bound(p));
        if((int)s.size()>k)
        {
            for(int j=0;j<=k;j++)
            {
                f[i][j]=-INF;
                st[j].push_back(f[i][j]);
            }
        }
        else
        {
            vector<int>pos;
            for(int p:s)
                pos.emplace_back(p);
            for(int j=0;j<=k;j++)
            {
                f[i][j]=st[j].query(pos.empty()?0:pos.back(),i-1)+1;
                for(int l=0,r=0;l<(int)pos.size();l=r)
                {
                    while(r<(int)pos.size()&&pos[l]==pos[r]) r++;
                    int d=pos.size()-l;
                    if(j<d) continue;
                    f[i][j]=max(f[i][j],st[j-d].query(l==0?0:pos[l-1],pos[l]-1)+1);
                }
                st[j].push_back(f[i][j]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=k;i++)
        ans=max(ans,st[i].query(1,n));
    cout<<ans<<"\n";
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
