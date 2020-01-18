#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
deque<int>q;
int n,m,w;
int dp[2001][2001];
int ans;
int main()
{
    scanf("%d%d%d",&n,&m,&w);
    memset(dp,-63,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        int ap,bp,as,bs;
        scanf("%d%d%d%d",&ap,&bp,&as,&bs);
        for(int j=0;j<=as;j++)
            dp[i][j]=-1*j*ap;
        for(int j=0;j<=m;j++)
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        if(i<=w) continue;
        q.clear();
        for(int j=0;j<=m;j++)
        {
            while(!q.empty()&&dp[i-w-1][q.back()]+q.back()*ap<=dp[i-w-1][j]+j*ap)
                q.pop_back();
            q.push_back(j);
            while(!q.empty()&&q.front()<j-as)
                q.pop_front();
            if(!q.empty()) dp[i][j]=max(dp[i][j],dp[i-w-1][q.front()]+q.front()*ap-j*ap);
        }
        q.clear();
        for(int j=m;j>=0;j--)
        {
            while(!q.empty()&&q.front()>j+bs)
                q.pop_front();
            while(!q.empty()&&dp[i-w-1][q.back()]+q.back()*bp<=dp[i-w-1][j]+j*bp)
                q.pop_back();
            q.push_back(j);
            if(!q.empty()) dp[i][j]=max(dp[i][j],dp[i-w-1][q.front()]+q.front()*bp-j*bp);
        }
    }
    for(int i=0;i<=m;i++)
        ans=max(ans,dp[n][i]);
    printf("%d",ans);
    return 0;
}