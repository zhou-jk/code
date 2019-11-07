#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=2009;
struct matrix
{
    int p[101][101],n;
    matrix()
    {
        memset(p,0,sizeof(p));
        n=0;
        return;
    }
    matrix operator *(const matrix &b)const
    {
        matrix c;
        c.n=n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=b.n;j++)
                for(int k=1;k<=n;k++)
                    c.p[i][j]=(c.p[i][j]+p[i][k]*b.p[k][j]%mod)%mod;
        return c;
    }
}ans,a;
char s[11];
int n,T;
matrix ksm(matrix a,int b)
{
    matrix res;
    res.n=a.n;
    for(int i=1;i<=a.n;i++)
        res.p[i][i]=1;
    while(b)
    {
        if(b&1) res=res*a;
        b>>=1,a=a*a;
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&T);
    a.n=n*9;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=8;j++)
            a.p[9*(i-1)+j][9*(i-1)+j+1]=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        for(int j=1;j<=n;j++)
            if(s[j-1]>'0') a.p[9*(i-1)+s[j-1]-'0'][9*(j-1)+1]=1;
    }
    ans=ksm(a,T);
    printf("%d",ans.p[1][n*9-8]);
    return 0;
}