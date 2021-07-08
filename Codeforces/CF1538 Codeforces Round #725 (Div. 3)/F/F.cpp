#include<iostream>
#include<cstdio>
using namespace std;
int T;
int l,r;
void solve()
{
    scanf("%d%d",&l,&r);
    int ans=0;
    for(long long i=1;i<=r;i*=10)
        ans+=r/i-l/i;
    printf("%d\n",ans);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}