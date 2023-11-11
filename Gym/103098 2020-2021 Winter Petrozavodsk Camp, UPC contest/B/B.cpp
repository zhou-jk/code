#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n;
int a[N],tot;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    if(n%4==0)
    {
        for(int i=0;i<n/4;i++)
            a[++tot]=n-1-i;
        a[++tot]=n/4-1;
        for(int i=0;i<n/4;i++)
            a[++tot]=n-1-i-n/4;
        for(int i=0;i<n/4-1;i++)
            a[++tot]=n/2-2-i;
        for(int i=0;i<n/4-1;i++)
            a[++tot]=n/4-2-i;
        a[++tot]=n/2-1;
    }
    else if(n%4==1)
    {
        for(int i=0;i<n/4;i++)
            a[++tot]=n-1-i;
        a[++tot]=n/4;
        for(int i=0;i<n/4;i++)
            a[++tot]=n-n/4-1-i;
        for(int i=0;i<n/4-1;i++)
            a[++tot]=n/2-1-i;
        for(int i=0;i<n/4-1;i++)
            a[++tot]=n/4-1-i;
        a[++tot]=0;
        a[++tot]=n/2;
    }
    else
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return;
}