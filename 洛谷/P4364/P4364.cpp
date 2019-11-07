#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=500001;
int n;
double K;
int a[N],ans[N],size[N];
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
struct Node
{
    int l,r;
    int sum;
}tree[N<<2];
void push_up(int i)
{
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    tree[i].sum=0;
    if(l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void update(int i,int u,int v)
{
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum+=v;
        return;
    }
    if(u<=tree[i*2].r) update(i*2,u,v);
    else update(i*2+1,u,v);
    push_up(i);
    return;
}
int query(int i,int k)
{
    if(tree[i].l==tree[i].r) return tree[i].l;
    if(tree[i*2+1].sum<k) return query(i*2,k-tree[i*2+1].sum);
    else return query(i*2+1,k);
}
int main()
{
    scanf("%d%lf",&n,&K);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),size[i]=1;
    sort(a+1,a+n+1);
    for(int i=n;i>0;i--)
        add_edge((int)floor(i/K),i),size[(int)floor(i/K)]+=size[i];
    build(1,1,n);
    for(int i=head[0];i;i=edge[i].next)
    {
        int v=edge[i].to;
        update(1,v,size[v]);
    }
    int pre=1;
    for(int j=1;j<=n;j=pre)
    {
        while(pre<=n&&a[j]==a[pre]) pre++;
        for(int k=pre-j;k>0;k--)
        {
            int u=query(1,k);
            ans[u]=a[j];
            update(1,u,-size[u]);
            for(int i=head[u];i;i=edge[i].next)
            {
                int v=edge[i].to;
                update(1,v,size[v]);
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}