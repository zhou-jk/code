#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=1061109567;
const int N=1005;
int n;
int dp[N][1<<15],mat[5],w[5];
bool s[N][5];
char ch[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=4;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=4;i++)
    {
        scanf("%s",ch);
        for(int j=0;j<n;j++)
            s[j+1][i]=ch[j]=='.';
    }
    mat[1]=1;
    mat[2]=51;
    mat[3]=1911;
    mat[4]=65535;
    int now=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=3;j++)
            if(s[j][i]) now|=1<<((j-1)*4+i-1);
    memset(dp,63,sizeof(dp));
    dp[0][now]=0;
    for(int i=1;i<=n;i++)
    {
        int nxt=0;
        for(int j=1;j<=4;j++)
            if(s[i+3][j]) nxt|=1<<(j-1);
        for(int state=0;state<(1<<12);state++)
        {
            if(dp[i-1][state]==INF) continue;
            for(int a=0;a<=4;a++)
                for(int b=0;b<=3;b++)
                    for(int c=0;c<=2;c++)
                        for(int d=0;d<=1;d++)
                            if(((state|(mat[a]<<(4-a)|mat[b]<<(3-b)|mat[c]<<(2-c)|mat[d]<<(1-d)))&15)==15) dp[i][(state>>4)|((mat[a]<<(4-a)|mat[b]<<(3-b)|mat[c]<<(2-c)|mat[d]<<(1-d))>>4)|(nxt<<8)]=min(dp[i][(state>>4)|((mat[a]<<(4-a)|mat[b]<<(3-b)|mat[c]<<(2-c)|mat[d]<<(1-d))>>4)|(nxt<<8)],dp[i-1][state]+w[a]+w[b]+w[c]+w[d]);
        }
            
    }
    printf("%d",dp[n][0]);
    return 0;
}