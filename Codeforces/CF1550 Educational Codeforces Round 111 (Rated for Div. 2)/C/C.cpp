#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
int a[N];
bool check(int l,int r)
{
    if(r-l+1<=2) return true;
    for(int i=l;i<=r;i++)
        for(int j=i+1;j<=r;j++)
            for(int k=j+1;k<=r;k++)
                if((a[i]<=a[j]&&a[j]<=a[k])||(a[i]>=a[j]&&a[j]>=a[k])) return false;
    return true;
}
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int k=1;k<=4&&i+k-1<=n;k++)
            if(check(i,i+k-1)) ans++;
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