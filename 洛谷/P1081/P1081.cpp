#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int INF=1061109567;
const double eps=1e-7;
struct Node
{
    int fa;
    int ch[2];
    int val;
    int id;
}tree[100001];
int size,root;
void rotate(int u,int &to)
{
    int y=tree[u].fa,z=tree[y].fa;
    int l,r;
    if(tree[y].ch[1]!=u) l=0,r=1;
    else l=1,r=0;
    if(y==to) to=u;
    else tree[z].ch[tree[z].ch[1]==y]=u;
    tree[tree[u].ch[r]].fa=y;
    tree[y].fa=u;
    tree[u].fa=z;
    tree[y].ch[l]=tree[u].ch[r];
    tree[u].ch[r]=y;
    return;
}
void splay(int u,int &to)
{
    while(u^to)
    {
        int y=tree[u].fa,z=tree[y].fa;
        if(y^to)
        {
            if((tree[y].ch[0]==u)^(tree[z].ch[0]==y)) rotate(u,to);
            else rotate(y,to);
        }
        rotate(u,to);
    }
    return;
}
int insert(int key,int Index)
{
    if(!root)
    {
        root=++size;
        tree[root].val=key;
        tree[root].id=Index;
        return root;
    }
    int x;
    for(x=root;tree[x].ch[key>tree[x].val];x=tree[x].ch[key>tree[x].val]);
    tree[x].ch[key>tree[x].val]=++size;
    tree[size].fa=x;
    tree[size].val=key;
    tree[size].id=Index;
    splay(size,root);
    return root;
}
int pre(int u)
{
    if(!root) return -1;
    splay(u,root);
    if(!tree[u].ch[0]) return -1;
    for(u=tree[u].ch[0];tree[u].ch[1];u=tree[u].ch[1]);
    return u;
}
int next(int u)
{
    if(!root) return -1;
    splay(u,root);
    if(!tree[u].ch[1]) return -1;
    for(u=tree[u].ch[1];tree[u].ch[0];u=tree[u].ch[0]);
    return u;
}
int f[100001][17],dp[100001][17][2];
int n,a[100001],fa[100001][2];
int count(int i,int j)
{
    return abs(a[i]-a[j]);
}
pair<int,int> find(int x,int id)
{
    int min1=INF,min2=INF;
    int t1=pre(x),t2=next(x);
    int pos1=0,pos2=0;
    if((t1!=-1&&(min1>count(tree[t1].id,id)))||(min1==count(tree[t1].id,id)&&a[tree[t1].id]<a[pos1])) min1=count(tree[t1].id,id),pos1=tree[t1].id;
    if((t2!=-1&&(min1>count(tree[t2].id,id)))||(min1==count(tree[t2].id,id)&&a[tree[t2].id]<a[pos1])) min1=count(tree[t2].id,id),pos1=tree[t2].id;
    if(min1==INF) return make_pair(-1,-1);
    if(t1!=-1&&min1==count(tree[t1].id,id))
    {
        int t=pre(t1);
        if((t!=-1&&(min2>count(tree[t].id,id)))||(min2==count(tree[t].id,id)&&a[tree[t].id]<a[pos2])) min2=count(tree[t].id,id),pos2=tree[t].id;
        if((t2!=-1&&(min2>count(tree[t2].id,id)))||(min2==count(tree[t2].id,id)&&a[tree[t2].id]<a[pos2])) min2=count(tree[t2].id,id),pos2=tree[t2].id;
        return make_pair(pos1,pos2);
    }
    if(t2!=-1&&min1==count(tree[t2].id,id))
    {
        int t=next(t2);
        if((t1!=-1&&(min2>count(tree[t1].id,id)))||(min2==count(tree[t1].id,id)&&a[tree[t1].id]<a[pos2])) min2=count(tree[t1].id,id),pos2=tree[t1].id;
        if((t!=-1&&(min2>count(tree[t].id,id)))||(min2==count(tree[t].id,id)&&a[tree[t].id]<a[pos2])) min2=count(tree[t].id,id),pos2=tree[t].id;
        return make_pair(pos1,pos2);
    }
    return make_pair(-1,-1);
}
void build()
{
    for(int i=n;i>=1;i--)
    {
        int x=insert(a[i],i);
        pair<int,int> u=find(x,i);
        if(u.first!=-1) fa[i][1]=u.first;
        if(u.second!=-1) fa[i][0]=u.second;
    }
    for(int i=1;i<=n;i++)
    {
        f[i][0]=fa[fa[i][0]][1];
        dp[i][0][0]=count(i,fa[i][0]);
        dp[i][0][1]=count(fa[i][0],fa[fa[i][0]][1]);
    }
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++)
        {
            f[i][j]=f[f[i][j-1]][j-1];
            dp[i][j][0]=dp[i][j-1][0]+dp[f[i][j-1]][j-1][0];
            dp[i][j][1]=dp[i][j-1][1]+dp[f[i][j-1]][j-1][1];
        }
    return;
}
pair<int,int> query(int s,int x)
{
    int ans1=0,ans2=0;
    for(int k=log2(n);k>=0;k--)
        if(f[s][k]&&ans1+ans2+dp[s][k][0]+dp[s][k][1]<=x)
        {
            ans1+=dp[s][k][0];
            ans2+=dp[s][k][1];
            s=f[s][k];
        }
    if(fa[s][0]&&ans1+ans2+count(s,fa[s][0])<=x) ans1+=count(s,fa[s][0]);
    return make_pair(ans1,ans2);
}
int check(double x)
{
    if(fabs(x)<eps) return 0;
    if(x>0.0) return 1;
    else return -1;
}
int T,s0,res;
double ans=INF+1;
int main()
{
    scanf("%d",&n);
    a[0]=INF;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build();
    scanf("%d",&s0);
    for(int i=1;i<=n;i++)
    {
        pair<int,int> now=query(i,s0);
        double tmp=INF;
        if(now.second) tmp=(double)now.first/now.second;
        if(check(ans-tmp)==1) ans=tmp,res=i;
        else if(check(ans-tmp)==0&&a[res]<a[i]) res=i;
    }
    printf("%d\n",res);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int s,x;
        scanf("%d%d",&s,&x);
        pair<int,int> u=query(s,x);
        printf("%d %d\n",u.first,u.second);            
    }
    return 0;
}