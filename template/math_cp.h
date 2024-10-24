#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
using namespace std;
long long get_phi(long long x)
{
    long long res=x;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
        {
            res=res/i*(i-1);
            while(x%i==0) x/=i;
        }
    if(x>1) res=res/x*(x-1);
    return res;
}
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
bool is_prime(long long n)
{
    if(n<2) return false;
    for(long long i=2;i*i<=n;i++)
        if(n%i==0) return false;
    if(n < 2) return false;
    return true;
}
long long get_primitive_root(long long m)
{
    if(m==1) return -1;
    if(m==2) return 1;
    if(m==4) return 3;
    long long mm=m;
    if(mm%2==0) mm/=2;
    if(mm%2==0) return -1;
    for(long long i=2;i*i<=mm;i++)
        if(mm%i==0)
        {
            while(mm%i==0) mm/=i;
            if(mm!=1) return -1;
        }
    long long p=get_phi(m);
    long long tmp=p;
    vector<long long>factors;
    for(long long i=2;i*i<=tmp;i++)
        if(tmp%i==0)
        {
            factors.push_back(i);
            while(tmp%i==0) tmp/=i;
        }
    if(tmp>1) factors.push_back(tmp);
    for(long long g=2;g<m;g++)
    {
        bool flag=true;
        if(gcd(g,m)!=1) continue;
        for(long long u:factors)
            if(qpow(g,p/u,m)==1)
            {
                flag=false;
                break;
            }
        if(flag) return g;
    }
    return -1;
}