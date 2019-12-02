#include<iostream>
#include<cstdio>
#include<cmath>
#include<unordered_map>
using namespace std;
long long ksm(long long a,long long b,long long p)
{
    long long res=1;
    while(b)
    {
        if(b%2==1) res=res*a%p;
        b/=2,a=a*a%p;
    }
    return res;
}
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
unordered_map<long long,long long>book;
long long ex_BSGS(long long y,long long z,long long p)
{
    y%=p,z%=p;
    if(y==0) return z==0?1:-1;
    if(z==1) return 0;
    int k=0;
    long long a=1;
    while(1)
    {
        long long d=gcd(y,p);
        if(d==1) break;
        if(z%d!=0) return -1;
        z/=d,p/=d;
        k++;
        a=a*y/d%p;
        if(z==a) return k;
    }
    book.clear();
    int m=ceil(sqrt(p));
    long long sum=z;
    for(int i=0;i<m;i++)
    {
        book[sum]=i;
        sum=sum*y%p;
    }
    long long t=ksm(y,m,p);
    sum=t*a%p;
    for(int i=1;i<=ceil((double)p/m);i++)
    {
        if(book.count(sum)) return i*m-book[sum]+k;
        sum=sum*t%p;
    }
    return -1;
}
int main()
{
    while(1)
    {
        long long a,p,b;
        scanf("%lld%lld%lld",&a,&p,&b);
        if(a==0&&p==0&&b==0) return 0;
        long long res=ex_BSGS(a,b,p);
        if(res==-1) printf("No Solution\n");
        else printf("%lld\n",res);
    }
    return 0;
}