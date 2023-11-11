#include<iostream>
#include<cstdio>
#include<numeric>
using namespace std;
const int N=100005;
int n,m;
int a[N];
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    long long d=exgcd(b,a%b,x,y);
    long long tmp=x;
    x=y,y=tmp-a/b*y;
    return d;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    long long a=n,b=(long long)n*(n+1)/2;
    long long d=gcd(a,b);
    long long g=gcd(d,m);
    long long z=(m-sum%m+g-1)/g;
    long long mn=sum%g;
    long long k,t;
    exgcd(d,m,k,t);
    k=(k*z%m+m)%m,t=(t*z%m+m)%m;
    long long x,y;
    exgcd(a,b,x,y);
    x=(x*k%m+m)%m,y=(y*k%m+m)%m;
    cout<<mn<<"\n";
    cout<<x<<" "<<y;
    return 0;
}