#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int k=1;k<=n;k++)
        if(n%k==0)
        {
            int d=0;
            for(int j=1;j<=k;j++)
            {
                for(int i=j;i<=n;i+=k)
                {
                    d=gcd(d,abs(a[i]-a[j]));
                    if(d==1) break;
                }
                if(d==1) break;
            }
            if(d!=1) ans++;
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