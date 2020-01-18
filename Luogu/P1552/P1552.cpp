#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100001;
int n,m;
struct Edge
{
    int to,next;
}edge[N];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int b[N],num;
int c[N],v[N];
struct Node
{
    int ls,rs;
    int size;
    long long sum;
}tree[N*20];
int rt[N],root;
long long ans;
void push_up(int i)
{
    tree[i].size=tree[tree[i].ls].size+tree[tree[i].rs].size;
    tree[i].sum=tree[tree[i].ls].sum+tree[tree[i].rs].sum;
    return;
}
void update(int &i,int l,int r,int u)
{
    if(!i) i=++root;
    if(l==r)
    {
        tree[i].size=1;
        tree[i].sum=b[l];
        return;
    }
    int mid=(l+r)/2;
    if(u<=mid) update(tree[i].ls,l,mid,u);
    else update(tree[i].rs,mid+1,r,u);
    push_up(i);
    return;
}
int merge(int l,int r,int i,int u)
{
    if(!i) return u;
    if(!u) return i;
    if(l==r)
    {
        tree[i].size+=tree[u].size;
        tree[i].sum+=tree[u].sum;
        return i;
    }
    int mid=(l+r)/2;
    tree[i].ls=merge(l,mid,tree[i].ls,tree[u].ls);
    tree[i].rs=merge(mid+1,r,tree[i].rs,tree[u].rs);
    push_up(i);
    return i;
}
int find(int i,int l,int r,long long now,int tot)
{
    if(l==r)
    {
        if(now+tree[i].sum<=m) tot+=tree[i].size;
        else
        {
            long long tmp=now;
            for(int j=log2(tree[i].size);j>=0;j--)
                if((1<<j)*b[l]+tmp<=m) tot+=(1<<j),tmp+=(1<<j)*b[l];
        }
        return tot;
    }
    int mid=(l+r)/2;
    if(tree[tree[i].ls].sum+now>=m) return find(tree[i].ls,l,mid,now,tot);
    else return find(tree[i].rs,mid+1,r,now+tree[tree[i].ls].sum,tot+tree[tree[i].ls].size);
}
void dfs(int u)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        dfs(v);
        rt[u]=merge(1,num,rt[u],rt[v]);
    }
    ans=max(ans,(long long)v[u]*find(rt[u],1,num,0,0));
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,d;i<=n;i++)
    {
        scanf("%d%d%d",&d,&c[i],&v[i]);
        add_edge(d,i);
        b[i]=c[i];
    }
    sort(b+1,b+n+1);
    num=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++)
        c[i]=lower_bound(b+1,b+num+1,c[i])-b;
    for(int i=1;i<=n;i++)
        update(rt[i],1,num,c[i]);
    dfs(1);
    printf("%lld",ans);
    return 0;
}