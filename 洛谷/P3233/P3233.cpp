#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=300001;
int n,m,Q;
int a[N],b[N],f[N];
struct Edge
{
	int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int fa[N][19],dep[N];
int dfn[N],Index,size[N];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
	dfn[u]=++Index;
    size[u]=1;
    fa[u][0]=father;
	for(int i=1;(1<<i)<=n;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
        size[u]+=size[v];
    }
    return;
}
bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}
int querylca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
    for(int i=log2(n);i>=0;i--)
    {
        if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
        if(u==v) return u;
    }
	for(int i=log2(n);i>=0;i--)
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
inline int dis(int a,int b)
{
	return dep[a]+dep[b]-2*dep[querylca(a,b)];
}
int sum[N],belong[N];
void query(int a,int b)
{
	int u=b,mid=b;
	for(int i=log2(n);i>=0;i--)
		if(dep[fa[u][i]]>dep[a]) u=fa[u][i];
	sum[a]-=size[u];
	if(belong[a]==belong[b])
	{
		f[belong[a]]+=size[u]-size[b];
		return;
	}
	for(int i=log2(n);i>=0;i--)
	{
		if(dep[fa[mid][i]]<=dep[a])continue;
		int t1=dis(belong[a],fa[mid][i]),t2=dis(belong[b],fa[mid][i]);
		if(t1>t2||(t1==t2&&belong[b]<belong[a])) mid=fa[mid][i];
	}
	f[belong[a]]+=size[u]-size[mid],f[belong[b]]+=size[mid]-size[b];
    return;
}
int top,s[N],c[N];
void dfs1(int u)
{
	c[++Index]=u;
    sum[u]=size[u];
	for(int i=head[u];i;i=edge[i].next)
	{
        int v=edge[i].to;
		dfs1(v);
		if(!belong[v]) continue;
		int t1=dis(belong[v],u),t2=dis(belong[u],u);
		if((t1==t2&&belong[v]<belong[u])||t1<t2||!belong[u]) belong[u]=belong[v];
	}
    return;
}
void dfs2(int u)
{
	for(int i=head[u];i;i=edge[i].next)
	{
        int v=edge[i].to;
		int t1=dis(belong[u],v),t2=dis(belong[v],v);
		if((t1==t2&&belong[v]>belong[u])||t1<t2||!belong[v])
			belong[v]=belong[u];
		dfs2(v);
	}
    return;
}
void solve()
{
	top=Index=cnt=0;
    scanf("%d",&m);
	for(int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
	for(int i=1;i<=m;i++)
        belong[a[i]]=a[i];
	sort(a+1,a+m+1,cmp);
	if(belong[1]!=1) s[++top]=1;
    for(int i=1;i<=m;i++)
	{
		int t=a[i],lca=0;
		while(top>0)
		{
			lca=querylca(s[top],t);
			if(top>1&&dep[lca]<dep[s[top-1]]) add_edge(s[top-1],s[top]),top--;
			else if(dep[lca]<dep[s[top]])
			{
				add_edge(lca,s[top--]);
                break;
			}
			else break;
		}
		if(s[top]!=lca) s[++top]=lca;
		s[++top]=t;
	}
	while(top>1)
        add_edge(s[top-1],s[top]),top--;
	dfs1(1);
    dfs2(1);
	for(int i=1;i<=Index;i++)
    {
        int u=c[i];
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            query(u,v);
        }
    }
	for(int i=1;i<=Index;i++)
        f[belong[c[i]]]+=sum[c[i]];
	for(int i=1;i<=m;i++)
        printf("%d ",f[b[i]]);
    printf("\n");
	for(int i=1;i<=Index;i++)
		f[c[i]]=belong[c[i]]=head[c[i]]=sum[c[i]]=0;
    return;
}
int main()
{
    scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
	}
	dfs(1,0);
	memset(head,0,sizeof(head));
	scanf("%d",&Q);
	while(Q--)
        solve();
	return 0;
}