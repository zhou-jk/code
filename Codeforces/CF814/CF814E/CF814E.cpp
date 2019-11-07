#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000007;
int n,d[51];
const int a[51]={0,0,1,1,3,12,60,360,2520,20160,181440,1814400,19958400,239500800,113510379,589145299,837179429,394870773,712803099,830455698,778658157,573163035,36423651,801320322,430367280,328814650,220366194,729521009,697067110,517878947,18489358,554680740,195102821,243290230,28577534,971636156,7265222,261547992,677275641,736474183,722492941,899717444,888414952,313427725,477392084,5251549,236319705,870706360,923198640,313534412,363186083};
int c1,c2;
long long f[51][51],g[51][51][51],c[51][51];
long long ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    c[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
    }
    g[0][0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=2;j<i;j++)
            g[0][0][i]=(g[0][0][i]+g[0][0][i-1-j]*c[i-1][j]%MOD*a[j+1]%MOD)%MOD;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n-i;j++)
        {
            if(i>=2) g[0][i][j]=(g[0][i][j]+g[0][i-2][j]*(i-1)%MOD)%MOD;
            if(j>=1) g[0][i][j]=(g[0][i][j]+g[0][i][j-1]*j%MOD)%MOD;
        }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n-i;j++)
            for(int k=0;k<=n-i-j;k++)
            {
                if(j>=1) g[i][j][k]=(g[i][j][k]+g[i-1][j-1][k]*j%MOD)%MOD;
                if(k>=1) g[i][j][k]=(g[i][j][k]+g[i-1][j+1][k-1]*k%MOD)%MOD;
            }
    f[d[1]+1][d[1]]=1;
    for(int i=d[1]+2;i<=n;i++)
        for(int j=1;j<i-d[1];j++)
        {
            c1=c2=0;
            for(int k=1;k<=i-j;k++)
            {
                if(d[i-j-k+1]==2) c1++;
                else c2++;
                f[i][j]=(f[i][j]+f[i-j][k]*g[j][c1][c2]%MOD)%MOD;
            }
        }
    c1=c2=0;
    for(int i=1;i<n;i++)
    {
        if(d[n-i+1]==2) c1++;
        else c2++;
        ans=(ans+f[n][i]*g[0][c1][c2]%MOD)%MOD;
    }
    printf("%lld",ans);
    return 0;
}