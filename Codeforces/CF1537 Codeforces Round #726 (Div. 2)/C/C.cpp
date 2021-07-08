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
    sort(a+1,a+n+1);
    int v=a[n];
    for(int i=2;i<=n;i++)
        v=min(v,a[i]-a[i-1]);
    for(int i=2;i<=n;i++)
        if(a[i]-a[i-1]==v)
        {
            printf("%d ",a[i-1]);
            for(int j=i+1;j<=n;j++)
                printf("%d ",a[j]);
            for(int j=1;j<i-1;j++)
                printf("%d ",a[j]);
            printf("%d\n",a[i]);
            return;
        }
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}