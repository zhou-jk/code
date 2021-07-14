#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=305;
const int MOD=1000000007;
int n,m,L;
string s;
int a[N];
int s1[N],s2[N];
int f[2][N][N][N],g[2][N][N][N];
int main()
{
    cin>>s;
    L=s.size();
    reverse(s.begin(),s.end());
    while((int)s.size()>0)
    {
        if(s[0]!='1')
        {
            cout<<0;
            return 0;
        }
        string t="";
        int c=1;
        n++;
        for(int i=0;i<(int)s.size();i++)
            if(s[i]-'0'==c) a[n]++,c^=1;
            else t+=s[i];
        s=t;
    }
    for(int i=1;i<=L;i++)
        s1[i]=s1[i-1]+a[i]/2;
    for(int i=1;i<=L;i++)
        s2[i]=s2[i-1]+(a[i]+1)/2;
    int cur=0;
    f[0][0][0][L]=g[0][0][0][L]=1;
    int ans=0;
    for(int i=1;i<=L;i++)
    {
        cur^=1;
        if(i-2>=0)
        {
            for(int j=0;j<=s1[i-2];j++)
                for(int k=0;k<=s2[i-2];k++)
                    for(int t=0;t<=L/max(i-2,1);t++)
                        f[cur][j][k][t]=g[cur][j][k][t]=0;
        }
        for(int j=0;j<=s1[i];j++)
            for(int k=0;k<=s2[i];k++)
            {
                for(int t=0;t<=L/i;t++)
                    if(j-t/2>=0&&k-(t+1)/2>=0) f[cur][j][k][t]=(g[cur^1][j-t/2][k-(t+1)/2][L/max(i-1,1)]-(t-1>=0?g[cur^1][j-t/2][k-(t+1)/2][t-1]:0))%MOD;
                g[cur][j][k][0]=f[cur][j][k][0];
                for(int t=1;t<=L/i;t++)
                    g[cur][j][k][t]=(g[cur][j][k][t-1]+f[cur][j][k][t])%MOD;
            }
        if(i>=n)
            for(int t=1;t<=L/i;t++)
                ans=(ans+f[cur][s1[n]][s2[n]][t])%MOD;
    }
    ans=(ans+MOD)%MOD;
    printf("%d",ans);
    return 0;
}