#include<iostream>
#include<cstdio>
using namespace std;
const int N=20;
int T,n,k;
long long S[N+1][N+1],fac[N+1];
void init()
{
	for(int i=1;i<=N;i++)
	{
        S[i][0]=0;
        S[i][i]=1;
        for(int j=1;j<i;j++)
            S[i][j]=(S[i-1][j-1]+(i-1)*S[i-1][j]);
    }
    fac[0]=1;
    for(int i=1;i<=N;i++)
        fac[i]=fac[i-1]*i;
    return;
}
int main()
{
    init();
    scanf("%d",&T);
    while(T--)
	{
        scanf("%d%d",&n,&k);
        double ans=0;
        for(int i=1;i<=k;i++)
			ans+=(double)(S[n][i]-S[n-1][i-1])/fac[n];
        printf("%.4lf\n",ans);
    }
    return 0;
}
