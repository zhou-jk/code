#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int T;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    if(sum%n!=0)
    {
        printf("-1\n");
        return;
    }
    int v=sum/n;
    int ans=0;
    for(int i=1;i<=n;i++)
        if(a[i]>v) ans++;
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