#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=1000000007;
struct Matrix
{
    int n;
    long long a[101][101];
    Matrix(int x=0)
    {
        n=x;
        memset(a,0,sizeof(a));
        return;
    }
    Matrix operator*(const Matrix &b)const
    {
        Matrix c(n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    c.a[i][j]=(a[i][k]*b.a[k][j]%MOD+c.a[i][j])%MOD;
        return c;
    }
    Matrix operator*=(const Matrix &b)
    {
        *this=*this*b;
        return *this;
    }
    friend Matrix pow(Matrix a,long long b)
    {
        Matrix res(a.n);
        for(int i=1;i<=a.n;i++)
            res.a[i][i]=1;
        while(b)
        {
            if(b&1) res*=a;
            a*=a,b>>=1;
        }
        return res;
    }
}A;
long long k;
int main()
{
    scanf("%d%lld",&A.n,&k);
    for(int i=1;i<=A.n;i++)
        for(int j=1;j<=A.n;j++)
            scanf("%lld",&A.a[i][j]);
    Matrix res=pow(A,k);
    for(int i=1;i<=res.n;i++)
    {
        for(int j=1;j<=res.n;j++)
            printf("%lld ",res.a[i][j]);
        printf("\n");
    }
    return 0;   
}