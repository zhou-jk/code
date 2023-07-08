#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    long long ans=0;
    int cnt=0;
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)
        {
            ans+=a[i];
            flag=false;
        }
        else if(a[i]<0)
        {
            ans+=-a[i];
            if(!flag) cnt++,flag=true;
        }
    }
    printf("%lld %d\n",ans,cnt);
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