#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2005;
int T;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    static int b[N];
    int tot=0;
    for(int i=1;i<=n;i++)
        if(a[i]%2==0) b[++tot]=a[i];
    for(int i=1;i<=n;i++)
        if(a[i]%2==1) b[++tot]=a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(__gcd(b[i],b[j]*2)>1) ans++;
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