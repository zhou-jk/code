#include<iostream>
#include<cstdio>
using namespace std;
int x,y,z;
void solve()
{
    cin>>x>>y>>z;
    int k=y-(z-x);
    if(k==0) k=z+1;
    if(k<=z||k<=x)
    {
        cout<<-1<<"\n";
        return;
    }
    else cout<<k<<"\n";
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