#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int r(double x)
{
    int xx=(int)x;
    if(x-xx<0.5) return xx;
    else return xx+1;
}
void solve()
{
    cin>>n>>k;
    double ret=n-0.5*(k-1);
    int mn=0,mx=0;
    if(ret<0) mn=0;
    else mn=r(ret);
    if(ret<0) mx=n*2;
    else mx=k-1+r(ret);
    cout<<mn<<" "<<mx<<"\n";
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