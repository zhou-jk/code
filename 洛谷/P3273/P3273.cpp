#include<iostream>
#include<cstdio>
using namespace std;
const int N=300005;
const int INF=1061109567;
int n,Q;
int a[N];
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
int dfn[N],w[N],Index;
bool book[N];
int L[N],R[N];
void dfs(int u)
{
    L[u]=R[u]=dfn[u]=++Index;
    w[Index]=u;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        dfs(v);
    }
    return;
}
struct Node
{
    int l,r;
    int Max,lazy;
}tree[N<<2];
void push_up(int i)
{
    tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);
    return;
}
void push_down(int i)
{
    if(!tree[i].lazy) return;
    tree[i*2].Max+=tree[i].lazy;
    tree[i*2].lazy+=tree[i].lazy;
    tree[i*2+1].Max+=tree[i].lazy;
    tree[i*2+1].lazy+=tree[i].lazy;
    tree[i].lazy=0;
    return;
}
void build(int i,int l,int r)
{
    tree[i].Max=-INF;
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].Max=a[w[l]];
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void update(int i,int l,int r,int val)
{
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].Max+=val,tree[i].lazy+=val;
        return;
    }
    push_down(i); 
    if(l<=tree[i*2].r) update(i*2,l,r,val);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r,val);
    push_up(i);
    return;
} 
int query(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Max;
    push_down(i);
    int res=-INF;
    if(l<=tree[i*2].r) res=max(res,query(i*2,l,r));
    if(r>=tree[i*2+1].l) res=max(res,query(i*2+1,l,r));
    return res;
}
int fa[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    fa[v]=getf(fa[v]);
    return fa[v];
}
struct Ask
{
    int type,x,y;
}q[N];
int X[N],Y[N],tot;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        char s[3];
        scanf("%s",s);
        if(s[0]=='U')
        {
            q[i].type=1;
            scanf("%d%d",&q[i].x,&q[i].y);
            int fx=getf(q[i].x),fy=getf(q[i].y);
            if(fx==fy) continue;
            fa[fy]=fx;
            tot++;
            X[tot]=fx,Y[tot]=fy;
        }
        if(s[0]=='A')
        {
            if(s[1]=='1')
            {
                q[i].type=2;
                scanf("%d%d",&q[i].x,&q[i].y);
            }
            if(s[1]=='2')
            {
                q[i].type=3;
                scanf("%d%d",&q[i].x,&q[i].y);
            }
            if(s[1]=='3')
            {
                q[i].type=4;
                scanf("%d",&q[i].x);
            }
        }
        if(s[0]=='F')
        {
            if(s[1]=='1')
            {
                q[i].type=5;
                scanf("%d",&q[i].x);
            }
            if(s[1]=='2')
            {
                q[i].type=6;
                scanf("%d",&q[i].x);
            }
            if(s[1]=='3') q[i].type=7;
        }
    }
    for(int i=tot;i>0;i--)
        add_edge(X[i],Y[i]); 
    for(int i=1;i<=n;i++)
        if(!book[getf(i)])
        {
            dfs(getf(i));
            book[getf(i)]=true;
        }
    for(int i=1;i<=n;i++)
        fa[i]=i;
    build(1,1,n);
    for(int i=1;i<=Q;i++)
    {    
        if(q[i].type==1)
        {
            int fx=getf(q[i].x),fy=getf(q[i].y);
            if(fx==fy) continue;
            L[fx]=min(L[fx],L[fy]),R[fx]=max(R[fx],R[fy]);
            fa[fy]=fx;
        }
        if(q[i].type==2) update(1,dfn[q[i].x],dfn[q[i].x],q[i].y);
        if(q[i].type==3)
        {
            int fx=getf(q[i].x);
            update(1,L[fx],R[fx],q[i].y);
        } 
        if(q[i].type==4) update(1,1,n,q[i].x);
        if(q[i].type==5) printf("%d\n",query(1,dfn[q[i].x],dfn[q[i].x]));
        if(q[i].type==6)
        {
            int fx=getf(q[i].x);
            printf("%d\n",query(1,L[fx],R[fx]));
        }
        if(q[i].type==7) printf("%d\n",query(1,1,n));
    }
    return 0;
}