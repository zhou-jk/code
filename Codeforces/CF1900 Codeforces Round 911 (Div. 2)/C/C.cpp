#include<iostream>
#include<cstdio>
using namespace std;
const int N=300005;
const int INF=1e9;
int n;
char s[N];
int ls[N],rs[N];
int f[N];
void dfs(int u)
{
    if(!ls[u]&&!rs[u])
    {
        f[u]=0;
        return;
    }
    f[u]=INF;
    if(ls[u])
    {
        dfs(ls[u]);
        f[u]=min(f[u],f[ls[u]]+(s[u]!='L'));
    }
    if(rs[u])
    {
        dfs(rs[u]);
        f[u]=min(f[u],f[rs[u]]+(s[u]!='R'));
    }
    return;
}
void solve()
{
    cin>>n;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++)
        s[i]=str[i-1];
    for(int i=1;i<=n;i++)
        cin>>ls[i]>>rs[i];
    dfs(1);
    cout<<f[1]<<"\n";
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