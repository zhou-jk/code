#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int T;
char str[3];
long long ans;
int a[35],book[35];
long long dp[36][5][2][5][3][3];
long long f[36];
const int c[5][5]={{1,0,0,0,0},{1,1,0,0,0},{1,2,1,0,0},{1,3,3,1,0},{1,4,6,4,1}};
const int yaoku[15]={0,1,9,10,18,19,27,28,29,30,31,32,33,34};
const bool isyaoku[35]={0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
const bool tail[35]={0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1};
void kokushi()
{
    int x;
    for(int i=1;i<=13;i++)
    {
        x=yaoku[i];
        long long tmp=13;
        tmp*=c[a[x]][2]*book[x]*book[x];
        for(int j=1;j<=13;j++)
        {
            if(i==j) continue;
            x=yaoku[j];
            tmp*=a[x]*book[x];
        }
        ans=max(ans,tmp);
    }
    return;
}
void chitoi()
{
    vector<int>v;
    for(int i=1;i<=34;i++)
        v.push_back(c[a[i]][2]*book[i]*book[i]);
    sort(v.begin(),v.end(),greater<int>());
    long long sum=7;
    for(int i=0;i<7;i++)
        sum*=v[i];
    ans=max(ans,sum);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(f,0,sizeof(f));
        memset(dp,0,sizeof(dp));
        fill(a+1,a+34+1,4);
        fill(book+1,book+34+1,1);
        ans=0;
        dp[1][0][0][0][0][0]=1;
        while(1)
        {
            scanf("%s",str);
            if(str[0]=='0') break;
            else if(str[1]=='p') a[str[0]-'0']--;
            else if(str[1]=='s') a[str[0]-'0'+9]--;
            else if(str[1]=='m') a[str[0]-'0'+18]--;
            else if(str[0]=='E') a[28]--;
            else if(str[0]=='S') a[29]--;
            else if(str[0]=='W') a[30]--;
            else if(str[0]=='N') a[31]--;
            else if(str[0]=='B') a[32]--;
            else if(str[0]=='F') a[33]--;
            else if(str[0]=='Z') a[34]--;
        }
        while(1)
        {
            scanf("%s",str);
            if(str[0]=='0') break;
            else if(str[1]=='p') book[str[0]-'0']=2;
            else if(str[1]=='s') book[str[0]-'0'+9]=2;
            else if(str[1]=='m') book[str[0]-'0'+18]=2;
            else if(str[0]=='E') book[28]=2;
            else if(str[0]=='S') book[29]=2;
            else if(str[0]=='W') book[30]=2;
            else if(str[0]=='N') book[31]=2;
            else if(str[0]=='B') book[32]=2;
            else if(str[0]=='F') book[33]=2;
            else if(str[0]=='Z') book[34]=2;
        }
        kokushi(); 
        chitoi();
        for(int i=1;i<=34;i++)
            for(int j=0;j<=4;j++)
                for(int k=0;k<=4;k++)
                    for(int l=0;l<=2;l++)
                        for(int m=0;m<=2;m++)
                        {
                            if(a[i]-k>=2) dp[i][j][1][k+2][l][m]=max(dp[i][j][1][k+2][l][m],dp[i][j][0][k][l][m]/c[a[i]][k]*c[a[i]][k+2]*book[i]*book[i]);
                            if(j<4)
                            {
                                if(a[i]-k>=3)
                                {
                                    for(int o=0;o<2;o++)
                                        dp[i][j+1][o][k+3][l][m]=max(dp[i][j+1][o][k+3][l][m],dp[i][j][o][k][l][m]/c[a[i]][k]*c[a[i]][k+3]*book[i]*book[i]*book[i]);
                                }
                                if(!tail[i]&&a[i]>k&&a[i+1]>l&&a[i+2]>m&&l!=2&&m!=2)
                                {
                                    for(int o=0;o<2;o++)
                                        dp[i][j+1][o][k+1][l+1][m+1]=max(dp[i][j+1][o][k+1][l+1][m+1],dp[i][j][o][k][l][m]/c[a[i]][k]*c[a[i]][k+1]*book[i]/c[a[i+1]][l]*c[a[i+1]][l+1]*book[i+1]/c[a[i+2]][m]*c[a[i+2]][m+1]*book[i+2]);
                                }
                            }
                            dp[i+1][j][0][l][m][0]=max(dp[i+1][j][0][l][m][0],dp[i][j][0][k][l][m]);
                            dp[i+1][j][1][l][m][0]=max(dp[i+1][j][1][l][m][0],dp[i][j][1][k][l][m]);
                            if(j==4) f[i]=max(f[i],dp[i][j][1][k][l][m]);
                        }
        printf("%lld\n",max(ans,*max_element(f+1,f+35+1)));
    }
    return 0;
}