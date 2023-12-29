#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005,M=21;
int n,m,q;
int a[N];
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
            int sumf=0;
            long long sumg=0;
            for(int i=1;i<=n;i++)
                if(!((a[i]>>p)&1))
                    if((a[i]&ans)==ans) sumf++,sumg+=a[i]&((1<<p)-1);
            long long kk=x*(1ll<<p)+sumf*(1ll<<p)-sumg;
            if(k>=kk) k-=kk,x+=sumf,ans+=1<<p;
        }
        cout<<ans<<"\n";
    }
    return 0;
}