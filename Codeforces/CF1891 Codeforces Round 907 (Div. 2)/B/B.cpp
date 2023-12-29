#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n,q;
long long a[N];
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int lst=31;
    vector<int>p;
    while(q--)
    {
        int x;
        cin>>x;
        if(x<lst) p.emplace_back(x),lst=x;
    }
    for(int x:p)
        for(int i=1;i<=n;i++)
            if(a[i]%(1<<x)==0) a[i]+=(1<<(x-1));
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
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