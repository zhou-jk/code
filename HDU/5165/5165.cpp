#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
using namespace std;
const int N=105;
vector<int> nxt[N*N],pre[N*N];
map<pair<int,int>,bool>book;
int f[N],id[N][N];
int dp[N*N][2];
int T,n,m;
queue<pair<int,int> > q;
void init()
{
    int tot=0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            id[j][i]=id[i][j]=++tot;
    for(int i=1;i<=tot;i++)
        nxt[i].clear(),pre[i].clear();
    book.clear();
    memset(dp,0,sizeof(dp));
    return; 
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            	scanf("%d",&f[j]);
            for(int j=1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                {
                    int u=id[j][k],v=id[f[j]][f[k]];
                    if(!book[make_pair(u,v)])
                    {
                        nxt[u].push_back(v),pre[v].push_back(u);
                        book[make_pair(u,v)]=true;
                    }
                }
        }
        for(int i=1;i<=n;i++)
        {
            q.push(make_pair(id[i][i],0));
            q.push(make_pair(id[i][i],1));
            dp[id[i][i]][0]=dp[id[i][i]][1]=1;
        }
        while(!q.empty())
        {
            int u=q.front().first,k=q.front().second;
            q.pop();
            if(k==1)
            {
                for(auto v:pre[u])
                    if(dp[v][0]==0)
                    {
                        dp[v][0]=1;
                        q.push(make_pair(v,0));
                    }
            }
            else if(k==0)
            {
                for(auto v:pre[u])
	                if(dp[v][1]==0)
	                {
	                    dp[v][1]=1;
	                    for(auto w:nxt[v])
	                        dp[v][1]&=dp[w][0];
	                    if(dp[v][1]) q.push(make_pair(v,1));
	                }
            }
        }
        int ans=1;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                ans&=dp[id[i][j]][0];
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
