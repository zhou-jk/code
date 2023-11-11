#include<iostream>
#include<cstdio>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
using namespace std;
long long qpow(long long a,long long b,long long p)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=(__int128)res*a%p;
        a=(__int128)a*a%p,b>>=1;
    }
    return res;
}
bool miller_rabin(long long n)
{
    if(n==1) return false;
    if(n%2==0) return n==2;
    static const int prime[]={2,325,9375,28178,450775,9780504,1795265022};
    long long u=n-1;
    int t=0;
    while(u%2==0) u/=2,t++;
    for(int a:prime)
    {
        if(a%n==0) continue;
        long long x=qpow(a,u,n);
        if(x==1||x==n-1) continue;
        for(int s=0;s<t;s++)
        {
            x=(__int128)x*x%n;
            if(x==n-1) break;
        }
        if(x!=n-1) return false;
    }
    return true;
}
int main()
{
    long long x;
    while(scanf("%lld",&x)==1)
    {
        if(miller_rabin(x)) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}