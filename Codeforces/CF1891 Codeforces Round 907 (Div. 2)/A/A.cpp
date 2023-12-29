#include<iostream>
#include<cstdio>
using namespace std;
const int N=25;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int j=1;(1<<(j-1))<=n;j++)
        for(int i=(1<<(j-1))+1;i+1<=min((1<<j),n);i++)
            if(a[i]>a[i+1])
            {
                cout<<"NO\n";
                return;
            }
    cout<<"YES\n";
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