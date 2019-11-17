#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
    char ch;
    int ret=0;
    bool flag=true;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') flag=false;
    while(ch>='0'&&ch<='9')
        ret=(ret<<1)+(ret<<3)+(ch^48),ch=getchar();
    return flag?ret:-ret;
}
const int N=10001;
const int INF=1061109567;
int n,k;
int a[N];
long long w[N];
long long dp[2][2000001];
int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)
	    a[i]=read()+n*k;
    for(int i=1;i<=n;i++)
        w[i]=read();
	int m=2*n*k+1;
    for(int i=0;i<m;i++)
	    dp[0][i]=-INF;
	dp[0][n*k]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
		{
			dp[i&1][j]=-INF;
			if(j>a[i]) continue;
            for(int l=-k;l<=k;l++)
				if(j-l>=0&&j-l<m) dp[i&1][j]=max(dp[i&1][j],dp[(i&1)^1][j-l]);
			if(dp[i&1][j]>-INF) dp[i&1][j]+=w[i]*(j-n*k);
		}
	long long ans=-INF;
	for(int i=0;i<m;i++)
        ans=max(ans,dp[n&1][i]);
	printf("%lld",ans);
    return 0;
}