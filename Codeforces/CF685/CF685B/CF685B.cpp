#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=300001;
vector<int>son[N];
int n,m;
int size[N],fa[N];
int sum[N],ans[N];
void init(int u)
{
    size[u]++;
    for(int i=0;i<son[u].size();i++)
    {
        int v=son[u][i];
        init(v);
        size[u]+=size[v];
        sum[u]=max(sum[u],size[v]);
    }
    return;
}
void dfs(int u)
{
    ans[u]=u;
    for(int i=0;i<son[u].size();i++)
    {
        int v=son[u][i];
        dfs(v);
        for(int j=ans[v],now=sum[u];j!=u;j=fa[j])
        {
            if(max(sum[j],size[u]-size[j])<now) now=max(sum[j],size[u]-size[j]),ans[u]=j;
            if(sum[j]>size[u]-size[j]) break;
        }
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&fa[i]);
        son[fa[i]].push_back(i);
    }
    init(1);
    dfs(1);
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
    return 0;
}