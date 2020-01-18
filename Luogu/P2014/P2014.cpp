#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int>son[301];
int f[301][301],a[301];
int n,m;
void dfs(int u)
{
    f[u][0]=0;
    for(int i=0;i<son[u].size();i++)
    {
        int v=son[u][i];
        dfs(v);
        for(int j=m;j>=0;j--)
            for(int k=j;k>=0;k--)
                f[u][j]=max(f[u][j],f[u][j-k]+f[v][k]);
    }
    if(u!=0)
        for(int i=m;i>0;i--)
            f[u][i]=f[u][i-1]+a[u];
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(f,-63,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d%d",&x,&a[i]);
        son[x].push_back(i);
    }
    dfs(0);
    printf("%d",f[0][m]);
    return 0;
}