#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int s1,t1,s2,t2;
int f1[2001],g1[2001],f2[2001],g2[2001],in[2001];
int len1,len2,ans;
bool book[2001];
int f[2001];
struct
{
    int to,val,next;
}edge[1000001],Edge[1000001];
int head[2001],cnt;
int Head[2001],Cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void add(int u,int v,int w)
{
    Cnt++;
    Edge[Cnt].to=v;
    Edge[Cnt].val=w;
    Edge[Cnt].next=Head[u];
    Head[u]=Cnt;
    return;
}
void spfa(int *dis,int s)
{
	memset(book,false,sizeof(book));
	dis[s]=0;
    book[s]=true;
	queue<int>q;
	q.push(s);
	while (!q.empty())
	{
        int u=q.front();
        q.pop();
        book[u]=false;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                if(!book[v])
                {
                    book[v]=true;
                    q.push(v);
                }
            }
        }
	}
    return;
}
int dp()
{
	memset(f,0,sizeof(f));
    queue<int>q;
    int res=0;
    for(int i=1;i<=n;i++)
        if(in[i]==0) q.push(i);
    while(!q.empty())
	{
        int u=q.front();
        q.pop();
        for(int i=Head[u];i;i=Edge[i].next)
        {
            int v=Edge[i].to;
            f[v]=f[u]+Edge[i].val;
            in[v]--;
            if(in[v]==0) q.push(v);
        }
	}
	for(int i=1;i<=n;i++)
	    res=max(res,f[i]);
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&s1,&t1,&s2,&t2);
    for (int i=1;i<=m;i++)
    {
     	int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    memset(f1,63,sizeof(f1));
    memset(g1,63,sizeof(g1));
    memset(f2,63,sizeof(f2));
    memset(g2,63,sizeof(g2));
    spfa(f1,s1); len1=f1[t1];
    spfa(g1,t1);
    spfa(f2,s2); len2=f2[t2];
    spfa(g2,t2);
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(f1[u]+g1[v]+edge[i].val==len1&&f2[u]+g2[v]+edge[i].val==len2)
                add(u,v,edge[i].val),in[v]++;
        }
    ans=max(ans,dp());
    memset(f2,63,sizeof(f2));
    memset(g2,63,sizeof(g2));
    spfa(f2,t2);
    spfa(g2,s2);
    Cnt=0;
    memset(in,0,sizeof(in));
    memset(Head,0,sizeof(Head));
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(f1[u]+g1[v]+edge[i].val==len1&&f2[u]+g2[v]+edge[i].val==len2)
                add(u,v,edge[i].val),in[v]++;
        }
    ans=max(ans,dp());
    printf("%d",ans);
    return 0;
}