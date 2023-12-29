#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1000005,M=21;
int n,m,q;
int a[N];
int f[M][1<<M];
long long g[M][1<<M];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    m=*max_element(a+1,a+n+1);
    m=ceil(log2(m))+1;
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    for(int p=0;p<m;p++)
    {
        for(int i=1;i<=n;i++)
            if(!((a[i]>>p)&1)) f[p][a[i]]++,g[p][a[i]]+=a[i]&((1<<p)-1);
        for(int j=0;j<m;j++)
            for(int i=(1<<m)-1;i>=0;i--)
                if(!((i>>j)&1))
                    f[p][i]+=f[p][i^(1<<j)],g[p][i]+=g[p][i^(1<<j)];
    }
    while(q--)
    {
        long long k;
        cin>>k;
        if(k>=(1ll<<m)*n-sum)
        {
            k-=((1ll<<m)*n-sum);
            long long ans=(1ll<<m)+k/n;
            cout<<ans<<"\n";
            continue;
        }
        int x=0;
        int ans=0;
        for(int p=m-1;p>=0;p--)
        {
            long long kk=x*(1ll<<p)+f[p][ans]*(1ll<<p)-g[p][ans];
            if(k>=kk) k-=kk,x+=f[p][ans],ans+=1<<p;
        }
        cout<<ans<<"\n";
    }
    return 0;
}