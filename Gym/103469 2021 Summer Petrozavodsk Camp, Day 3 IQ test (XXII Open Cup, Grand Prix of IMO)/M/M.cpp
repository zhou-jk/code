#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000005;
int n,m;
int a[N];
int c[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    m=*max_element(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        c[a[i]]++;
    long long ans=0;
    for(int i=1;i<=m;i++)
        for(int j=i+2;j<=m/i;j+=2)
            ans+=c[(j-i)/2]*c[i*j];
    cout<<ans;
    return 0;
}
