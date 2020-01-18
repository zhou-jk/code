#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int K=21;
long long f[100][10*K*K];
long long l,r,P;
int cnt,p[100];
long long init(int u,int sum,bool limit)
{
    if(u==0) return sum;
    if(!limit&&f[u][sum]!=-1) return f[u][sum];
    int end=limit?p[u]:P-1;
    long long res=0;
    for(int i=0;i<=end;i++)
        res+=init(u-1,sum+(u-1)*i,limit&&i==end);
    if(!limit) f[u][sum]=res;
    return res;
}
long long init(int u,int up,int sum,bool limit)
{
    if(sum<0) return 0;
    if(u==0) return sum;
    if(!limit&&f[u][sum]!=-1) return f[u][sum];
    int end=limit?p[u]:P-1;
    long long res=0;
    for(int i=0;i<=end;i++)
        if(u>=up) res+=init(u-1,up,sum+i,limit&&i==end);
        else res+=init(u-1,up,sum-i,limit&&i==end);
    return limit==0?f[u][sum]=res:res;
}
long long calc(long long n)
{
    cnt=0;
    do
    { 
        p[++cnt]=n%P;
        n/=P;
    }
    while(n);
    memset(f,-1,sizeof(f));
    long long res=init(cnt,0,true);
    for(int i=2;i<=cnt;i++)
    {
        memset(f,-1,sizeof(f));
        res-=init(cnt,i,0,true);
    }
    return res;
}
int main()
{
    scanf("%lld%lld%lld",&l,&r,&P);
    printf("%lld",calc(r)-calc(l-1));
    return 0;
}