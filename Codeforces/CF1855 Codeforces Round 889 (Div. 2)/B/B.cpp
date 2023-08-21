#include<iostream>
#include<cstdio>
using namespace std;
long long n;
void solve()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        if(n%i!=0)
        {
            printf("%d\n",i-1);
            return;
        }
    printf("%lld\n",n);
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