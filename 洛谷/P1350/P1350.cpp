#include<iostream>
#include<cstdio>
using namespace std;
int Mod=100003;
int a,b,c,d,k;
long long f[1001][2001],v[2001];
int main()
{
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
    for(int i=1;i<=c;i++)
        v[i]=d,f[0][i]=1;
    for(int i=c+1;i<=a+c;i++)
        v[i]=b+d,f[0][i]=1;
    f[0][0]=1;
    for(int j=1;j<=a+c;j++)
        for(int i=1;i<=k;i++)
            f[i][j]=(f[i][j-1]+f[i-1][j-1]*(v[j]-i+1))%Mod;
    printf("%lld",f[k][a+c]);
    return 0;
}