#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n,l,t;
long long p;
bool check(int x)
{
    long long sum=(long long)(n-x)*l+(long long)min((n+6)/7,(n-x)*2)*t;
    return sum>=p;
}
void solve()
{
    scanf("%d%lld%d%d",&n,&p,&l,&t);
    int l=1,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
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