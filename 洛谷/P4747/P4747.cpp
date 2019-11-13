#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100020;
int a[N],pos[N],ans[N][2],tt,n,m;

struct Ask
{
    int l,r,id;
    bool operator <(const Ask &b)const
    {
        return l<b.l;
    }
};
struct Node
{
    int w,p;
    Node operator +(const Node &b)const
    {
        Node c;
        if(w>b.w) c.w=w,c.p=p;
        else c.w=b.w,c.p=b.p;
        return c;
    }
};
struct 
{
    int l,r;
    Node sum;
    int lazy;
}tree[N*4];
vector<Ask> v[N];
priority_queue<Ask> q;
void change(int i,int w)
{
    tree[i].sum.w+=w;
    tree[i].lazy+=w;
}
void push_up(int i)
{
    if(tree[i*2].sum.w>tree[i*2+1].sum.w) tree[i].sum.w=tree[i*2].sum.w,tree[i].sum.p=tree[i*2].sum.p;
    else tree[i].sum.w=tree[i*2+1].sum.w,tree[i].sum.p=tree[i*2+1].sum.p;
    return;
}
void down(int i)
{
    change(i*2,tree[i].lazy);change(i*2+1,tree[i].lazy);
    tree[i].lazy=0;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;tree[i].lazy=0;
    if(l==r)
    {
        tree[i].sum.p=tree[i].sum.w=l;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void add(int i,int x,int y)
{
    int l=tree[i].l,r=tree[i].r,mid=l+r>>1;
    if(l==x&&r==y){change(i,1);return;}
    if(tree[i].lazy) down(i);
    if(y<=mid) add(i*2,x,y);
    else if(x>mid) add(i*2+1,x,y);
    else add(i*2,x,mid),add(i*2+1,mid+1,y);
    push_up(i);
}
Node ask(int i,int x,int y)
{
    int l=tree[i].l,r=tree[i].r,mid=l+r>>1;
    if(l==x&&r==y) return tree[i].sum;
    if(tree[i].lazy) down(i);
    if(y<=mid) return ask(i*2,x,y);
    else if(x>mid) return ask(i*2+1,x,y);
    return ask(i*2,x,mid)+ask(i*2+1,mid+1,y);
}
int main()
{
    scanf("%d",&n);
    build(1,1,n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),pos[a[i]]=i;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        v[r].push_back((Ask){l,r,i});
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]-1>=1&&pos[a[i]-1]<i) add(1,1,pos[a[i]-1]);
        if(a[i]+1<=n&&pos[a[i]+1]<i) add(1,1,pos[a[i]+1]);
        for(int j=0;j<v[i].size();j++)
            q.push(v[i][j]);
        while(!q.empty())
        {
            Ask u=q.top();
            Node res=ask(1,1,u.l);
            if(res.w!=i) break;
            else
            {
                ans[u.id][0]=res.p,ans[u.id][1]=i;
                q.pop();
            }
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d %d\n",ans[i][0],ans[i][1]);
    return 0;
}