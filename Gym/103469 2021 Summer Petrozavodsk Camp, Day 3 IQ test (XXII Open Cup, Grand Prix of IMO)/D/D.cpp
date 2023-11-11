#include<iostream>
#include<cstdio>
#include<bitset>
#include<queue>
using namespace std;
const int N=4005;
int n;
int a[N][N];
bitset<N>f[N],g[N];
pair<int,int>b[N*N/4];
bool t[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j+=2)
        {
            cin>>a[i][j];
            b[a[i][j]]=make_pair(i,j+1);
        }
    for(int i=1;i<=n+1;i++)
        f[i][i]=g[i][i]=1;
    for(int val=1;val<=n*n/4;val++)
    {
        auto [i,j]=b[val];
        t[i][j]=1;
        if(f[i][j]) continue;
        if(f[i+1][j-1]) f[i][j]=g[j][i]=1;
        if(!f[i][j]) continue;
        queue<pair<int,int>>q;
        q.emplace(i,j);
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            if(x-1>=0&&!f[x-1][y+1]&&t[x-1][y+1])
            {
                f[x-1][y+1]=g[y+1][x-1]=1;
                q.emplace(x-1,y+1);
            }
            if(x-2>=0&&!f[x-2][y]&&t[x-2][x])
            {
                f[x-2][y]=g[y][x-2]=1;
                q.emplace(x-2,y);
            }
            if(y+2<=n+1&&!f[x][y+2]&&t[y][y+2])
            {
                f[x][y+2]=g[y+2][x]=1;
                q.emplace(x,y+2);
            }
            bitset<N>pos1=f[y]&(~f[x]);
            for (int t=pos1._Find_first();t<=n+1;t=pos1._Find_next(t))
            {
                f[x][t]=g[t][x]=1;
                q.emplace(x,t);
            }
            bitset<N>pos2=g[x]&(~g[y]);
            for(int t=pos2._Find_first();t<=n+1;t=pos2._Find_next(t))
            {
                f[t][y]=g[y][t]=1;
                q.emplace(t,y);
            }
        }
        if(f[1][n+1])
        {
            cout<<val;
            return 0;
        }
    }
    return 0;
}
