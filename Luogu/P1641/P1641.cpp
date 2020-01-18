#include<iostream>
#include<cstdio>
long long a[2000001];
const int MOD=20100403;
int n,m;
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}
long long C(int n,int m)
{
    return a[n]*ksm(a[m],MOD-2)%MOD*ksm(a[n-m],MOD-2)%MOD;
}
int main()
{
    a[0]=1;
    for(int i=1;i<=2000000;i++)
        a[i]=(a[i-1]*i)%MOD;
    scanf("%d%d",&n,&m);
    printf("%lld",(C(n+m,m)-C(n+m,m-1)+MOD)%MOD);
    return 0;
}