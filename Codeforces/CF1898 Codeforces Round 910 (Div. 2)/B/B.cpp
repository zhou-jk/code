#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long cnt=0;
    for(int i=n-1;i>=1;i--)
        if(a[i]>a[i+1])
        {
            int x=(a[i]+a[i+1]-1)/a[i+1]-1;
            a[i]=a[i]/(x+1);
            cnt+=x;
        }
    cout<<cnt<<"\n";
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
