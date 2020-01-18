#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define MOD 998244353
#define MAX 2550
inline int read()
{
    int x=0;bool t=false;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=true,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return t?-x:x;
}
int n,m,C0,C1,D0,D1,ans;
int fr[MAX],S[MAX],ss[MAX],sum;
int g1[MAX],g2[MAX];
vector<int> p[MAX];
int K,lim[MAX],Lim[MAX];
int f[MAX][MAX],g[MAX][MAX];
int Calc(int x,int y)
{
    int lc=max(0,sum-x-C1),rc=C0-x;
    int ld=max(0,sum-y-D1),rd=D0-y;
    if(lc>rc||ld>rd)return 0;
    return 1ll*(g2[rc]-(lc?g2[lc-1]:0)+MOD)*(g1[rd]-(ld?g1[ld-1]:0)+MOD)%MOD;
}
int main()
{
    int T=read();
    while(T--)
    {
        n=read();m=read();C0=read();C1=read();D0=read();D1=read();
        for(int i=1;i<=n;++i)
        {
            fr[i]=read();S[i]=read();
            sum+=S[i];ss[fr[i]]+=S[i];
        }
        K=read();
        for(int i=1;i<=n;++i)lim[i]=-1;
        for(int i=1;i<=m;++i)Lim[i]=-1;
        for(int i=1;i<=K;++i)
        {
            int x=read(),q=read();
            lim[x]=Lim[fr[x]]=q;
            p[fr[x]].push_back(x);
        }
        g1[0]=g2[0]=1;
        int s1=0,s2=0;
        for(int i=1;i<=n;++i)
        {
            s1+=S[i];if(~lim[i])continue;
            for(int j=min(s1,D0);j>=S[i];--j)
                g1[j]=(g1[j]+g1[j-S[i]])%MOD;
        }
        for(int i=1;i<=m;++i)
        {
            s2+=ss[i];if(!ss[i]||~Lim[i])continue;
            for(int j=min(s2,C0);j>=ss[i];--j)
                g2[j]=(g2[j]+g2[j-ss[i]])%MOD;
        }
        for(int i=1;i<=D0;++i)g1[i]=(g1[i-1]+g1[i])%MOD;
        for(int i=1;i<=C0;++i)g2[i]=(g2[i-1]+g2[i])%MOD;
        f[0][0]=1;
        for(int i=1,sc=0,sd=0;i<=m;++i)
        {
            if(!~Lim[i]||!ss[i])continue;
            for(int j=0;j<=C0&&j<=sc;++j)
                for(int k=0;k<=D0&&k<=sd;++k)g[j][k]=f[j][k];
            for(int qwq=0;qwq<(int)p[i].size();++qwq)
            {
                int x=p[i][qwq];sd+=S[x];
                int t0=lim[x]!=0,t1=lim[x]!=1,t2=lim[x]!=2,t3=lim[x]!=3;
                for(int j=min(C0,sc);~j;--j)
                    for(int k=min(D0,sd);~k;--k)
                        if(k>=S[x])
                        {
                            f[j][k]=(f[j][k]*t1+f[j][k-S[x]]*t0)%MOD;
                            g[j][k]=(g[j][k]*t3+g[j][k-S[x]]*t2)%MOD;
                        }
                        else f[j][k]=f[j][k]*t1,g[j][k]=g[j][k]*t3;
            }
            sc+=ss[i];
            for(int j=min(C0,sc);~j;--j)
                for(int k=min(D0,sd);~k;--k)
                    if(j>=ss[i])f[j][k]=(f[j-ss[i]][k]+g[j][k])%MOD;
                    else f[j][k]=g[j][k];
        }
        for(int i=0;i<=C0;++i)
            for(int j=0;j<=D0;++j)
                ans=(ans+1ll*f[i][j]*Calc(i,j))%MOD;
        printf("%d\n",ans);
        sum=ans=0;
        for(int i=0;i<=D0;++i)g1[i]=0;
        for(int i=0;i<=C0;++i)g2[i]=0;
        for(int i=1;i<=n;++i)fr[i]=S[i]=0,lim[i]=0;
        for(int i=1;i<=m;++i)p[i].clear(),ss[i]=0,Lim[i]=0;
        for(int i=0;i<=C0;++i)for(int j=0;j<=D0;++j)g[i][j]=f[i][j]=0;
    }
    return 0;
}