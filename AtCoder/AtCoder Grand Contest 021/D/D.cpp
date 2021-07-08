#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=305;
int n,k;
char s[N];
int f[N][N][N];
int dfs(int l,int r,int k)
{
    if(l==r) return f[l][r][k]=1;
    if(l+1==r)
    {
        if(s[l]==s[r]||k>=1) f[l][r][k]=2;
        else f[l][r][k]=1;
        return f[l][r][k];
    }
    if(f[l][r][k]!=-1) return f[l][r][k];
    f[l][r][k]=max(dfs(l+1,r,k),dfs(l,r-1,k));
    if(s[l]==s[r]) f[l][r][k]=max(f[l][r][k],dfs(l+1,r-1,k)+2);
    if(k>=1) f[l][r][k]=max(f[l][r][k],dfs(l+1,r-1,k-1)+2);
    return f[l][r][k];
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    scanf("%d",&k);
    memset(f,-1,sizeof(f));
    printf("%d",dfs(1,n,k));
    return 0;
}