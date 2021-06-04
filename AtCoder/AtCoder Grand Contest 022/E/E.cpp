#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=300005;
const int MOD=1000000007;
int n;
char s[N];
int f[N][3][3];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    f[0][0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
            {
                if(s[i+1]=='1')
                {
                    if(k>=1) f[i+1][j][k-1]=(f[i+1][j][k-1]+f[i][j][k])%MOD;
                    else if(j+1<3) f[i+1][j+1][k]=(f[i+1][j+1][k]+f[i][j][k])%MOD;
                    else f[i+1][2][k]=(f[i+1][2][k]+f[i][j][k])%MOD;
                }
                if(s[i+1]=='0')
                {
                    if(k>=2) f[i+1][j][1]=(f[i+1][j][1]+f[i][j][k])%MOD;
                    else f[i+1][j][k+1]=(f[i+1][j][k+1]+f[i][j][k])%MOD;
                }
                if(s[i+1]=='?')
                {
                    if(k>=1) f[i+1][j][k-1]=(f[i+1][j][k-1]+f[i][j][k])%MOD;
                    else if(j+1<3) f[i+1][j+1][k]=(f[i+1][j+1][k]+f[i][j][k])%MOD;
                    else f[i+1][2][k]=(f[i+1][2][k]+f[i][j][k])%MOD;
                    if(k>=2) f[i+1][j][1]=(f[i+1][j][1]+f[i][j][k])%MOD;
                    else f[i+1][j][k+1]=(f[i+1][j][k+1]+f[i][j][k])%MOD;
                }
            }
    int ans=0;
    for(int j=0;j<3;j++)
        for(int k=0;k<=j;k++)
            ans=(ans+f[n][j][k])%MOD;
    printf("%d",ans);
    return 0;
}