#include<iostream>
#include<cstdio>
using namespace std;
const int N=201;
int n,s;
int w[N],v[N];
void init(int u)
{
    scanf("%d%d",&v[u],&w[u]);
    v[u]<<=1;
    if(w[u]==0) init(u*2),init(u*2+1);
    return;
}
int f[N][N<<2];
int dfs(int u,int k)
{
    if(f[u][k]||k==0) return f[u][k];
    if(w[u])
    {
        f[u][k]=min(w[u],(k-v[u])/5);
        return f[u][k];
    }
    for(int i=0;i<=k-v[u];i++)
        f[u][k]=max(f[u][k],dfs(u*2,i)+dfs(u*2+1,k-v[u]-i));
    return f[u][k];
}
int main()
{
    scanf("%d",&s);
    init(1);
    printf("%d",dfs(1,s-1));
    return 0;
}