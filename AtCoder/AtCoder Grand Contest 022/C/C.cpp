#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=55;
int n;
int a[N],b[N];
bool f[N][N];
vector<int>v;
int check(int m)
{
    memset(f,false,sizeof(f));
    for(int i=0;i<=50;i++)
    {
        f[i][i]=true;
        for(int j=0;j<=i;j++)
            for(int k=1;k<=m;k++)
                f[i][j]|=f[i%k][j];
        for(int j=0;j<=i;j++)
            for(int k:v)
                f[i][j]|=f[i%k][j];
    }
    for(int i=1;i<=n;i++)
        if(!f[a[i]][b[i]]) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    if(!check(50))
    {
        printf("-1");
        return 0;
    }
    for(int k=51;k>=1;k--)
        if(!check(k-1)) v.emplace_back(k);
    long long ans=0;
    for(int k:v)
        ans|=1LL<<k;
    printf("%lld",ans);
    return 0;
}