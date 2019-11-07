#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
int n,m;
int ans;
int ans1[50001],ans2[50001];
struct Edge
{
    int next,to;
}edge[100001];
int head[50001],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int Index,dfn[50001],low[50001];
bool book[50001];
stack<int>s;
void tarjan(int u)
{
    dfn[u]=low[u]=++Index;
    s.push(u);
    book[u]=true;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(book[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        int tot=0;
        while(s.top()!=u)
        {
            ans1[++tot]=s.top();
            book[s.top()]=false;
            s.pop();
        }
        ans1[++tot]=u;
        book[u]=false;
        s.pop();
        if(tot>ans)
        {
            memset(ans2,0,sizeof(ans2));
            ans=tot;
            for(int i=1;i<=tot;i++)
                ans2[i]=ans1[i];
            sort(ans2+1,ans2+ans+1);
        }
        if(tot==ans)
        {
            sort(ans1+1,ans1+ans+1);
            if(ans1[1]<ans2[1]) 
            {
                memset(ans2,0,sizeof(ans2));
                for(int i=1;i<=ans;i++)
                    ans2[i]=ans1[i];
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y);
        if(z==2) add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        if(ans2[i]) printf("%d ",ans2[i]);
    return 0;
}