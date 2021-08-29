#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<int,int> Point;
#define x first
#define y second
const int M=500005,Q=1000005;
const int INF=1061109567;
int n,m,q;
Point p[M+Q];
int cnt;
struct Operation
{
    int t,l;
}op[M+Q];
int tot;
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        int mi;
        int pq;
    }tree[(M+Q)*4];
    void push_up(int i)
    {
        tree[i].mi=min(tree[i*2].mi,tree[i*2+1].mi);
        return;
    }
    void build(const vector<int> &pos)
    {
        int n=pos.size();
        function<void(int,int,int)>build=[&](int i,int l,int r)
        {
            tree[i].l=l,tree[i].r=r;
            if(l==r)
            {
                tree[i].pq=pos[l-1];
                tree[i].mi=p[pos[l-1]].y;
                return;
            }
            int mid=(l+r)/2;
            build(i*2,l,mid);
            build(i*2+1,mid+1,r);
            push_up(i);
            return;
        };
        build(1,1,n);
        return;
    }
    vector<int>modify_H(int l,int r,int v)
    {
        vector<int>pos;
        function<void(int,int,int,int)>modify=[&](int i,int l,int r,int v)
        {
            if(tree[i].mi>v) return;
            if(tree[i].l==tree[i].r)
            {
                tree[i].mi=INF;
                p[tree[i].pq].first=n-v;
                pos.emplace_back(tree[i].pq);
                return;
            }
            if(l<=tree[i*2].r) modify(i*2,l,r,v);
            if(r>=tree[i*2+1].l) modify(i*2+1,l,r,v);
            push_up(i);
            return;
        };
        modify(1,l,r,v);
        return pos;
    }
    vector<int>modify_V(int l,int r,int v)
    {
        vector<int>pos;
        function<void(int,int,int,int)>modify=[&](int i,int l,int r,int v)
        {
            if(tree[i].mi>n-v) return;
            if(tree[i].l==tree[i].r)
            {
                tree[i].mi=INF;
                p[tree[i].pq].second=n-v;
                pos.emplace_back(tree[i].pq);
                return;
            }
            if(l<=tree[i*2].r) modify(i*2,l,r,v);
            if(r>=tree[i*2+1].l) modify(i*2+1,l,r,v);
            push_up(i);
            return;
        };
        modify(1,l,r,v);
        return pos;
    }
}T1;
struct FHQ_Treap
{
    int root,tot;
    struct Node
    {
        int fa,ch[2];
        Point val;
        unsigned rd;
        int siz;
        int tagh,tagv;
        void clear()
        {
            fa=ch[0]=ch[1]=0;
            val={0,0};
            rd=0;
            siz=0;
            tagh=tagv=0;
            return;
        }
    }tree[M+Q];
    int new_node(Point val)
    {
        static mt19937 rnd(time(NULL));
        int now=++tot;
        tree[now].clear();
        tree[now].val=val,tree[now].rd=rnd();
        tree[now].siz=1;
        return now;
    }
    void clear()
    {
        root=0,tot=0;
        return;
    }
    void push_up(int u)
    {
        tree[u].siz=tree[tree[u].ch[0]].siz+tree[tree[u].ch[1]].siz+1;
        return;
    }
    void add_H(int i,int l)
    {
        if(!i) return;
        tree[i].val.x=l;
        tree[i].tagh=l;
        return;
    }
    void add_V(int i,int l)
    {
        if(!i) return;
        tree[i].val.y=l;
        tree[i].tagv=l;
        return;
    }
    void push_down(int i)
    {
        if(tree[i].tagh)
        {
            add_H(tree[i].ch[0],tree[i].tagh);
            add_H(tree[i].ch[1],tree[i].tagh);
            tree[i].tagh=0;
        }
        if(tree[i].tagv)
        {
            add_V(tree[i].ch[0],tree[i].tagv);
            add_V(tree[i].ch[1],tree[i].tagv);
            tree[i].tagv=0;
        }
        return;
    }
    int merge(int u,int v)
    {
        if(!u) return v;
        if(!v) return u;
        push_down(u);
        push_down(v);
        if(tree[u].rd<tree[v].rd)
        {
            tree[u].ch[1]=merge(tree[u].ch[1],v);
            tree[tree[u].ch[1]].fa=u;
            push_up(u); 
            return u;
        }
        else
        {
            tree[v].ch[0]=merge(u,tree[v].ch[0]);
            tree[tree[v].ch[0]].fa=v;
            push_up(v);
            return v;
        }
    }
    void split_x(int i,int k,int &u,int &v)
    {
        if(!i)
        {
            u=v=0;
            return;
        }
        push_down(i);
        if(tree[i].val.x<=k)
        {
            u=i;
            split_x(tree[i].ch[1],k,tree[u].ch[1],v);
            tree[tree[u].ch[1]].fa=u;
        }
        else
        {
            v=i;
            split_x(tree[i].ch[0],k,u,tree[v].ch[0]);
            tree[tree[v].ch[0]].fa=v;
        }
        push_up(i);
        return;
    }
    void split_y(int i,int k,int &u,int &v)
    {
        if(!i)
        {
            u=v=0;
            return;
        }
        push_down(i);
        if(tree[i].val.y>=k)
        {
            u=i;
            split_y(tree[i].ch[1],k,tree[u].ch[1],v);
            tree[tree[u].ch[1]].fa=u;
        }
        else
        {
            v=i;
            split_y(tree[i].ch[0],k,u,tree[v].ch[0]);
            tree[tree[v].ch[0]].fa=v;
        }
        push_up(i);
        return;
    }
    int insert(Point val)
    {
        int u,v,w;
        split_x(root,val.x,u,w);
        split_y(u,val.y,u,v);
        int now=new_node(val);
        root=merge(merge(merge(u,now),v),w);
        return now;
    }
    void modify_H(int l)
    {
        int u,v,w;
        split_x(root,n-l-1,u,w);
        split_y(u,l+1,u,v);
        add_H(v,n-l);
        root=merge(merge(u,v),w);
        return;
    }
    void modify_V(int l)
    {
        int u,v,w;
        split_x(root,l,u,w);
        split_y(u,n-l,u,v);
        add_V(v,n-l);
        root=merge(merge(u,v),w);
        return;
    }
    Point get(int i)
    {
        vector<int>pos;
        for(int u=i;u;u=tree[u].fa)
            pos.emplace_back(u);
        reverse(pos.begin(),pos.end());
        for(int u:pos)
            push_down(u);
        return tree[i].val;
    }
}T2;
Point ans[M+Q];
void solve(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
    vector<int>idx; 
    for(int i=l;i<=mid;i++)
        if(op[i].t==4) idx.emplace_back(op[i].l);
    if(idx.empty()) return;
    sort(idx.begin(),idx.end(),[=](const int &a,const int &b){return p[a].x<p[b].x;});
    T1.build(idx);
    T2.clear();
    vector<int>valx(idx.size());
    for(int i=0;i<(int)idx.size();i++)
        valx[i]=p[idx[i]].x;
    static bool book[M+Q];
    for(int u:idx)
        book[u]=true;
    static int rnk[M+Q];
    for(int i=mid+1;i<=r;i++)
    {
        if(op[i].t==1)
        {
            if(book[op[i].l])
            {
                if(!rnk[op[i].l]) ans[i]=p[op[i].l];
                else ans[i]=T2.get(rnk[op[i].l]);
            }
        }
        else if(op[i].t==2)
        {
            int r=upper_bound(valx.begin(),valx.end(),n-op[i].l)-valx.begin();
            T2.modify_H(op[i].l);
            if(r>=1)
            {
                vector<int>pos=T1.modify_H(1,r,op[i].l);
                for(int u:pos)
                    rnk[u]=T2.insert(p[u]);
            }
        }
        else if(op[i].t==3)
        {
            int r=upper_bound(valx.begin(),valx.end(),op[i].l)-valx.begin();
            T2.modify_V(op[i].l);
            if(r>=1)
            {
                vector<int>pos=T1.modify_V(1,r,op[i].l);
                for(int u:pos)
                    rnk[u]=T2.insert(p[u]);
            }
        }
    }
    for(int u:idx)
        if(rnk[u]) p[u]=T2.get(rnk[u]);
    for(int u:idx)
        book[u]=false,rnk[u]=0;
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p[++cnt]={x,y};
        tot++;
        op[tot].t=4,op[tot].l=cnt;
    }
    for(int i=1;i<=q;i++)
    {
        tot++;
        scanf("%d",&op[tot].t);
        if(op[tot].t==1||op[tot].t==2||op[tot].t==3) scanf("%d",&op[tot].l);
        else if(op[tot].t==4)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            p[++cnt]={x,y};
            op[tot].l=cnt;
        }
    }
    solve(1,tot);
    for(int i=1;i<=tot;i++)
        if(op[i].t==1) printf("%d %d\n",ans[i].x,ans[i].y);
    return 0;
}