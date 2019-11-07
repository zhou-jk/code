#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=1000000007;
long long n,m,k;
struct Matrix
{
    int size;
    long long c[8][8];
    Matrix(int s=0)
    {
        size=s;
        memset(c,0,sizeof(c));
        return;
    }
    Matrix operator *(const Matrix b)const
    {
        Matrix res(size);
        for(int i=1;i<=size;i++)
            for(int j=1;j<=size;j++)
                for(int k=1;k<=size;k++)
                    res.c[i][j]=(res.c[i][j]+c[i][k]*b.c[k][j]%MOD)%MOD;
        return res;
    }
    Matrix operator *=(const Matrix &b)
    {
        *this=*this*b;
        return *this;
    }
    friend Matrix pow(Matrix a,long long b)
    {
        Matrix res(a.size);
        for(int i=1;i<=a.size;i++)
    	    res.c[i][i]=1;
        while(b)
        {
            if(b&1) res*=a;
            a*=a,b>>=1;
        }
        return res;
    }
};
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
int main()
{
    while(1)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        if(n==0&&m==0&&k==0) return 0;
	    if(k==0) printf("%lld\n",ksm(m,n));
	    if(k==1)
        {
			if(n==1)
            {
                printf("%lld\n",m);
                continue;
            }
		    Matrix a(2);
		    a.c[1][1]=0;
            a.c[1][2]=1;
            a.c[2][1]=m-1;
            a.c[2][2]=m-2;
		    printf("%lld\n",pow(a,n-1).c[2][1]*m%MOD);
		}
		if(k==2)
        {
			if(n==1)
            {
                printf("%lld\n",m);
                continue;
            }
            else if(n==2)
            {
                printf("%lld\n",m*(m-1)%MOD);
                continue;
            }
			Matrix a(7);
			a.c[1][1]=m-4;
            a.c[1][4]=m-3;
            a.c[1][6]=m-3;
			a.c[2][1]=1;
            a.c[2][6]=1;
			a.c[3][1]=1;
            a.c[3][4]=1;
			a.c[4][2]=m-3;
            a.c[4][7]=m-2;
			a.c[5][2]=1;
			a.c[6][3]=m-3;
            a.c[6][5]=m-2;
			a.c[7][3]=1;
			a=pow(a,n-2);
			printf("%lld\n",((a.c[1][5]+a.c[6][5])%MOD)*m%MOD*(m-1)%MOD);
		}
	}
    return 0;
}