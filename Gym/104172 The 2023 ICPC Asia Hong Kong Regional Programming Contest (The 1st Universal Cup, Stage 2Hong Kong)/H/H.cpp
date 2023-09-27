#include<iostream>
#include<cstdio>
using namespace std;
int l,r,b,k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>l>>r>>b>>k;
    long long ans=(long long)(l+b-1)/b*b*k;
    cout<<ans;
    return 0;
}