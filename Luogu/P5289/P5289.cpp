#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2501,MOD=998244353;
int T,n,c;
int c0,c1,d0,d1;
int K;
int ss;
long long ans;
int b[N],s[N];
long long dp[N][N];
long long f1[N][N],f2[N][N],f[N],g[N];
int ki[N],kp[N];
int v[N],ct[N];
int sum[N],Sum[N];
vector<int>school[N];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        memset(Sum,0,sizeof(Sum));
        memset(sum,0,sizeof(sum));
        memset(ct,0,sizeof(ct));
        memset(v,-1,sizeof(v));
        for(int i=0;i<N;i++)
            school[i].clear();
        ss=0,ans=0;
        scanf("%d%d%d%d%d%d",&n,&c,&c0,&c1,&d0,&d1);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&b[i],&s[i]);
            sum[b[i]]+=s[i],ss+=s[i];
        }
        scanf("%d",&K);
        for(int i=1;i<=K;i++)
        {
            scanf("%d%d",&ki[i],&kp[i]);
            ct[i]=b[ki[i]];
            school[b[ki[i]]].push_back(ki[i]);
            v[ki[i]]=kp[i];
        }
        sort(ct+1,ct+K+1);
        K=unique(ct+1,ct+K+1)-ct-1;
        for(int i=1;i<=n;i++)
            if(v[i]!=-1) Sum[b[i]]+=s[i];
        dp[0][0]=1;
        int s1=0,s2=0;
        for(int i=1;i<=K;i++)
        {
            s1=min(c0,s1+sum[ct[i]]),s2=min(d0,s2+Sum[ct[i]]);
            for(int j=0;j<=1;j++)
            {
                for(int j=0;j<=s1;j++)
                    for(int k=0;k<=s2;k++)
                        f1[j][k]=dp[j][k];
                for(auto k:school[ct[i]])
                {
                    for(int l=s1;l>=0;l--)
                        for(int m=s2;m>=0;m--)
                        {
                            if(j==0)
                            {
                                f1[l][m]=0;
                                if(v[k]!=1&&l>=s[k]) f1[l][m]=(f1[l][m]+f1[l-s[k]][m])%MOD;
                                if(v[k]!=0&&l>=s[k]&&m>=s[k]) f1[l][m]=(f1[l][m]+f1[l-s[k]][m-s[k]])%MOD;
                            }
                            else
                            {
                                if(v[k]==3) f1[l][m]=0;
                                if(v[k]!=2&&m>=s[k]) f1[l][m]=(f1[l][m]+f1[l][m-s[k]])%MOD;
                            }
                        }
                }
                if(j==0)
                {
                    for(int k=s1;k>=0;k--)
                        for(int l=s2;l>=0;l--)
                            if(k>=sum[ct[i]]-Sum[ct[i]]) f1[k][l]=f1[k-(sum[ct[i]]-Sum[ct[i]])][l];
                            else f1[k][l]=0;
                    for(int j=0;j<=s1;j++)
                        for(int k=0;k<=s2;k++)
                            f2[j][k]=f1[j][k];
                }
                else
                {
                    for(int k=0;k<=s1;k++)
                        for(int l=0;l<=s2;l++)
                            dp[k][l]=(f1[k][l]+f2[k][l])%MOD;
                }
            }
        }
        f[0]=1;
        int Max=0;
        for(int i=1;i<=c;i++)
            if(school[i].empty()&&sum[i])
            {
                Max=min(c0,Max+sum[i]);
                for(int j=Max;j>=sum[i];j--)
                    f[j]=(f[j]+f[j-sum[i]])%MOD;
            }
        g[0]=1;
        Max=0;
        for(int i=1;i<=n;i++)
            if(v[i]==-1)
            {
                Max=min(d0,Max+s[i]);
                for(int j=Max;j>=s[i];j--)
                    g[j]=(g[j]+g[j-s[i]])%MOD;
            }
        for(int i=1;i<=c0;i++)
            f[i]=(f[i]+f[i-1])%MOD;
        for(int i=1;i<=d0;i++)
            g[i]=(g[i]+g[i-1])%MOD;
        for(int i=0;i<=c0;i++)
            if(c0+c1>=ss)
                for(int j=0;j<=d0;j++)
                    if(d0+d1>=ss)
                    {
                        long long sum1=0,sum2=0;
                        if(ss-i-c1-1>=0) sum1=(f[c0-i]-f[ss-i-c1-1]+MOD)%MOD;
                        else sum1=f[c0-i];
                        if(ss-j-d1-1>=0) sum2=(g[d0-j]-g[ss-j-d1-1]+MOD)%MOD;
                        else sum2=g[d0-j];
                        ans=(ans+dp[i][j]*((sum1*sum2)%MOD)%MOD)%MOD;
                    }
        printf("%lld\n",ans);
    }
    return 0;
}