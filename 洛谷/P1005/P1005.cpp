#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int a[81];
__int128 p[81],f[81][81];
__int128 ans;
__int128 dfs(int l,int r)
{
    if(f[l][r]!=-1) return f[l][r];
    if(r-l>=1) f[l][r]=max(a[l]*p[m-r+l]+dfs(l+1,r),dfs(l,r-1)+a[r]*p[m-r+l]);
    else f[l][r]=a[l]*p[m-r+l];
    return f[l][r];
}
void print(__int128 x)
{
    if(x<0) x=-x,putchar('-');
    if(x>=10) print(x/10);
    putchar(x%10+'0');
    return;
}

int main()
{
    scanf("%d%d",&n,&m);
    p[0]=1;
    for(int i=1;i<=m;i++)
        p[i]=p[i-1]*2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            scanf("%d",&a[j]);
        memset(f,-1,sizeof(f));
        ans+=dfs(1,m);
    }
    print(ans);
    return 0;
}