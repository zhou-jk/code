#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int c0=0,cp=0,cn=0;
    for(int i=1;i<=n;i++)
        if(a[i]>0) cp++;
        else if(a[i]<0) cn++;
        else c0++;
    if(c0)
    {
        cout<<0<<"\n";
        return;
    }
    if(cn%2==0)
    {
        cout<<1<<"\n";
        cout<<1<<" "<<0<<"\n";
    }
    else cout<<0<<"\n";
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