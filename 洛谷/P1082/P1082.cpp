#include<iostream>
#include<cstdio>
using namespace std;
long long x,y,m,n,L;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    else
    {
        long long d=exgcd(b,a%b,x,y);
        long long t=x;
        x=y,y=t-a/b*y;
        return d;
    }
}
int main()
{
    long long a,b,x,y;
    scanf("%lld%lld",&a,&b);
    exgcd(a,b,x,y);
    printf("%lld",(x%b+b)%b);
    return 0;
}
