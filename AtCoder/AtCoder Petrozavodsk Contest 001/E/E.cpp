#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n;
vector<int>G[N];
int f[N];
void dfs(int u,int father)
{
    bool flag=false;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        f[u]+=f[v];
        if(f[v]==0&&flag) f[u]++;
        if(f[v]==0&&!flag) flag=true;
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    int p=0;
    for(int i=1;i<=n;i++)
        if((int)G[i].size()>=3)
        {
            p=i;
            break;
        }
    if(p==0)
    {
        printf("1");
        return 0;
    }
    dfs(p,0);
    printf("%d",f[p]);
    return 0;
}
