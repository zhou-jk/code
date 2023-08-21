#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
int p[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
        if(p[i]==i) ans++;
    ans=(ans+1)/2;
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