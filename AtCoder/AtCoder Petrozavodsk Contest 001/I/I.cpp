#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MOD=1000000007;
const int INV2=500000004;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int N=35;
int h,w;
int n;
int x[N],y[N];
int bx[N],totx,by[N],toty;
int dx[N*2],dy[N*2],r,c;
pair<int,int> px[N*2],py[N*2];
bool black[N*2][N*2];
int dis[N*2][N*2];
bool vis[N*2][N*2];
int bfs(int sx,int sy)
{
    vector<pair<int,int>>pos;
    queue<pair<int,int>>q;
    q.emplace(sx,sy);
    dis[sx][sy]=0;
    vis[sx][sy]=true;
    while(!q.empty())
    {
        auto [x,y]=q.front();
        pos.emplace_back(x,y);
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=x+dir[i][0],ty=y+dir[i][1];
            if(tx<1||tx>r||ty<1||ty>c) continue;
            if(vis[tx][ty]||black[tx][ty]) continue;
            dis[tx][ty]=dis[x][y]+1;
            vis[tx][ty]=true;
            q.emplace(tx,ty);
        }
    }
    for(auto [x,y]:pos)
        vis[x][y]=false;
    int res=0;
    for(int i=1;i<=r;i++)
        if(1<=px[i].first&&px[i].second<=h)
            for(int j=1;j<=c;j++)
                if(1<=py[j].first&&py[j].second<=w)
                    if(!black[i][j]) res=(res+(long long)dis[i][j]*(px[i].second-px[i].first+1)%MOD*(py[j].second-py[j].first+1))%MOD;
    return res;
}
int main()
{
    scanf("%d%d",&h,&w);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        x[i]++,y[i]++;
    }
    for(int i=1;i<=n;i++)
        bx[++totx]=x[i],by[++toty]=y[i];
    bx[0]=0,bx[++totx]=h+1,by[0]=0,by[++toty]=w+1;
    sort(bx+1,bx+totx+1);
    sort(by+1,by+toty+1);
    int ans=0;
    for(int i=1;i<=totx;i++)
    {
        if(bx[i]-bx[i-1]-1>=1)
        {
            for(int k=bx[i-1]+2;k<=bx[i]-1;k++)
            {
                int pre=((long long)(k-1)*w-(i-1))%MOD,suf=((long long)(h+1-k)*w-(totx-i))%MOD;
                ans=(ans+(long long)pre*suf)%MOD;
            }
            r++,dx[r]=bx[i]-bx[i-1]-1-1,px[r]=make_pair(bx[i-1]+1,bx[i]-1);
        }
        if(bx[i]!=bx[i-1]&&bx[i]<=h) r++,dx[r]=0,px[r]=make_pair(bx[i],bx[i]);
    }
    for(int i=1;i<=toty;i++)
    {
        if(by[i]-by[i-1]-1>=1)
        {
            for(int k=by[i-1]+2;k<=by[i]-1;k++)
            {
                int pre=((long long)(k-1)*h-(i-1))%MOD,suf=((long long)(w+1-k)*h-(toty-i))%MOD;
                ans=(ans+(long long)pre*suf)%MOD;
            }
            c++,dy[c]=by[i]-by[i-1]-1-1,py[c]=make_pair(by[i-1]+1,by[i]-1);
        }
        if(by[i]!=by[i-1]&&by[i]<=w) c++,dy[c]=0,py[c]=make_pair(by[i],by[i]);
    }
    for(int i=1;i<=n;i++)
        x[i]=lower_bound(px+1,px+r+1,make_pair(x[i],x[i]))-px,y[i]=lower_bound(py+1,py+c+1,make_pair(y[i],y[i]))-py,black[x[i]][y[i]]=true;
    int sum=0;
    for(int i=1;i<=r;i++)
        if(1<=px[i].first&&px[i].second<=h)
            for(int j=1;j<=c;j++)
                if(1<=py[j].first&&py[j].second<=w)
                    if(!black[i][j]) sum=(sum+(long long)bfs(i,j)*(px[i].second-px[i].first+1)%MOD*(py[j].second-py[j].first+1))%MOD;
    sum=(long long)sum*INV2%MOD;
    ans=(ans+sum)%MOD;
    printf("%d",ans);
    return 0;
}