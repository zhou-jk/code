#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=1000000007;
long long n,m,k;
int SIZE;
struct Matrix
{
    long long c[32][32];
    Matrix()
    {
        memset(c,0,sizeof(c));
        return;
    }
    Matrix operator *(const Matrix &b)const
    {
        Matrix res;
        for(int i=0;i<SIZE;i++)
            for(int j=0;j<SIZE;j++)
                for(int k=0;k<SIZE;k++)
                    res.c[i][j]=(res.c[i][j]+c[i][k]*b.c[k][j]%MOD)%MOD;
        return res;
    }
}ans,x;
bool check(int x)
{
    int cnt=0;
    while(x)
    {
        if(x&1) cnt++;
        x>>=1;
    }
    return cnt<=k;
}
Matrix ksm(Matrix x,long long b)
{
    Matrix res;
    for(int i=0;i<SIZE;i++)
        res.c[i][i]=1;
    while(b)
    {
        if(b&1) res=res*x;
        x=x*x,b>>=1;
    }
    return res;
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    SIZE=1<<m;
    for(int i=0;i<SIZE;i++)
    {
        if(!check(i)) continue;
        int s=i;
        if((s&(1<<(m-1)))==(1<<(m-1))) s-=1<<(m-1);
        s<<=1;
        if(check(s)) x.c[i][s]=1;
        s|=1;
        if(check(s)) x.c[i][s]=1;
    }
    ans=ksm(x,n);
    long long res=0;
    for(int i=0;i<SIZE;i++)
        if(check(i)) res=(res+ans.c[i][i])%MOD;
    printf("%lld",res);
    return 0;
}