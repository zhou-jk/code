#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct Edge
{
	int to,next;
}edge[200001];
int head[10001],cnt;
void add_edge(int u,int v)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
	return;
}
queue<int>q;
int n,m,res,x,y,ans[2],color[200001];
bool book[200001];
void bfs(int x)
{
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        book[u]=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(color[v]==color[u])
            {
                ans[0]=ans[1]=-1;
                return;
            }  
            if(!book[v])
            {
                q.push(v);
                color[v]=(color[u]+1)%2;
                ans[color[v]]++;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(color,-1,sizeof(color));
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!book[i])  
        {
            ans[0]=1;
            ans[1]=0;
            color[i]=0;
            q.push(i);
            bfs(i);
            if(ans[0]==-1)
            {
                printf("Impossible");
                return 0;
            }
            res+=min(ans[0],ans[1]);
        }
    }
    printf("%d",res);
    return 0;
}