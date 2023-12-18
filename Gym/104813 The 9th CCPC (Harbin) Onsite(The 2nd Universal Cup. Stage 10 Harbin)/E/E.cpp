#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N],b[N],c[N];
int d[N];
long long sa,sb;
long long lim[N];
int id[N];
bool check(long long x)
{
    for(int i=1;i<=n;i++)
        lim[i]=x/c[i]-b[i]-sb;
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y)
    {
        if(d[x]<=0&&d[y]<=0) return lim[x]-d[x]>lim[y]-d[y];
        else if(d[x]>0&&d[y]>0) return lim[x]<lim[y];
        else return d[x]<d[y];
    });
    long long sd=0;
    for(int i=1;i<=n;i++)
    {
        sd+=d[id[i]];
        if(sd>lim[id[i]]) return false;
    }
    return true;
}
int ans[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++)
        d[i]=a[i]-b[i];
    sa=0,sb=0;
    for(int i=1;i<=n;i++)
        sa+=a[i],sb+=b[i];
    long long l=1,r=(long long)*max_element(c+1,c+n+1)*max(sa,sb)*2;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid))
        {
            for(int i=1;i<=n;i++)
                ans[i]=id[i];
            r=mid-1;
        }
        else l=mid+1;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0; 
}