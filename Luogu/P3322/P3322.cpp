#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define abs(x) ((x)>=0?(x):(-x))
int vis[200001];
bool book[(1<<12)+1];
int n;
int st[200],ed[200];
struct Node
{
    int num,dep;
}tree[1000050];
long long ans;
void build(int i,int l,int r,int deep,int father)
{
    tree[i].dep=deep;
    st[deep]=min(st[deep],i);
    ed[deep]=max(ed[deep],i);
    if(l==r)
    {
        scanf("%d",&tree[i].num);
        return;
    }
    int mid=(l+r)/2;
    if(l<=mid) build(i*2,l,mid,deep+1,i);
    if(mid+1<=r) build(i*2+1,mid+1,r,deep+1,i);
    return;
}
bool check(int x,int deep)
{
    if(abs(tree[x*2].num-tree[x*2+1].num)>(1<<(n-deep-1))) return false;
    if(tree[x*2].num>tree[x*2+1].num) return false;
    return true;
}
void update(int deep)
{
    for(int i=st[deep];i<=ed[deep];i++)
        tree[i].num=max(tree[i*2].num,tree[i*2+1].num);
    return;
}
void dfs(int root,int deep,int state)
{
    if(deep==-1)
    {
        if(book[state]) return;
        book[state]=true;
        long long res=1;
        for(int i=2;i<=root;i++) res*=i;
        ans+=res;
        return;
    }
    int cnt=0;
    for(int i=st[deep];i<=ed[deep];i++)
        if(!check(i,deep)) vis[++cnt]=i;
    if(cnt>=3) return;
    else if(cnt==2)
    {
        int p1=vis[1],p2=vis[2];
        swap(tree[p1*2],tree[p2*2]);
        if(check(p1,deep)&&check(p2,deep))
        {
            update(deep);
            dfs(root+1,deep-1,state|(1<<deep));
        }
        swap(tree[p1*2],tree[p2*2]);
        update(deep);
        swap(tree[p1*2+1],tree[p2*2]);
        if(check(p1,deep)&&check(p2,deep))
        {
            update(deep);
            dfs(root+1,deep-1,state|(1<<deep));
        }
        swap(tree[p1*2+1],tree[p2*2]);
        update(deep);
        swap(tree[p1*2],tree[p2*2+1]);
        if(check(p1,deep)&&check(p2,deep))
        {
            update(deep);
            dfs(root+1,deep-1,state|(1<<deep));
        }
        swap(tree[p1*2],tree[p2*2+1]);
        update(deep);
        swap(tree[p1*2+1],tree[p2*2+1]);
        if(check(p1,deep)&&check(p2,deep))
        {
            update(deep);
            dfs(root+1,deep-1,state|(1<<deep));
        }
        swap(tree[p1*2+1],tree[p2*2+1]);
        update(deep);
    }
    else if(cnt==1)
    {
        int p=vis[1];
        if(abs(tree[p*2].num-tree[p*2+1].num)>(1<<(n-deep))) return;
        swap(tree[p*2],tree[p*2+1]);
        update(deep);
        dfs(root+1,deep-1,state|(1<<deep));
        swap(tree[p*2],tree[p*2+1]);
        update(deep);
    }
    else if(cnt==0)
    {
        update(deep);
        dfs(root,deep-1,state);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    memset(st,127,sizeof(st));
    memset(ed,0,sizeof(ed));
    build(1,1,1<<n,0,0);
    dfs(0,n-1,0);
    printf("%lld",ans);
    return 0;
}