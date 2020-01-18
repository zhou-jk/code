#include<iostream>
#include<cstdio>
using namespace std;
const int N=400005,LOG=20;
int n,m;
struct Node
{
    int lc,rc;
    pair<int,long long>lsum,rsum;
}tree[N];
int rt[N],tot;
int root;
int dep[N],f[N][LOG];
void build(int &i,int l,int r)
{
    i=++tot;
	if(l==r)
    {
		rt[l]=i;
		return;
	}
	int mid;
    scanf("%d",&mid);
	build(tree[i].lc,l,mid);
	f[tree[i].lc][0]=i;
	build(tree[i].rc,mid+1,r);
	f[tree[i].rc][0]=i;
	return;
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=LOG-1;i>=0;i--)
    {
        if(dep[f[u][i]]>=dep[v]) u=f[u][i];
	    if(u==v) return u;
    }
	for(int i=LOG-1;i>=0;i--)
		if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}
int jump(int u,int v)
{
	for(int i=LOG-1;i>=0;i--)
		if(dep[f[u][i]]>dep[v]) u=f[u][i];
	return u;
}
void dfs(int u,int father)
{
	dep[u]=dep[father]+1;
	for (int i=1;i<LOG;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	if(tree[u].lc) dfs(tree[u].lc,u);
	if(tree[u].rc) dfs(tree[u].rc,u);
    return;
}
void Dfs(int u,int father)
{
	if(tree[u].lc)
    {
		tree[tree[u].lc].lsum=tree[u].lsum;
		tree[tree[u].lc].rsum=tree[u].rsum;
		tree[tree[u].lc].rsum.first++;
		tree[tree[u].lc].rsum.second+=dep[tree[u].rc];
		Dfs(tree[u].lc,u);
	}
	if(tree[u].rc)
    {
        tree[tree[u].rc].lsum=tree[u].lsum;
		tree[tree[u].rc].rsum=tree[u].rsum;
		tree[tree[u].rc].lsum.first++;
		tree[tree[u].rc].lsum.second+=dep[tree[u].lc];
		Dfs(tree[u].rc,u);
	}
    return;
}
int main()
{
    scanf("%d",&n);
	build(root,1,n);
	rt[0]=++tot;
	tree[tot+1].lc=tot;
	f[tot][0]=tot+1;
	tree[tot+1].rc=1;
	f[1][0]=++tot;
	rt[n+1]=++tot;
	tree[tot+1].lc=tot-1;
	f[tot-1][0]=tot+1;
	tree[tot+1].rc=tot;
	f[tot][0]=tot+1;
    root=++tot;
	dfs(root,0);
	Dfs(root,0);
	scanf("%d",&m);
    while(m--)
    {
		int u,l,r;
        scanf("%d%d%d",&u,&l,&r);
		l=rt[l-1],r=rt[r+1];
		int lca=LCA(l,r),tl=jump(l,lca),tr=jump(r,lca);
		long long ans=tree[l].rsum.second-tree[tl].rsum.second+tree[r].lsum.second-tree[tr].lsum.second;
        long long cnt=tree[l].rsum.first-tree[tl].rsum.first+tree[r].lsum.first-tree[tr].lsum.first;
		ans+=cnt*dep[u];
		if(u==lca||LCA(u,lca)!=lca)
        {
			int v=LCA(u,lca);
			ans-=(long long)2*cnt*dep[v];
		}
        else if(LCA(u,l)!=lca)
        {
			int v=LCA(u,l);
			ans-=(long long)2*(tree[r].lsum.first-tree[tr].lsum.first)*dep[lca];
			ans-=(long long)2*(tree[l].rsum.first-tree[v].rsum.first)*dep[v];
			ans-=(long long)2*(tree[v].rsum.second-tree[tl].rsum.second-(tree[v].rsum.first-tree[tl].rsum.first));
			if(v!=u&&jump(u,v)==tree[v].rc) ans-=2;
		}
        else
        {
			int v=LCA(u,r);
			ans-=(long long)2*(tree[l].rsum.first-tree[tl].rsum.first)*dep[lca];
			ans-=(long long)2*(tree[r].lsum.first-tree[v].lsum.first)*dep[v];
			ans-=(long long)2*(tree[v].lsum.second-tree[tr].lsum.second-(tree[v].lsum.first-tree[tr].lsum.first));
			if(v!=u&&jump(u,v)==tree[v].lc) ans-=2;
		}
        printf("%lld\n",ans);
	}
	return 0;
}