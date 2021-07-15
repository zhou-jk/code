#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000005;
const int INF=1061109567;
int n;
char s[N],t[N];
int a[N],b[N];
int f[N][2][2][2];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%s",t+1);
    for(int i=1;i<=n;i++)
        a[i]=s[i]-'0',b[i]=t[i]-'0';
    memset(f,63,sizeof(f));
    f[0][0][0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=1;j++)
            for(int k=0;k<=1;k++)
                for(int l=0;l<=1;l++)
                    if(f[i-1][j][k][l]<INF)
                    {
                        int d;
                        d=b[i]==0;
                        f[i][d][1][0]=min(f[i][d][1][0],f[i-1][j][k][l]+(d&&j==0)+(k==0));
                        d=b[i]==1;
                        f[i][d][0][1]=min(f[i][d][0][1],f[i-1][j][k][l]+(d&&j==0)+(l==0));
                        d=a[i]!=b[i];
                        f[i][d][0][0]=min(f[i][d][0][0],f[i-1][j][k][l]+(d&&j==0));
                    }
    int ans=INF;
    for(int j=0;j<=1;j++)
        for(int k=0;k<=1;k++)
            for(int l=0;l<=1;l++)
                ans=min(ans,f[n][j][k][l]);
    printf("%d",ans);
    return 0;
}