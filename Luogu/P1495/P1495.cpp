#include<iostream>
#include<cstdio>
using namespace std;
const int N=11;
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
long long calc(long long a,long long b,long long c)
{
    long long x,y;
    long long d=ex_gcd(a,b,x,y);
    long long s=b/d;
    x=x*c/d;
    x=(x%s+s)%s;
    return x;
}
int n;
long long M=1;
long long ans;
int m[N],a[N];
int t[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&m[i],&a[i]);
        M*=m[i];
    }
    for(int i=1;i<=n;i++)
        t[i]=calc(M/m[i],m[i],1);
    for(int i=1;i<=n;i++)
        ans+=a[i]*(M/m[i])*t[i];
    printf("%lld",(ans+M)%M);
    return 0;
}