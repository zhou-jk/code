#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<functional>
using namespace std;
const int N=605,M=200005;
const int dir[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
int n;
int d1,d2;
int id[N][N];
int fsqrt[M];
void draw(int col[N][N],int d)
{
    vector<int>G[N*N];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int a=0;a*a<=d;a++)
                if(fsqrt[d-a*a]!=-1)
                {
                    int b=fsqrt[d-a*a];
                    for(int k=0;k<4;k++)
                    {
                        int x=i+a*dir[k][0],y=j+b*dir[k][1];
                        if(x<1||x>n||y<1||y>n) continue;
                        G[id[i][j]].emplace_back(id[x][y]);
                    }
                }
    static int c[N*N];
    memset(c,-1,sizeof(c));
    function<void(int,int)>dfs=[&](int u,int col)
    {
        if(c[u]!=-1) return;
        c[u]=col;
        for(int v:G[u])
            dfs(v,col^1);
        return;
    };
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(c[id[i][j]]==-1) dfs(id[i][j],1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            col[i][j]=c[id[i][j]];
    return;
}
int col[2][N][N];
int main()
{
    scanf("%d%d%d",&n,&d1,&d2);
    n=n*2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            id[i][j]=(i-1)*n+j;
    memset(fsqrt,-1,sizeof(fsqrt));
    for(int i=0;i*i<=max(d1,d2);i++)
        fsqrt[i*i]=i;
    draw(col[0],d1);
    draw(col[1],d2);
    vector<pair<int,int>>pos[2][2];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            pos[col[0][i][j]][col[1][i][j]].emplace_back(i,j);
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if((int)pos[i][j].size()>=n*n/4)
            {
                for(int k=0;k<n*n/4;k++)
                {
                    auto [x,y]=pos[i][j][k];
                    printf("%d %d\n",x-1,y-1);
                }
                return 0;
            }
    return 0;
}