#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
const long long INF=2e18;
int n,q;
int b[N],x[N];
long long c[N];
long long k[N];
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i]>>x[i];
        if(b[i]==1) c[i]=min(c[i-1]+1,INF);
        else if(b[i]==2) c[i]=min<__int128>((__int128)c[i-1]*(x[i]+1),INF);
    }
    for(int i=1;i<=q;i++)
        cin>>k[i];
    for(int i=1;i<=q;i++)
    {
        int ans=0;
        while(true)
        {
            int p=lower_bound(c+1,c+n+1,k[i])-c;
            if(b[p]==1)
            {
                ans=x[p];
                break;
            }
            else if(b[p]==2)
            {
                k[i]=(k[i]-1)%c[p-1]+1;
            }
        }
        cout<<ans<<" ";
    }
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