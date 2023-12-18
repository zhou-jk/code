#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1005;
int n;
int p[N],q[N];
int pos[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
        cin>>q[i];
    for(int i=1;i<=n;i++)
        pos[q[i]]=i;
    vector<int>pp(n);
    for(int i=1;i<=n;i++)
        pp[i-1]=pos[p[i]];
    string ans;
    for(int i=n-1;i>=1;i--)
    {
        while(pp[0]!=i)
        {
            ans+='1';
            pp.emplace_back(pp[0]);
            pp.erase(pp.begin());
        }
        while(pp[1]!=i+1)
        {
            ans+='2';
            pp.emplace_back(pp[1]);
            pp.erase(pp.begin()+1);
        }
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