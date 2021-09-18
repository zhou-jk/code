#include<iostream>
#include<cstdio>
using namespace std;
const int N=300005;
const int INF=1061109567;
int n,k;
int a[N],t[N];
int f[N];
void solve()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=k;i++)
        scanf("%d",&t[i]);
    fill(f+1,f+n+1,INF);
    for(int i=1;i<=k;i++)
        f[a[i]]=min(f[a[i]],t[i]);
    for(int i=2;i<=n;i++)
        f[i]=min(f[i],f[i-1]+1);
    for(int i=n-1;i>=1;i--)
        f[i]=min(f[i],f[i+1]+1);
    for(int i=1;i<=n;i++)
        printf("%d ",f[i]);
    printf("\n");
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}