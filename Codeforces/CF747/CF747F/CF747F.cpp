#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=17;
int limit[N];
long long C[N][N],dp[N][N];
void init(int n)
{
    for(int i=0;i<=n;i++)
        C[i][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    return;
}
long long DP(int len,int flag)
{
    if(len==0) return 1;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=len&&i<=limit[0];i++)
        dp[0][i]=C[len][i];
    for(int i=1;i<16;i++)
        for(int j=0;j<=len;j++)
            for(int k=0;k<=j&&k<=limit[i];k++)
                dp[i][j]+=dp[i-1][j-k]*C[len-j+k][k];
    return dp[15][len];    
}
int res[N];

int main()
{
    long long n;
    int m;
    scanf("%lld%d",&n,&m);
    for(int i=0;i<16;i++)
        limit[i]=m;
    init(15);
    int pos=-1;
    long long ans=n;
    for (int i=0;i>=0;i++)
    {
        long long sum=0;
        for(int j=1;j<16;j++)
        {
            limit[j]--;
            sum+=DP(i,j);
            limit[j]++;
            if(sum>=ans)
            {
                pos=i;
                break;
            }
        }
        if(ans>sum) ans-=sum;
        else break;
    }
    for(int i=pos;i>=0;i--)
        for(int j=0;j<16;j++)
        {
            if(i==pos&&j==0) continue;
            if(limit[j]<=0) continue;
            limit[j]--;
            long long sum=DP(i,j);
            limit[j]++;
            if(ans>sum) ans-=sum;
            else
            {
                res[i]=j;
                limit[j]--;
                break;
            }
        }
    for(int i=pos;i>=0;i--)
        printf("%x",res[i]);
    return 0;
}