#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100001;
int n,m;
int a[N];
struct Line
{
    int u,p,flag;
}s[N*2];
int q;
bool cmp(Line a,Line b)
{
    return a.u<b.u;
}
struct Node
{
    int lc,rc;
    int size;
    long long sum;
}tree[N*40];
int rt[N],tot;
void push_up(int i)
{
    tree[i].sum=tree[tree[i].lc].sum+tree[tree[i].rc].sum;
    tree[i].size=tree[tree[i].lc].size+tree[tree[i].rc].size;
    return;
}
void build(int &i,int l,int r)
{
    i=++tot;
    if(l==r) return;
    int mid=(l+r)/2;
    build(tree[i].lc,l,mid);
    build(tree[i].rc,mid+1,r);
    return;
}
int update(int i,int l,int r,int u,int val)
{
    int now=++tot;
    tree[now]=tree[i];
    if(l==r)
    {
        tree[now].sum+=val*a[u];
        tree[now].size+=val;
        return now;
    }
    int mid=(l+r)/2;
    if(u<=mid) tree[now].lc=update(tree[now].lc,l,mid,u,val); 
    else tree[now].rc=update(tree[now].rc,mid+1,r,u,val);
    push_up(now);
    return now;
}
long long query(int i,int l,int r,int k)
{
    if(l==r) return tree[i].sum/tree[i].size*(long long)k;
    int mid=(l+r)/2;
    int sum=tree[tree[i].lc].size;
    if(sum>=k) return query(tree[i].lc,l,mid,k);
    else return query(tree[i].rc,mid+1,r,k-sum)+tree[tree[i].lc].sum;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        s[++q].u=x,s[q].p=z,s[q].flag=1;
        s[++q].u=y+1,s[q].p=z,s[q].flag=-1;
        a[i]=z;
    }
    sort(a+1,a+n+1);
    sort(s+1,s+q+1,cmp);
    build(rt[0],1,m);
    int j=1;
    for(int i=1;i<=m;i++)
    {
        rt[i]=rt[i-1];
        while(j<=q&&s[j].u==i)
        {
            int p=lower_bound(a+1,a+n+1,s[j].p)-a;
            rt[i]=update(rt[i],1,m,p,s[j].flag);
            j++;
        }
    }
    long long pre=1;
    for(int i=1;i<=m;i++)
    {
        int x,a,b,c;
        scanf("%d%d%d%d",&x,&a,&b,&c);
        long long k=1+(a*pre+b)%c;
        if(k>=tree[rt[x]].size) pre=tree[rt[x]].sum;
        else pre=query(rt[x],1,m,k);
        printf("%lld\n",pre);
    }
    return 0;
}