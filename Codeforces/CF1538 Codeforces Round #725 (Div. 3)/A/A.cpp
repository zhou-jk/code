#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int T;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=min_element(a+1,a+n+1)-a,r=max_element(a+1,a+n+1)-a;
    if(l>r) swap(l,r);
    int ans=min({r,n-l+1,l+n-r+1});
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