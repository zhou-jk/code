#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=500005;
int n;
int a[N*2],b[N*2];
int f[N*2][2],g[N*2][2];
void print(int i,int j,int k)
{
    if(i==0) return;
    int v=j==0?a[i]:b[i];
    if(j==0) k--;
    if(v>=a[i-1]&&f[i-1][0]<=k&&k<=g[i-1][0]) print(i-1,0,k);
    else if(v>=b[i-1]&&f[i-1][1]<=k&&k<=g[i-1][1]) print(i-1,1,k);
    else exit(1);
    if(j==0) printf("A");
    else printf("B");
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n*2;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n*2;i++)
        scanf("%d",&b[i]);
    memset(f,63,sizeof(f));
    memset(g,0,sizeof(g));
    f[0][0]=g[0][0]=0;
    for(int i=1;i<=n*2;i++)
    {
        if(a[i]>=a[i-1]) f[i][0]=min(f[i][0],f[i-1][0]+1),g[i][0]=max(g[i][0],g[i-1][0]+1);
        if(a[i]>=b[i-1]) f[i][0]=min(f[i][0],f[i-1][1]+1),g[i][0]=max(g[i][0],g[i-1][1]+1);
        if(b[i]>=a[i-1]) f[i][1]=min(f[i][1],f[i-1][0]),g[i][1]=max(g[i][1],g[i-1][0]);
        if(b[i]>=b[i-1]) f[i][1]=min(f[i][1],f[i-1][1]),g[i][1]=max(g[i][1],g[i-1][1]);
    }
    if(f[n*2][0]<=n&&n<=g[n*2][0]) print(n*2,0,n);
    else if(f[n*2][1]<=n&&n<=g[n*2][1]) print(n*2,1,n);
    else printf("-1");
    return 0;
}