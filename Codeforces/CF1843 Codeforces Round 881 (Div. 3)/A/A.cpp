#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n/2;i++)
        ans-=a[i];
    for(int i=(n+1)/2+1;i<=n;i++)
        ans+=a[i];
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