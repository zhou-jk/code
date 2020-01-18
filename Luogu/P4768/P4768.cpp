#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int N=200005;
struct Edge
{
    int to,val,next;
}edge[N<<2];
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
int dis[N];
bool book[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >Q;
void dijkstra(int s)
{
    memset(dis,63,sizeof(dis));
    memset(book,false,sizeof(book));
    dis[s]=0;
    Q.push(make_pair(0,s));
    while(!Q.empty())
    {
        int u=Q.top().second;
        Q.pop();
        if(book[u]) continue;
        book[u]=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!book[v]&&dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                Q.push(make_pair(dis[v],v));
            }
        }
    }
    return;
}
struct Line
{
    int u,v,w,h;
}a[N<<1];
bool cmp(Line x,Line y)
{
    return x.h>y.h;
}
int T,n,m,q,k,s;
struct Chairman_Tree
{
    struct Node
    {
        int lc,rc,val;
    }tree[N*40];
    int tot,b[N],rt[N<<1];
    void build(int &i,int l,int r)
    {
        i=++tot;
        if(l==r)
        {
            tree[i].val=b[l];
            return;
        }
        int mid=(l+r)/2;
        build(tree[i].lc,l,mid);
        build(tree[i].rc,mid+1,r);
        return;
    }
    int update(int i,int l,int r,int u,int v)
    {
        int now=++tot;
        tree[now]=tree[i];
        if(l==r)
        {
            tree[now].val=v;
            return now;
        }
        int mid=(l+r)/2;
        if(u<=mid) tree[now].lc=update(tree[now].lc,l,mid,u,v);
        else tree[now].rc=update(tree[now].rc,mid+1,r,u,v);
        return now;
    }
    int query(int i,int l,int r,int u)
    {
        if(l==r) return tree[i].val;
        int mid=(l+r)/2;
        if(u<=mid) return query(tree[i].lc,l,mid,u);
        else return query(tree[i].rc,mid+1,r,u);
    }
}fa,dep,Min;
int getf(int i,int v)
{
    int f=fa.query(fa.rt[i],1,n,v);
    if(v==f) return v;
    return getf(i,f);
}
void solve()
{
    memset(head,0,sizeof(head));
    cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&a[i].u,&a[i].v,&a[i].w,&a[i].h);
        add_edge(a[i].u,a[i].v,a[i].w);
        add_edge(a[i].v,a[i].u,a[i].w);
    }
    dijkstra(1);
    sort(a+1,a+m+1,cmp);
    fa.tot=dep.tot=Min.tot=0;
    for(int i=1;i<=n;i++)
        fa.b[i]=i,dep.b[i]=1,Min.b[i]=dis[i];
    fa.build(fa.rt[0],1,n);
    dep.build(dep.rt[0],1,n);
    Min.build(Min.rt[0],1,n);
    for(int i=1;i<=m;i++)
    {
        fa.rt[i]=fa.rt[i-1];
        dep.rt[i]=dep.rt[i-1];
        Min.rt[i]=Min.rt[i-1];
        int fx=getf(i,a[i].u),fy=getf(i,a[i].v);
        if(fx==fy) continue;
        int depx=dep.query(dep.rt[i-1],1,n,fx),depy=dep.query(dep.rt[i-1],1,n,fy);
        if(depx>depy) swap(fx,fy);
        fa.rt[i]=fa.update(fa.rt[i-1],1,n,fx,fy);
        int val1=Min.query(Min.rt[i-1],1,n,fx),val2=Min.query(Min.rt[i-1],1,n,fy);
        Min.rt[i]=Min.update(Min.rt[i-1],1,n,fy,min(val1,val2));
        if(depx==depy) dep.rt[i]=dep.update(dep.rt[i-1],1,n,fy,depy+1);
    }
    scanf("%d%d%d",&q,&k,&s);
    int lastans=0;
    while(q--)
    {
        int v0,p0;
        scanf("%d%d",&v0,&p0);
        v0=(v0+k*lastans-1)%n+1;
        p0=(p0+k*lastans)%(s+1);
        int L=1,R=m,ans=-1;
        while(L<=R)
        {
            int mid=(L+R)/2;
            if(a[mid].h>p0) ans=mid,L=mid+1;
            else R=mid-1;
        }
        if(ans==-1)
        {
            lastans=dis[v0];
            printf("%d\n",lastans);
            continue;
        }
        lastans=Min.query(Min.rt[ans],1,n,getf(ans,v0));
        printf("%d\n",lastans);
    }
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}