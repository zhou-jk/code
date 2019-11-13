#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1000001;
int n,k;
struct Edge
{
    int to,next;
}edge[2*N];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int root=1,in[N];
int dis[N];
int ans=1;
int dfs(int u,int father)
{
    if(in[u]==1) return 0;
    vector<int>s;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        s.push_back(dfs(v,u)+1);
    }
    sort(s.begin(),s.end());
    for(int i=s.size()-1;i>0;i--)
        if(s[i]+s[i-1]>k) ans++;
        else return s[i];
    return s[0];
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
        in[x]++,in[y]++;
    }
    while(in[root]==1) root++;
    dfs(root,0);
    printf("%d",ans);
    return 0;
}