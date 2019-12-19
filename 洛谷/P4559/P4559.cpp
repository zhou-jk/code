#include<iostream>
#include<cstdio>
using namespace std;
const int N=500001;
int n,Q;
int a[N];
long long sum[N];
int m,c;
struct Node
{
    int lc,rc;
    int size;
    long long num;
}tree[N<<5];
int rt[N],tot;
void push_up(int i)
{
    tree[i].num=tree[tree[i].lc].num+tree[tree[i].rc].num;
    tree[i].size=tree[tree[i].lc].size+tree[tree[i].rc].size;
    return;
}
int update(int &x,int l,int r,int u)
{
    int now=++tot;
    tree[now]=tree[x];
    if(l==r)
    {
        tree[now].size++;
        tree[now].num+=u;
        return now;
    }
    int mid=(l+r)/2;
    if(u<=mid) tree[now].lc=update(tree[x].lc,l,mid,u);
    else tree[now].rc=update(tree[x].rc,mid+1,r,u);
    push_up(now);
    return now;
}
long long query(int u,int v,int l,int r,int k)
{
    if(l==r)
    {
        if(tree[u].size-tree[v].size&&l<=k)
        {
            c++;
            return l;
        }
        return 0;
    }
    int mid=(l+r)/2;
    int sum=tree[tree[u].lc].size-tree[tree[v].lc].size;
    if(sum==0||mid<=sum+k-1)
    {
        c+=sum;
        return query(tree[u].rc,tree[v].rc,mid+1,r,k+sum)+tree[tree[u].lc].num-tree[tree[v].lc].num;
    }
    else return query(tree[u].lc,tree[v].lc,l,mid,k);
}
int main()
{
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        m=max(m,a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
        rt[i]=update(rt[i-1],1,m,a[i]);
    while(Q--)
    {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        c=0;
        long long res=query(rt[r],rt[l-1],1,m,k);
        printf("%lld\n",((long long)c*(2*k+c-1)/2)-res+sum[r]-sum[l-1]-res-((long long)(c+2*k+r-l)*(r-l+1-c)/2));
    }
    return 0;
}