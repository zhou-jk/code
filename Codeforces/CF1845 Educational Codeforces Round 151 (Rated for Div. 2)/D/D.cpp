#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=300005;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    long long sum=0,f=0,mx=0;
    long long pre=0,k=0;
    for(int i=1;i<=n;i++)
    {
        if(f>0) f+=-a[i];
        else pre=sum,f=-a[i];
        if(f>mx) mx=f,k=pre;
        sum+=a[i];
    }
    printf("%lld\n",k);
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