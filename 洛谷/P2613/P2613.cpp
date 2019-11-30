#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=19260817;
inline long long read()
{
    char ch;
    bool flag=true;
    long long ret=0;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') flag=false;
    while(ch>='0'&&ch<='9')
        ret=((ret<<1)+(ret<<3)+(ch^48))%MOD,ch=getchar();
    return flag?ret:-ret;
}
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
long long modular(long long a,long long b)
{
    return calc(b,MOD,a);
}
long long a,b;
int main()
{
    a=read(),b=read();
    if(b==0) printf("Angry!");
    else printf("%lld",modular(a,b));
    return 0;
}