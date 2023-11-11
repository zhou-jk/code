#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N];
int b[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    deque<int>q;
    for(int i=1;i<=n;i++)
        if(i&1) q.emplace_back(a[i]);
        else q.emplace_front(a[i]);
    for(int i=1;i<=n;i++)
        b[i]=q.front(),q.pop_front();
    long long ans=(long long)b[1]*b[n];
    for(int i=2;i<=n;i++)
        ans+=(long long)b[i]*b[i-1];
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