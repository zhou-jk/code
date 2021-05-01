#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n;
long long ex_gcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    long long d=ex_gcd(b,a%b,x,y);
    long long tmp=x;
    x=y,y=tmp-a/b*y;
    return d;
}
int main()
{
    scanf("%lld",&n);
    n=n*2; 
    long long res=n-1; 
    for(long long a=1;a*a<=n;a++)
        if(n%a==0)
        {
            long long b=n/a;
            if(__gcd(a,b)!=1) continue;
            long long x,y;
            long long d=ex_gcd(a,b,x,y);
            if(x>=0)
            {
                long long t=(x+b)/b;
                x-=t*b,y+=t*a;
            }
            if(y<=0)
            {
                long long t=(-y+b)/b;
                x-=t*b,y+=t*a;
            }
            res=min(res,-a*x);
            swap(a,b);
            d=ex_gcd(a,b,x,y);
            if(x>=0)
            {
                long long t=(x+b)/b;
                x-=t*b,y+=t*a;
            }
            if(y<=0)
            {
                long long t=(-y+b)/b;
                x-=t*b,y+=t*a;
            }
            res=min(res,-a*x);
            swap(a,b);
        }
    printf("%lld",res);
    return 0;
}