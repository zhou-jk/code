#include<iostream>
#include<cstdio>
using namespace std;
const int N=5005;
const int MOD=998244353;
int n,m,k;
char s[N][N];
int f[N][N];
int d[N][N],r[N][N];
int pw3[N];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]=' ';
    pw3[0]=1;
    for(int i=1;i<=max(n,m);i++)
        pw3[i]=(long long)pw3[i-1]*3%MOD;
    for(int i=1;i<=k;i++)
    {
        int h,w;
        char c;
        scanf("%d%d",&h,&w);
        for(c=getchar();c!='R'&&c!='D'&&c!='X';c=getchar());
        s[h][w]=c;
    }
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
            d[i][j]=d[i+1][j]+(s[i][j]==' '),r[i][j]=r[i][j+1]+(s[i][j]==' ');
    f[1][1]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='D') f[i+1][j]=(f[i+1][j]+(long long)pw3[r[i][j+1]]*f[i][j])%MOD;
            else if(s[i][j]=='R') f[i][j+1]=(f[i][j+1]+(long long)pw3[d[i+1][j]]*f[i][j])%MOD;
            else if(s[i][j]=='X') f[i+1][j]=(f[i+1][j]+(long long)pw3[r[i][j+1]]*f[i][j])%MOD,f[i][j+1]=(f[i][j+1]+(long long)pw3[d[i+1][j]]*f[i][j])%MOD;
            else f[i+1][j]=(f[i+1][j]+(long long)pw3[r[i][j+1]]*f[i][j]*2)%MOD,f[i][j+1]=(f[i][j+1]+(long long)pw3[d[i+1][j]]*f[i][j]*2)%MOD;
        }
    int ans=f[n][m];
    if(s[n][m]==' ') ans=(long long)ans*3%MOD;
    printf("%d",ans);
    return 0;
}