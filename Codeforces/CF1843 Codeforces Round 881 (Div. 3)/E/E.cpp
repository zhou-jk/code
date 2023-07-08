#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,m,q;
int a[N],sum[N];
int l[N],r[N],u[N];
bool check(int x)
{
    for(int i=1;i<=n;i++)
        a[i]=0;
    for(int i=1;i<=x;i++)
        a[u[i]]=1;
    sum[0]=0;
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=m;i++)
        if(2*sum[r[i]]-r[i]>2*sum[l[i]-1]-(l[i]-1)) return true;
    return false;
}
void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&l[i],&r[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
        scanf("%d",&u[i]);
    int l=1,r=q,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
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