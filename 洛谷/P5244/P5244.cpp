#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=300005,T=1000005;
const long long INF=4557430888798830399;
int t,n,m,s;
struct Node
{
    int x,y;
}a[N];
bool cmp(Node a,Node b)
{
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
int nxt[N];
long long dp[N];
vector<int> pos[N];
struct Binary_Indexed_Tree
{
    int C[T];
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=t;i+=lowbit(i))
            C[i]=max(C[i],y);
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res=max(res,C[i]);
        return res;
    }
}BIT;

struct Segment_Tree
{
    struct Node
    {
        int lc,rc;
        vector<int> sum;
    }tree[N<<1];
    int n,tot;
    int rt;
    vector<int> point,tmp;
    void build(int &i,int l,int r)
    {
        i=++tot;
        tree[i].lc=tree[i].rc=0;
        tree[i].sum.clear();
        if(l==r) return;
        int mid=(l+r)/2;
        build(tree[i].lc,l,mid);
        build(tree[i].rc,mid+1,r);
        return;
    }
    void Init(vector<int> tmp)
    {
        point=tmp;
        n=tmp.size();
        rt=tot=0;
        build(rt,0,n-1);
        return;
    }
    void update(int i,int l,int r,int x)
    {
        if(a[x].x>=a[point[r]].x&&a[x].y>=a[point[l]].y)
        {
            tree[i].sum.push_back(x);
            return;
        }
        if(a[x].x<=a[point[l]].x||a[x].y<=a[point[r]].y) return;
        int mid=(l+r)/2;
        update(tree[i].lc,l,mid,x);
        update(tree[i].rc,mid+1,r,x);
        return;
    }
    void ask(int l,int r,int L,int R)
    {
        int mid=(l+r)/2,now=tmp[mid];
        long long ans=INF;
        int u=0;
        for(int i=L;i<=R;i++)
        {
            int pos=point[i];
            long long res=dp[pos]+(long long)(a[now].x-a[pos].x)*(a[now].y-a[pos].y);
            if(res<ans) ans=res,u=i;
        }
        dp[now]=min(dp[now],ans);
        if(l<mid) ask(l,mid-1,u,R);
        if(mid<r) ask(mid+1,r,L,u);
        return;
    }
    void query(int i,int l,int r)
    {
        if(!tree[i].sum.empty())
        {
            tmp=tree[i].sum;
            ask(0,tree[i].sum.size()-1,l,r);
        }
        if(l==r) return;
        int mid=(l+r)/2;
        query(tree[i].lc,l,mid);
        query(tree[i].rc,mid+1,r);
        return;
    }
}Tree;
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        nxt[i]=BIT.getsum(a[i].y)+1;
        BIT.add(a[i].y,nxt[i]);
        pos[nxt[i]].push_back(i);
        m=max(m,nxt[i]);
    }
    for(auto now:pos[1])
        dp[now]=(long long)a[now].x*a[now].y;
    for(int i=2;i<=m;i++)
    {
        Tree.Init(pos[i-1]);
        for(auto now:pos[i])
        {
            dp[now]=INF;
            Tree.update(Tree.rt,0,Tree.n-1,now);
        }
        Tree.query(Tree.rt,0,Tree.n-1);
    }
    long long ans=INF;
    for(auto now:pos[m])
        ans=min(ans,dp[now]+(long long)(t-a[now].x)*(t-a[now].y));
    printf("%lld",ans);
    return 0;
}