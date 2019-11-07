#include<iostream>
#include<cstdio>
using namespace std;
struct Edge
{
    int to,next;
}edge[400001];
int head[400001],cnt;
int x[400001],y[400001];
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int n,m,K;
int f[400001],ans[400001],a[400001],s;
bool book[400001];
int getf(int v)
{
    if(v==f[v]) return v;
    f[v]=getf(f[v]);
    return f[v];
}
bool merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2)
    {
        f[f2]=f1;
        return true;
    }
    return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
		add_edge(x[i],y[i]);
        add_edge(y[i],x[i]);
	}
	scanf("%d",&K);
	for(int i=1;i<=K;i++)
    {
		scanf("%d",&a[i]);
		book[a[i]]=1;
	}
    s=n-K;
	for(int i=0;i<n;i++)
        f[i]=i;
	for(int i=1;i<=m;i++)
	    if(!book[x[i]]&&!book[y[i]])
            if(merge(x[i],y[i])) s--;
	for(int k=K;k>0;k--)
    {
	    ans[k]=s;
        int u=a[k];
        book[u]=false;
        s++;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(book[v]) continue;
            if(merge(u,v)) s--;
        }
	}
    printf("%d\n",s);
	for(int i=1;i<=K;i++)
	    printf("%d\n",ans[i]);
	return 0;
}