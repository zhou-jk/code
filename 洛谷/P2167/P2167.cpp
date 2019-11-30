#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=51,M=15;
const int MOD=1000003;
int dp[N][1<<M],f[N][N];
int T,n,K;
char s[N][N];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        memset(f,0,sizeof(f));
        scanf("%d%d",&n,&K);
        for(int i=0;i<n;i++)
            scanf("%s",s[i]);
        int len=strlen(s[0]);
        for(int i=1;i<=len;i++)
            for(int j=0;j<26;j++)
                for(int k=0;k<n;k++)
                    if(s[k][i-1]==j+'a'||s[k][i-1]=='?') f[i][j]|=1<<k;
        dp[0][(1<<n)-1]=1;
        for(int i=1;i<=len;i++)
            for(int j=0;j<(1<<n);j++)
                for(int k=0;k<26;k++)
                    dp[i][f[i][k]&j]=(dp[i][f[i][k]&j]+dp[i-1][j])%MOD;
        int ans=0;
        for(int j=0;j<(1<<n);j++)
        {
            int p=j,cnt=0;
            while(p)
                cnt+=p&1,p>>=1;
            if(cnt==K) ans=(ans+dp[len][j])%MOD; 
        }
        printf("%d\n",ans);
    } 
    return 0;
}