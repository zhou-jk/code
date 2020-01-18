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
        if(b&1) res=res*a%p;
        a=a*a%p,b>>=1;
    }
    return res;
}
unordered_map<long long,long long>book;
long long BSGS(long long y,long long z,long long p)
{
    y%=p,z%=p;
    if(y==0) return z==0?1:-1;
    if(z==1) return 0;
    int m=ceil(sqrt(p));
    book.clear();
    long long sum=z;
    for(int i=0;i<m;i++)
    {
        book[sum]=i;
        sum=sum*y%p;
    }
    long long t=ksm(y,m,p);
    sum=t;
    for(int i=1;i<=ceil((double)p/m);i++)
    {
        if(book.count(sum)) return i*m-book[sum];
        sum=sum*t%p;
    }
    return -1;
}
int main()
{
    int b,n,p;
    scanf("%d%d%d",&p,&b,&n);
    long long res=BSGS(b,n,p);
    if(res==-1) printf("no solution");
    else printf("%lld",res);
    return 0;
}