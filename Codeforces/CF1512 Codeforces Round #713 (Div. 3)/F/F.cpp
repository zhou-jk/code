#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N=200005;
int T;
int n,c;
int a[N],b[N];
void solve()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
        scanf("%d",&b[i]);
    long long res=(c+a[1]-1)/a[1];
    long long t=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        res=min(res,(c-sum+a[i]-1)/a[i]+t);
        t+=max((b[i]-sum+a[i]-1)/a[i],0LL)+1;
        sum+=max((b[i]-sum+a[i]-1)/a[i],0LL)*a[i]-b[i];
    }
    printf("%lld\n",res);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}