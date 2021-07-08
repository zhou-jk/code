#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=505;
const int MOD=998244353;
int n;
char s[N];
int x[N];
int f[N][N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        s[i]=getchar();
        while(s[i]!='-'&&s[i]!='+') s[i]=getchar();
        if(s[i]=='+') scanf("%d",&x[i]);
    }
    int ans=0;
    for(int p=1;p<=n;p++)
        if(s[p]=='+')
        {
            memset(f,0,sizeof(f));
            f[0][0]=1;
            for(int i=1;i<=n;i++)
                if(i==p)
                {
                    for(int j=0;j<=i;j++)
                        f[i][j]=f[i-1][j];
                }
                else if(s[i]=='-')
                {
                    for(int j=0;j<=i;j++)
                        f[i][j]=(f[i-1][j]+f[i-1][j+1])%MOD;
                    if(i<p) f[i][0]=(f[i][0]+f[i-1][0])%MOD;
                }
                else if(x[i]>x[p]||(x[i]==x[p]&&i>p))
                {
                    for(int j=0;j<=i;j++)
                        f[i][j]=(f[i-1][j]+f[i-1][j])%MOD;
                }
                else
                {
                    for(int j=1;j<=i;j++)
                        f[i][j]=(f[i-1][j]+f[i-1][j-1])%MOD;
                    f[i][0]=f[i-1][0];
                }
            int sum=0;
            for(int j=0;j<=n;j++)
                sum=(sum+f[n][j])%MOD;
            ans=(ans+1LL*sum*x[p])%MOD;
        }
    printf("%d",ans);
    return 0;
}