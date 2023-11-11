#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N];
int c[30];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<30;i++)
        c[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=29;j>=0;j--)
            if((a[i]>>j)&1)
            {
                c[j]++;
                break;
            }
    int ans=*max_element(c,c+30);
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