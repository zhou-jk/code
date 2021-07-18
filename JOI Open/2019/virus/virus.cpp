#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int R=805,C=805,M=100005;
const int INF=1061109567;
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int m,r,c;
char s[M];
int d[M*2];
int u[R][C];
int mx[1<<4];
pair<int,int> bel[R][C];
bool vis[R][C];
pair<int,int> getbel(pair<int,int> v)
{
    if(bel[v.first][v.second]==v) return v;
    else return bel[v.first][v.second]=getbel(bel[v.first][v.second]);
}
int ans=INF,cnt;
pair<int,int> bfs(int s,int t)
{
    queue<pair<int,int>>q;
    q.emplace(s,t);
    vis[s][t]=true;
    vector<pair<int,int>>pos;
    pos.emplace_back(s,t);
    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=x+dir[i][0],ty=y+dir[i][1];
            if(tx<1||tx>r||ty<1||ty>c) continue;
            if(vis[tx][ty]) continue;
            int state=0;
            if(vis[tx-1][ty]) state|=1<<0;
            if(vis[tx+1][ty]) state|=1<<1;
            if(vis[tx][ty-1]) state|=1<<2;
            if(vis[tx][ty+1]) state|=1<<3;
            if(u[tx][ty]>0&&mx[state]>=u[tx][ty])
            {
                if(getbel({tx,ty})!=make_pair(s,t))
                {
                    for(auto [x,y]:pos)
                        vis[x][y]=false;
                    return getbel({tx,ty});
                }
                vis[tx][ty]=true;
                q.emplace(tx,ty);
                pos.emplace_back(tx,ty);
            }
        }
    }
    int k=pos.size();
    if(k<ans) ans=k,cnt=k;
    else if(k==ans) cnt+=k;
    for(auto [x,y]:pos)
        vis[x][y]=false;
    return {-1,-1};
}
bool book[R][C];
int main()
{
    scanf("%d%d%d",&m,&r,&c);
    scanf("%s",s+1);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf("%d",&u[i][j]);
    for(int i=1;i<=m;i++)
        if(s[i]=='N') d[i]=0;
        else if(s[i]=='S') d[i]=1;
        else if(s[i]=='W') d[i]=2;
        else if(s[i]=='E') d[i]=3;
    for(int i=m+1;i<=m+m;i++)
        d[i]=d[i-m];
    for(int s=0;s<(1<<4);s++)
    {
        int lst=1;
        for(int i=1;i<=m+m;i++)
            if(s&(1<<d[i])) mx[s]=max(mx[s],i-lst+1);
            else lst=i+1;
        if(mx[s]>=m+m) mx[s]=INF;
    }
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            bel[i][j]={i,j};
    while(true)
    {
        bool flag=false;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                if(u[i][j]>0&&getbel({i,j})==make_pair(i,j)&&!book[i][j])
                {
                    auto [x,y]=bfs(i,j);
                    if(x==-1&&y==-1)
                    {
                        book[i][j]=true;
                        continue;
                    }
                    flag=true;
                    bel[i][j]={x,y};
                }
        if(!flag) break;
    }
    printf("%d\n%d",ans,cnt);
    return 0;
}