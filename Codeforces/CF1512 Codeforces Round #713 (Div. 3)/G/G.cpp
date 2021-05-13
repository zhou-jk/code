#include<iostream>
#include<cstdio>
using namespace std;
const int N=10000005;
int T;
int n;
long long d[N];
int c[N];
void init(int n=10000000)
{
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            d[j]+=i;
    for(int i=1;i<=n;i++)
        c[i]=-1;
    for(int i=n;i>=1;i--)
        if(d[i]<=n) c[d[i]]=i;
    return;
}
void solve()
{
    scanf("%d",&n);
    printf("%d\n",c[n]);
    return;
}
int main()
{
    init();
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}