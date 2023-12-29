#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N],b[N];
int sa[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++)
        cin>>a[i];
    for(int i=2;i<=n;i++)
        b[i]=b[i-1]^a[i];
    for(int j=0;j<20;j++)
    {
        int c0=0,c1=0;
        for(int i=2;i<=n;i++)
            if((b[i]>>j)&1) c1++;
            else c0++;
        if(c1>c0) b[1]|=1<<j;
    }
    for(int i=2;i<=n;i++)
        b[i]^=b[1];
    for(int i=1;i<=n;i++)
        cout<<b[i]<<" ";
    return 0;
}