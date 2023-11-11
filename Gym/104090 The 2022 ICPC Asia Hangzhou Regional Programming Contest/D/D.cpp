#include<iostream>
#include<cstdio>
#include<iomanip>
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
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    double d=(double)sum/(n+1);
    cout<<fixed<<setprecision(10)<<d*2;
    for(int i=2;i<=n;i++)
        cout<<" "<<d;
    return 0;
}