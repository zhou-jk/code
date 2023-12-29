#include<iostream>
#include<cstdio>
#include<numeric>
using namespace std;
const int N=200005;
int n;
long long k;
long long a[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        a[i]-=k;
    bool allsame=true;
    for(int i=1;i<=n;i++)
        if(a[i]!=a[1])
        {
            allsame=false;
            break;
        }
    if(allsame)
    {
        cout<<0<<"\n";
        return;
    }
    long long g=0;
    bool pos=false,neg=false;
    for(int i=1;i<=n;i++)
        if(a[i]>0) pos=true,g=gcd(g,a[i]);
        else if(a[i]<0) neg=true,g=gcd(g,-a[i]);
        else
        {
            cout<<-1<<"\n";
            return;
        }
    if(pos&&neg)
    {
        cout<<-1<<"\n";
        return;
    }
    if(neg) g=-g;
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=a[i]/g-1;
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