#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define abs(x) ((x>=0)?(x):(-x))
int n,m;
int a[100001],b[100001];
bool c[100001];
struct Node
{
    int l,r;
    bool operator <(const Node &b)const
    {
        return l<b.l;
    }
};
set<Node>S;
void Insert(int p)
{
    Node t=(Node){p,p},suf,pre;
    set<Node>::iterator it=S.lower_bound(t);
    suf=*it;
    if(suf.l!=n+1&&suf.l==p+1) S.erase(it),t.r=suf.r;
    it=--S.lower_bound(t),pre=*it;
    if(pre.r&&pre.r==p-1) S.erase(it),t.l=pre.l;
    S.insert(t);
    return;
}
void Delete(int p)
{
    Node t=(Node){p,p},cur;
    set<Node>::iterator it=--S.upper_bound(t);
    cur=*it,S.erase(it);
    if(cur.l<p) S.insert((Node){cur.l,p-1});
    if(cur.r>p) S.insert((Node){p+1,cur.r});
    return;
} 
int solve(Node u,int p)
{
    if(u.l==1)
    {
        Node t=*--(--S.end());
        if(t.r==n) u.l=t.l;
    }
    if(u.r==n)
    {
        Node t=*++S.begin();
        if(t.l==1) u.r=t.r;
    }
    if((u.l<=u.r&&u.l<=p&&p<=u.r)||(u.l>u.r&&(u.l<=p||p<=u.r))) return 0;
    return min(min(abs(p-u.l),abs(p-u.r)),min(n-abs(p-u.r),n-abs(p-u.l)));
}
inline int nxt(int i)
{
    return i==n?1:i+1;
}
inline int pre(int i)
{
    return i==1?n:i-1;
}
inline set<Node>::iterator Nxt(set<Node>::iterator it)
{
    return it==--(--S.end())||it==--S.end()?++S.begin():++it;
}
inline set<Node>::iterator Pre(set<Node>::iterator it)
{
    return it==++S.begin()||it==S.begin()?--(--S.end()):--it;
}
int query(int p)
{
    if(S.size()==2) return -1;
    int pos=p+n/2;
    if(pos>n) pos-=n;
    Node t=(Node){pos,pos};
    set<Node>::iterator it=Pre(Pre(Pre(S.lower_bound(t)))); 
    int res=0;
    for(int i=1;i<=6;i++)
        res=max(res,solve(*it,p)),it=Nxt(it);
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        char ch;
        scanf("%d %c",&a[i],&ch);
        c[i]=ch=='*';
    }
    for(int i=1;i<=n;i++)
        b[i]=(c[i]?a[pre(i)]*a[i]%10:(a[pre(i)]+a[i])%10);
    S.insert((Node){0,0});
    S.insert((Node){n+1,n+1});
    for(int i=1;i<=n;i++)
        if(b[i]==0) Insert(i);
    while(m--)
    {
        int op,p;
        scanf("%d%d",&op,&p);
        p++;
        if(op==1)
        {
            char ch;
            scanf("%d %c",&a[p],&ch);
            c[p]=ch=='*';
            int x=b[p],y=b[p]=(c[p]?a[pre(p)]*a[p]%10:(a[pre(p)]+a[p])%10);
            if(x&&y==0) Insert(p);
            if(x==0&&y) Delete(p);
            x=b[nxt(p)],y=b[nxt(p)]=(c[nxt(p)]?a[p]*a[nxt(p)]%10:(a[p]+a[nxt(p)])%10);
            if(x&&y==0) Insert(nxt(p));
            if(x==0&&y) Delete(nxt(p));
        }
        else 
        {
            if(b[p]&&a[p]==0) Insert(p);
            if(b[p]==0&&a[p]) Delete(p);
            printf("%d\n",query(p));
            if(a[p]&&b[p]==0) Insert(p);
            if(a[p]==0&&b[p]) Delete(p);
        }
    }
    return 0;
}