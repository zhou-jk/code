#include<iostream>
#include<cstdio>
using namespace std;
const int N=400001,M=2000001;
int n,s,m;
struct Edge
{
    int to,val,next;
}edge[M];
int head[N],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int in[N];
struct Node
{
    int ls,rs;
}tree[N];
int root;
int a[N],pos[N],tot;
int f[N],sum;
void push_up(int i)
{
    add_edge(tree[i].ls,i,0);
    in[i]++;
    add_edge(tree[i].rs,i,0);
    in[i]++;
    return;
}
void build(int &i,int l,int r)
{
	i=++tot;
	if(l==r)
    {
        pos[l]=tot;
        return;
    }
	int mid=(l+r)/2;
	build(tree[i].ls,l,mid);
	build(tree[i].rs,mid+1,r);
	push_up(i);
    return;
}
void update(int i,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
    {
        add_edge(i,tot,1);
        in[tot]++;
        return;
    }
	int mid=(l+r)/2;
	if(L<=mid) update(tree[i].ls,l,mid,L,R);
	if(R>mid) update(tree[i].rs,mid+1,r,L,R);
    return;
}
void dfs(int u)
{
	sum++;
	if(f[u]>1000000000)
    {
        printf("NIE");
        exit(0);
    }
	if(a[u])
    {
        if(f[u]>a[u])
        {
            printf("NIE");
            exit(0);
        }
        f[u]=a[u];
    }
	in[u]=-1;
	for (int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
        in[v]--;
		f[v]=max(f[v],f[u]+edge[i].val);
		if(in[v]==0) dfs(v);
	}
    return;
}
int main()
{
	scanf("%d%d%d",&n,&s,&m);
	build(root,1,n);
	for (int i=1;i<=s;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[pos[x]]=y;
    }
	for (int i=1;i<=m;i++)
	{
		int cnt,r,x,y;
        tot++;
		scanf("%d%d%d",&cnt,&r,&x);
		for(int j=1;j<=x;j++)
		{
			scanf("%d",&y);
			add_edge(tot,pos[y],0);
            in[pos[y]]++;
			if(cnt<y) update(root,1,n,cnt,y-1);
			cnt=y+1;
		}
		if(cnt<=r) update(root,1,n,cnt,r);
	}
	for(int i=1;i<=tot;i++)
		if(!in[i]) f[i]=1,dfs(i);
	if(sum<tot)
    {
        printf("NIE");
        return 0;
    }
	printf("TAK\n");
	for (int i=1;i<=n;i++)
		printf("%d ",f[pos[i]]);
    return 0;
}