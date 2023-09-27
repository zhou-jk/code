#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int v=*min_element(a+1,a+n+1);
    bool f1=true,f2=true;
    for(int i=1;i<=n;i++)
    {
        if(a[i]%v!=0) f1=false;
        if(a[i]!=v&&(a[i]-1)/2<v) f2=false;
    }
    if(f1||f2) cout<<v;
    else cout<<v/2;
    return 0;
}