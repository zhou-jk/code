#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,m;
struct Line
{
    double k,b;
    double calc(const double &u)const
    {
        return k*u+b;
    }
};
struct Segment_Tree
{
    struct Node
    {
        int ls,rs;
        Line tag; 
    }tree[N<<2];
    int rt,tot;
    Segment_Tree(){rt=1,tot=1;}
    int new_node()
    {
        int now=++tot;
        tree[now].ls=tree[now].rs=0;
        tree[now].tag.k=tree[now].tag.b=0;
        return now;
    }
    void clear()
    {
        rt=1,tot=1;
        return; 
    }
    void modify(int &i,int l,int r,Line t)
    {
        if(!i) i=new_node();
        if(tree[i].tag.calc(l)<t.calc(l)) swap(tree[i].tag,t);
        if(l==r) return;
        int mid=(l+r)/2;
        if(tree[i].tag.calc(mid)<t.calc(mid)) modify(tree[i].ls,l,mid,tree[i].tag),tree[i].tag=t;
        else modify(tree[i].rs,mid+1,r,t);
        return;
    }
    void update(int &i,int l,int r,int L,int R,Line t)
    {
        if(!i) i=new_node();
        if(L<=l&&r<=R) return modify(i,l,r,t);
        int mid=(l+r)/2;
        if(L<=mid) update(tree[i].ls,l,mid,L,R,t);
        if(R>mid) update(tree[i].rs,mid+1,r,L,R,t);
        return;
    }
    double query(int i,int l,int r,int t)
    {
        if(!i) return 0;
        if(l==r) return tree[i].tag.calc(t);
        int mid=(l+r)/2;
        double res=tree[i].tag.calc(t);
        if(t<=mid) res=max(res,query(tree[i].ls,l,mid,t));
        else res=max(res,query(tree[i].rs,mid+1,r,t));
        return res;
    }
}T;
int main()
{
    cin>>n;
    m=50000;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(s=="Project")
        {
            Line a;
            cin>>a.b>>a.k;
            T.update(T.rt,0,m,0,m,a);
        }
        else if(s=="Query")
        {
            int x;
            cin>>x;
            cout<<(int)(T.query(T.rt,0,m,x-1)/100)<<"\n";
        }
    }
    return 0;
}