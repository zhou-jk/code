#include<iostream>
#include<cstdio>
using namespace std;
int n;
void solve()
{
    scanf("%d",&n);
    int ans=0;
    while(n>0)
        ans=max(ans,n%10),n/=10;
    printf("%d\n",ans);
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