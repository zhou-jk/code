#include<iostream>
#include<cstdio>
#include<cassert>
#include<algorithm>
using namespace std;
const int N=200005;
int n,k,m,c,d;
int a[N];
int s[N];
bool check(long long x)
{
    for(int i=1;i<=n;i++)
        s[i]=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(a[i]>=x) cnt++;
        else
        {
            if(a[i]+c+(long long)d*(m-1)>=x)
            {
                if(d==0) s[max(i-m+1,1)]++,s[i+1]--;
                else
                {
                    long long t=max((x-a[i]-c+d-1)/d+1,1ll);
                    if(i-t+1>=1) s[max(i-m+1,1)]++,s[i-t+1+1]--;
                }
            }
        }
    for(int i=1;i<=n;i++)
        s[i]+=s[i-1];
    cnt+=*max_element(s+1,s+n+1);
    return cnt>=k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>k>>m>>c>>d;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long l=0,r=*max_element(a+1,a+n+1)+c+(long long)d*(m-1),ans=-1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}