#include<iostream>
#include<cstdio>
#include<vector>
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
    int mn=*min_element(a+1,a+n+1),mx=*max_element(a+1,a+n+1);
    if(mn==mx)
    {
        cout<<0<<"\n";
        return;
    }
    vector<int>res;
    while(mn!=mx)
    {
        int x=0;
        if(mn%2==1)
        {
            if(mx%2==1) x=0;
            else x=1;
        }
        else
        {
            if(mx%2==1) x=0;
            else x=1;
        }
        res.emplace_back(x);
        mn=(mn+x)/2,mx=(mx+x)/2;
    }
    int m=res.size();
    cout<<m<<"\n";
    if(m<=n)
    {
        for(int x:res)
            cout<<x<<" ";
        cout<<"\n";
    }
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