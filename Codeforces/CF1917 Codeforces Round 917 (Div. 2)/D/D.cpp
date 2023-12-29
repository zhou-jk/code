#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
const int MOD=998244353;
int n,k;
int p[2*N],q[N];
struct BIT
{
    int n;
    int C[2*N];
    int lowbit(int x)
    {
        return x&-x;
    }
    void resize(int _n)
    {
        n=_n;
        for(int i=0;i<=n;i++)
            C[i]=0;
        return;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]=(C[i]+y)%MOD;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res=(res+C[i])%MOD;
        return res;
    }
    int query(int l,int r)
    {
        return (getsum(r)-getsum(l-1)+MOD)%MOD;
    }
}T;
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=k;i++)
    {
        cin>>q[i];
        q[i]++;
    }
    T.resize(k);
    int ans=0;
    for(int i=1;i<=k;i++)
        ans=(ans+T.query(q[i]+1,k))%MOD,T.add(q[i],1);
    ans=(long long)ans*n%MOD;
    T.resize(2*n-1);
    int cnt=0;
    for(int i=1;i<=n;i++)
        cnt=(cnt+T.query(p[i]+1,2*n-1))%MOD,T.add(p[i],1);
    cnt=(long long)cnt*k%MOD;
    ans=(ans+cnt)%MOD;
    T.resize(2*n-1);
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+ret)%MOD;
        ans=(ans+(long long)T.query(p[i]+1,2*n-1))%MOD;
        int l=-1;
        for(int j=1;j<=k;j++)
        {
            if(p[i]*(1<<j)>2*n-1)
            {
                l=j;
                break;
            }
            T.add(p[i]*(1<<j),k-j);
        }
        if(l!=-1) ret=(ret+(long long)(k-l+1)*(k-l)/2)%MOD;

    }
    T.resize(2*n-1);
    for(int i=n;i>=1;i--)
    {
        ans=(ans+(long long)T.query(1,p[i]-1))%MOD;
        for(int j=1;j<=k;j++)
        {
            if(p[i]*(1<<j)>2*n-1) break;
            T.add(p[i]*(1<<j),k-j);
        }
    }
    cout<<ans<<"\n";
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