#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
int T;
int n;
int a[N];
long long f[N][N][2];
long long dfs(int l,int r,int k)
{
    if(l==r) return f[l][r][k]=1;
    if(f[l][r][k]!=-1) return f[l][r][k];
    if(k==0)
    {
        if(dfs(l+1,r,k^1)>a[r]) f[l][r][k]=1;
        else f[l][r][k]=a[r]-dfs(l+1,r,k^1)+dfs(l,r-1,k)+1;
    }
    else
    {
        if(dfs(l,r-1,k^1)>a[l]) f[l][r][k]=1;
        else f[l][r][k]=a[l]-dfs(l,r-1,k^1)+dfs(l+1,r,k)+1;
    }
    return f[l][r][k];
}
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(f,-1,sizeof(f));
    if(dfs(1,n,0)<=a[1]) printf("First\n");
    else printf("Second\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}