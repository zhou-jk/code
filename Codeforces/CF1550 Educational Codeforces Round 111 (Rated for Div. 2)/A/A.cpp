#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int S;
void solve()
{
    scanf("%d",&S);
    int sum=1,now=1;
    int ans=1;
    while(sum<S)
    {
        now+=2;
        sum+=now;
        ans++;
    }
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