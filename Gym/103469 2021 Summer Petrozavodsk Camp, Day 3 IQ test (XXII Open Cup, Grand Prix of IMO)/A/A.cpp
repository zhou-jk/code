#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int b[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        if((b[i]&b[1])!=b[1])
        {
            cout<<-1<<"\n";
            return;
        }
    vector<int>a;
    for(int i=1;i<=n;i++)
        a.emplace_back(b[i]),a.emplace_back(b[1]);
    int k=a.size();
    cout<<k<<"\n";
    for(int u:a)
        cout<<u<<" ";
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
