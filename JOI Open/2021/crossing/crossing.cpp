#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=200005;
const int BASE=233;
const int MOD1=1000000007,MOD2=1000000009;
int n,q;
bool f[3][3][3];
pair<int,int> pw[N],fac[4][N];
char sa[N],sb[N],sc[N];
char t[N];
int get_val(char ch)
{
    if(ch=='J') return 0;
    else if(ch=='O') return 1;
    else if(ch=='I') return 2;
    else return -1;
}
map<pair<int,int>,bool>book;
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        int tag;
        pair<int,int> val;
    }tree[N*4];
    Node merge(const Node &a,const Node &b)
    {
        Node c;
        c.l=a.l,c.r=b.r;
        c.tag=0;
        c.val=make_pair(((long long)a.val.first*pw[b.r-b.l+1].first+b.val.first)%MOD1,((long long)a.val.second*pw[b.r-b.l+1].second+b.val.second)%MOD2);
        return c;
    }
    void push_up(int i)
    {
        tree[i]=merge(tree[ls],tree[rs]);
        return;
    }
    void add(int i,int v)
    {
        tree[i].tag=v;
        tree[i].val=fac[v][tree[i].r-tree[i].l+1];
        return;
    }
    void push_down(int i)
    {
        if(!tree[i].tag) return;
        add(ls,tree[i].tag);
        add(rs,tree[i].tag);
        tree[i].tag=0;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r) return add(i,get_val(t[l])+1);
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int l,int r,int v)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
        push_down(i);
        if(l<=tree[ls].r) modify(ls,l,r,v);
        if(r>=tree[rs].l) modify(rs,l,r,v);
        push_up(i);
        return;
    }
    Node query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i];
        push_down(i);
        if(r<=tree[ls].r) return query(ls,l,r);
        else if(l>=tree[rs].l) return query(rs,l,r);
        else return merge(query(ls,l,r),query(rs,l,r));
    }
    #undef ls
    #undef rs
}T;
int main()
{
    scanf("%d",&n);
    scanf("%s",sa+1);
    scanf("%s",sb+1);
    scanf("%s",sc+1);
    f[1][0][0]=f[0][1][0]=f[0][0][1]=true;
    while(true)
    {
        bool flag=true;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                    if(f[i][j][k])
                        for(int o=0;o<3;o++)
                            for(int p=0;p<3;p++)
                                for(int q=0;q<3;q++)
                                    if(f[o][p][q])
                                    {
                                        int a=(6-i-o)%3,b=(6-j-p)%3,c=(6-k-q)%3;
                                        if(!f[a][b][c])
                                        {
                                            f[a][b][c]=true;
                                            flag=false;
                                        }
                                    }
        if(flag) break;
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                if(f[i][j][k])
                {
                    int sum1=0,sum2=0;
                    for(int l=1;l<=n;l++)
                    {
                        int v=(get_val(sa[l])*i+get_val(sb[l])*j+get_val(sc[l])*k)%3;
                        v=(v+3)%3;
                        sum1=((long long)sum1*BASE+v+1)%MOD1;
                        sum2=((long long)sum2*BASE+v+1)%MOD2;
                    }
                    book[make_pair(sum1,sum2)]=true;
                }
    pw[0]=make_pair(1,1);
    for(int i=1;i<=n;i++)
        pw[i]=make_pair((long long)pw[i-1].first*BASE%MOD1,(long long)pw[i-1].second*BASE%MOD2);
    for(int v=1;v<=3;v++)
        for(int i=1;i<=n;i++)
            fac[v][i]=make_pair(((long long)fac[v][i-1].first*BASE+v)%MOD1,((long long)fac[v][i-1].second*BASE+v)%MOD2);
    scanf("%d",&q);
    scanf("%s",t+1);
    T.build(1,1,n);
    if(book[T.query(1,1,n).val]) printf("Yes\n");
    else printf("No\n");
    while(q--)
    {
        int l,r;
        char c;
        scanf("%d%d",&l,&r);
        for(c=getchar();c!='J'&&c!='O'&&c!='I';c=getchar());
        T.modify(1,l,r,get_val(c)+1);
        if(book[T.query(1,1,n).val]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}