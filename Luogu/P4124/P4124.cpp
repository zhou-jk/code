#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=12;
long long dp[N][11][2][2][2][2][2];
long long L,R;
long long calc(long long x)
{
    memset(dp,0,sizeof(dp));
    long long ans=0;
    int len=0,digit[12];
    while(x)
    {
        digit[++len]=x%10;
        x/=10;
    }
    reverse(digit+1,digit+len+1);
    dp[0][10][0][0][0][0][1]=1;
    for(int i=0;i<len;i++)
        for(int j=0;j<=10;j++)
            for(int k=0;k<=1;k++)
                for(int l=0;l<=1;l++)
                    for(int m=0;m<=1;m++)
                        for(int n=0;n<=1;n++)
                            for(int o=0;o<=1;o++)
                                for(int p=0;p<=9;p++)
                                {
                                    int a,b,c,d,e;
                                    if(o&&p>digit[i+1]) continue;
                                    if(p==j) a=1;
                                    else a=0;
                                    if(l==0) b=a+k==2;
                                    else b=l;
                                    if(m==0) c=p==4;
                                    else c=m;
                                    if(n==0) d=p==8;
                                    else d=n;
                                    if(o&&p==digit[i+1]) e=1;
                                    else e=0;
                                    if(c+d==2) continue;
                                    dp[i+1][p][a][b][c][d][e]+=dp[i][j][k][l][m][n][o]; 
                                }
    for(int i=0;i<=9;i++)
        for(int j=0;j<=1;j++)
            for(int k=0;k<=1;k++)
                for(int l=0;l<=1&&l+k<2;l++)
                    ans+=dp[len][i][j][1][k][l][0];
    return ans;
}
int main()
{
    scanf("%lld%lld",&L,&R);
    printf("%lld",calc(R+1)-calc(L));
    return 0;
}