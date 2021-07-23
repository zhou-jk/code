#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int M=100005;
const int INF=1061109567*2;
const long long LINF=4557430888798830399;
int n,m;
struct Seg
{
    int t,l,r,c;
}s[M];
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        pair<int,int>mi;
    }tree[M<<2];
    void push_up(int i)
    {
        tree[i].mi=min(tree[i*2].mi,tree[i*2+1].mi);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].mi={INF,l};
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,int v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].mi.first=v;
            return;
        }
        if(u<=tree[i*2].r) modify(i*2,u,v);
        else modify(i*2+1,u,v);
        push_up(i);
        return;
    }
    pair<int,int>query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].mi;
        pair<int,int> res={INF,0};
        if(l<=tree[i*2].r) res=min(res,query(i*2,l,r));
        if(r>=tree[i*2+1].l) res=min(res,query(i*2+1,l,r));
        return res;
    }
}T1,T2;
long long f[M];
bool vis[M];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int t,l,r,c;
        scanf("%d%d%d%d",&t,&l,&r,&c);
        s[i]={t,l,r,c};
    }
    sort(s+1,s+m+1,[=](const Seg &a,const Seg &b){return a.t<b.t;});
    T1.build(1,1,m),T2.build(1,1,m);
    fill(f+1,f+m+1,LINF);
    for(int i=1;i<=m;i++)
        T1.modify(1,i,s[i].l-s[i].t-1),T2.modify(1,i,s[i].l+s[i].t-1);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    for(int i=1;i<=m;i++)
        if(s[i].l==1) f[i]=s[i].c,q.emplace(f[i],i);
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        T1.modify(1,u,INF);
        T2.modify(1,u,INF);
        while(true)
        {
            auto [rt,v]=T1.query(1,1,u);
            if(rt<=s[u].r-s[u].t)
            {
                T1.modify(1,v,INF);
                T2.modify(1,v,INF);
                if(f[v]>f[u]+s[v].c)
                {
                    f[v]=f[u]+s[v].c;
                    q.emplace(f[v],v);
                }
            }
            else break;
        }
        while(true)
        {
            auto [rt,v]=T2.query(1,u,m);
            if(rt<=s[u].r+s[u].t)
            {
                T1.modify(1,v,INF);
                T2.modify(1,v,INF);
                if(f[v]>f[u]+s[v].c)
                {
                    f[v]=f[u]+s[v].c;
                    q.emplace(f[v],v);
                }
            }
            else break;
        }
    }
    long long ans=LINF;
    for(int i=1;i<=m;i++)
        if(s[i].r==n) ans=min(ans,f[i]);
    if(ans>=LINF) printf("-1");
    else printf("%lld",ans);
    return 0;
}