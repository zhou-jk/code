#include<iostream>
#include<cstdio>
using namespace std;
const int N=505;
const int MOD=1000000007;
const int INV2=500000004;
int n,m;
int s[N];
int f[N][N];
int dfs(int l,int r)
{
    if(f[l][r]!=-1) return f[l][r];
    if(l==r) return f[l][r]=0;
    if(r==m+1) return f[l][r]=m+1-l;
    f[l][r]=((long long)(dfs(l+1,r)+1+dfs(l,r+1))*INV2)%MOD;
    return f[l][r];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    for(int i=1;i<=m+1;i++)
        for(int j=1;j<=m+1;j++)
            f[i][j]=-1;
    int ans=m+1-s[n];
    for(int i=1;i<n;i++)
        ans=(ans+dfs(s[i],s[i+1]))%MOD;
    printf("%d",ans);
    return 0;
}