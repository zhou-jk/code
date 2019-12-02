#include<iostream>
#include<cstdio>
#include<cmath>
#include<unordered_map>
using namespace std;
int T,k;
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
long long ex_gcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    long long c=ex_gcd(b,a%b,x,y),z=x;
    x=y;y=z-y*(a/b);
    return c;
}
long long calc(long long a,long long b,long long c)
{
    long long x,y;
    long long d=ex_gcd(a,b,x,y);
    if(c%d!=0) return -1;
    long long s=b/d;
    x=x*c/d;
    x=(x%s+s)%s;
    return x;
}
unordered_map<long long,long long>book;
long long BSGS(long long y,long long z,long long p)
{
    if(y%p==0) return -1;
    y%=p,z%=p;
    if(z==1) return 0;
    int m=ceil(sqrt(p));
    book.clear();
    long long sum=z;
    for(int i=0;i<m;i++)
    {
        if(!book.count(sum)) book[sum]=i;
        sum=sum*y%p;
    }
    sum=ksm(y,m,p);
    long long t=sum;
    for(int i=1;i<=ceil((double)p/m);i++)
    {
        if(book.count(sum)) return i*m-book[sum];
        sum=sum*t%p;
    }
    return -1;
}
int main()
{
    scanf("%d%d",&T,&k);
    while(T--)
    {
        int y,z,p;
        scanf("%d%d%d",&y,&z,&p);
        if(k==1) printf("%lld\n",ksm(y,z,p));
        else if(k==2)
        {
            long long res=calc(y,p,z);
            if(res==-1) printf("Orz, I cannot find x!\n");
            else printf("%lld\n",res);
        }
        else if(k==3)
        {
            long long res=BSGS(y,z,p);
            if(res==-1) printf("Orz, I cannot find x!\n");
            else printf("%lld\n",res);
        }
    }
    return 0;
}