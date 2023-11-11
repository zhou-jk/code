#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,k;
int a[N];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(a[n]>=a[n-1])
    {
        cout<<"Python will never be faster than C++";
        return 0;
    }
    for(int i=n+1;;i++)
    {
        a[i]=max(2*a[i-1]-a[i-2],0);
        if(a[i]<k)
        {
            cout<<"Python 3."<<i<<" will be faster than C++";
            return 0;
        }
    }
    return 0;
}
