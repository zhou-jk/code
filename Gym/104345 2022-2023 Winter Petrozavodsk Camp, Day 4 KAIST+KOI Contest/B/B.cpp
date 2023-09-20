#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=250005;
int n,q;
int s[N],k;
vector<int>G[N];
int fa[N],dep[N];
bool book[N];
int siz[N];
void dfs(int u,int father)
{
    fa[u]=father;
    dep[u]=dep[father]+1;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs(1,0);
    cin>>q;
    while(q--)
    {
        cin>>k;
        for(int i=1;i<=k;i++)
            cin>>s[i]; 
        for(int i=1;i<=k;i++)
            book[s[i]]=true,siz[s[i]]=1;
        sort(s+1,s+k+1,[=](const int &x,const int &y){return dep[x]>dep[y];});
        long long ans=0;
        for(int i=1;i<=k;i++)
        {
            if(book[fa[s[i]]]) siz[fa[s[i]]]+=siz[s[i]];
            else ans+=(long long)(siz[s[i]]-1)*siz[s[i]]/2;
        }
        cout<<ans<<"\n";
        for(int i=1;i<=k;i++)
            book[s[i]]=false;
    }
    return 0;
}
