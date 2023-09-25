#include<iostream>
#include<cstdio>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
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
long long find_factor(long long n)
{
    long long s=0,t=0;
    long long c=rnd()%(n-1)+1;
    for(int goal=1;;goal*=2)
    {
        long long val=1;
        for(int step=1;step<=goal;step++)
        {
            t=((__int128)t*t+c)%n;
            val=(__int128)val*abs(t-s)%n;
            if(step%127==0)
            {
                long long d=gcd(val,n);
                if(d>1) return d;
            }
        }
        long long d=gcd(val,n);
        if(d>1) return d;
        s=t;
    }
}
vector<pair<long long,int>>pollard_rho(long long n)
{
    if(n==1) return {};
    if(miller_rabin(n)) return {make_pair(n,1)};
    long long p=n;
    while(p>=n) p=find_factor(n);
    int cnt=0;
    while(n%p==0) n/=p,cnt++;
    vector<pair<long long,int>>res1=pollard_rho(n),res2=pollard_rho(p);
    for(auto &[x,i]:res2)
        i*=cnt;
    vector<pair<long long,int>>res;
    int p1=0,p2=0;
    while(p1<(int)res1.size()&&p2<(int)res2.size())
    {
        if(res1[p1].first<res2[p2].first) res.emplace_back(res1[p1]),p1++;
        else if(res1[p1].first>res2[p2].first) res.emplace_back(res2[p2]),p2++;
        else res.emplace_back(make_pair(res1[p1].first,res1[p1].second+res2[p2].second)),p1++,p2++;
    }
    while(p1<(int)res1.size())
        res.emplace_back(res1[p1]),p1++;
    while(p2<(int)res2.size())
        res.emplace_back(res2[p2]),p2++;
    return res;
}