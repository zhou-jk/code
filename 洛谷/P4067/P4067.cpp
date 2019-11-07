#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T;
long long N,M,K;
int P;
long long dp[62][2][2][2][2];
int fa[62],fb[62],fc[62];
int L;
int makedp(long long N,long long M,long long K,int P)
{
	memset(fa,0,sizeof(fa));
    memset(fb,0,sizeof(fb));
	memset(fc,0,sizeof(fc));
    memset(dp,0,sizeof(dp));
    int i,L;
    N--,M--;
    dp[0][1][1][1][0]=1;
	for(i=1;N;N>>=1,i++)
        fa[i]=N%2;
    L=max(L,i-1);
	for(i=1;M;M>>=1,i++)
        fb[i]=M%2;
    L=max(L,i-1);
	for(i=1;K;K>>=1,i++)
        fc[i]=K%2;
    L=max(L,i-1);
	for(int i=1;2*i<=L;i++)
		swap(fa[i],fa[L-i+1]),swap(fb[i],fb[L-i+1]),swap(fc[i],fc[L-i+1]);
	for(int i=1;i<=L;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++)
				for(int l=0;l<=1;l++)
					if(dp[i-1][j][k][l][0]!=0)
                        for(int m=0;m<=1;m++)
                            for(int n=0;n<=1;n++)
                            {
						        if(((m^n)>fc[i]&&l)||(m>fa[i]&&j)||(n>fb[i]&&k)) continue;
                                dp[i][j&&m==fa[i]][k&&n==fb[i]][l&&(m^n)==fc[i]][0]=(dp[i][j&&m==fa[i]][k&&n==fb[i]][l&&(m^n)==fc[i]][0]+dp[i-1][j][k][l][0])%P;
						        dp[i][j&&m==fa[i]][k&&n==fb[i]][l&&(m^n)==fc[i]][1]=(dp[i][j&&m==fa[i]][k&&n==fb[i]][l&&(m^n)==fc[i]][1]+dp[i-1][j][k][l][1]*2+(m^n)*dp[i-1][j][k][l][0])%P;
					        }
	return L;
}
int main()
{
    scanf("%d",&T);
	while(T--)
    {
        scanf("%lld%lld%lld%d",&N,&M,&K,&P);
	    long long ans=0;
        int L=makedp(N,M,max(N,M)<<1,P);
	    for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++)
		        ans=(ans+dp[L][i][j][0][1])%P;
	    L=makedp(N,M,K,P);
        ans=((ans-N%P*(M%P)%P*(K%P))%P+P)%P;
	    for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++)
                for(int k=0;k<=1;k++)
		            ans=((ans+K%P*(dp[L][i][j][k][0]%P)%P-dp[L][i][j][k][1])%P+P)%P;
	    printf("%lld\n",ans);
    }
	return 0;
}