#include<iostream>
#include<cstdio>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
const int N=500005;
const long long INF=4557430888798830399;
int n;
int a[N];
int st[N][20],lg2[N];
int query(int l,int r)
{
    int k=lg2[r-l+1];
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
vector<int>G[N];
int dfn[N],Index;
int mn[N][20];
int dep[N];
vector<int>b[N];
void dfs(int u,int father)
{
    dfn[u]=++Index;
    mn[Index][0]=father;
    dep[u]=dep[father]+1;
    b[dep[u]].emplace_back(u);
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int lca(int u,int v)
{
    if(u==v) return u;
    u=dfn[u],v=dfn[v];
    if(u>v) swap(u,v);
    u++;
    int d=lg2[v-u+1];
    if(dfn[mn[u][d]]<dfn[mn[v-(1<<d)+1][d]]) return mn[u][d];
    else return mn[v-(1<<d)+1][d];
}
vector<int>E[N];
void build(vector<int>h)
{
    sort(h.begin(),h.end(),[=](const int &x,const int &y){return dfn[x]<dfn[y];});
    static int s[N];
    int top=0;
    s[++top]=1;
    E[1].clear();
    for(int i=0;i<(int)h.size();i++)
        if(h[i]!=1)
        {
            int l=lca(h[i],s[top]);
            if(l!=s[top])
            {
                while(dfn[l]<dfn[s[top-1]])
                {
                    E[s[top]].emplace_back(s[top-1]),E[s[top-1]].emplace_back(s[top]);
                    top--;
                }
                if(dfn[l]>dfn[s[top-1]])
                {
                    E[l].clear();
                    E[l].emplace_back(s[top]),E[s[top]].emplace_back(l);
                    top--;
                    s[++top]=l;
                }
                else
                {
                    E[s[top-1]].emplace_back(s[top]),E[s[top]].emplace_back(s[top-1]);
                    top--;
                }
            }
            E[h[i]].clear();
            s[++top]=h[i];
        }
    for(int i=1;i<top;i++)
        E[s[i]].emplace_back(s[i+1]),E[s[i+1]].emplace_back(s[i]);
    return;
}
long long f[N];
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        G[i].clear(),b[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    Index=0;
    dfs(1,0);
    lg2[0]=-1;
    for(int i=1;i<=n;i++)
        lg2[i]=lg2[i/2]+1;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            if(dfn[mn[i][j-1]]<dfn[mn[i+(1<<(j-1))][j-1]]) mn[i][j]=mn[i][j-1];
            else mn[i][j]=mn[i+(1<<(j-1))][j-1];
    for(int i=0;i<n;i++)
        st[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    long long ans=0;
    for(int d=1;d<=n;d++)
        if(!b[d].empty())
        {
            build(b[d]);
            function<void(int,int)> solve=[&](int u,int father)
            {
                f[u]=(long long)query(d-dep[u],d-(dep[father]+1));
                long long sum=0;
                for(int v:E[u])
                {
                    if(v==father) continue;
                    solve(v,u);
                    sum+=f[v];
                }
                if(sum>0) f[u]=min(f[u],sum);
                return;
            };
            solve(1,0);
            ans+=f[1];
        }
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