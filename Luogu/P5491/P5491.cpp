#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
int MOD;
long long w;
struct complex
{
    long long real,imag;
    bool operator==(const complex &b)const
    {
        return real==b.real&&imag==b.imag;
    }
    complex operator *(const complex &b)const
    {
        complex res;
        res.real=(real*b.real%MOD+w*imag%MOD*b.imag%MOD)%MOD;
        res.imag=(real*b.imag%MOD+imag*b.real%MOD)%MOD;
        return res;
    }
    complex operator *=(const complex &b)
    {
        *this=*this * b;
        return *this;
    }
    friend complex ksm(complex a,int b)
    {
        complex res=(complex){1,0};
        while(b)
        {
            if(b&1) res*=a;
            a*=a,b>>=1;
        }
        return res;
    }
};
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
bool check(int n)
{
    return ksm(n,(MOD-1)/2,MOD)==1;
}
long long cipolla(int n,int p)
{
    if(n==0) return 0;
    MOD=p;
    if(!check(n)) return -1;
    long long a;
    for(a=rand()%(MOD-1)+1;check((a*a%MOD+MOD-n)%MOD);a=rand()%(MOD-1)+1);
    w=(a*a%MOD+MOD-n)%MOD;
    complex res=ksm((complex){a,1},(MOD+1)/2);
    return res.real;
}
int T,n,p;
int main()
{
    srand((unsigned)time(NULL));
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&p);
        long long res=cipolla(n,p);
        if(res==-1) printf("Hola!\n");
        else if(res==p-res) printf("%lld\n",res);
        else if(res==0) printf("0\n");
        else printf("%lld %lld\n",min(res,p-res),max(res,p-res));
    }
    return 0;
}