#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2000005;
int n,m;
char s[N],t[N];
vector<int>p[N];
vector<int>pos[N];
struct Trie
{
    static const int C=4; 
    int trie[N][C],tot;
    vector<int> ed[N];
    int dfn[N],siz[N],Index;
    Trie():tot(1),Index(0){}
    int get(char c)
    {
        if(c=='A') return 0;
        else if(c=='G') return 1;
        else if(c=='U') return 2;
        else if(c=='C') return 3;
        else return -1;
    }
    void insert(char *s,int t)
    {
        int len=strlen(s);
        int u=1;
        for(int i=0;i<len;i++)
        {
            int c=get(s[i]);
            if(!trie[u][c]) trie[u][c]=++tot;
            u=trie[u][c];
        }
        ed[u].emplace_back(t);
        return;
    }
    void dfs(int u)
    {
        if(!u) return;
        dfn[u]=++Index;
        siz[u]=1; 
        for(int t:ed[u])
            p[t].emplace_back(dfn[u]);
        for(int c=0;c<C;c++)
            dfs(trie[u][c]),siz[u]+=siz[trie[u][c]];
        return;
    }
    pair<int,int> query(char *s)
    {
        int len=strlen(s);
        int u=1;
        for(int i=0;i<len;i++)
        {
            int c=get(s[i]);
            if(!trie[u][c]) return make_pair(0,0);
            u=trie[u][c];
        }
        return make_pair(dfn[u],dfn[u]+siz[u]-1);
    }
}T1,T2;
int bx[N],by[N],totx,toty;
struct Chairman_Tree
{
    struct Node
    {
        int ls,rs;
        int sum;
    }tree[N*20];
    int rt[N],tot;
    int new_node()
    {
        int now=++tot;
        tree[now].ls=tree[now].rs=0;
        tree[now].sum=0;
        return now;
    }
    void push_up(int i)
    {
        tree[i].sum=tree[tree[i].ls].sum+tree[tree[i].rs].sum;
        return;
    }
    void build(int &i,int l,int r)
    {
        if(!i) i=new_node();
        if(l==r)
        {
            tree[i].sum=0;
            return;
        }
        int mid=(l+r)/2;
        build(tree[i].ls,l,mid);
        build(tree[i].rs,mid+1,r);
        push_up(i);
        return;
    }
    int modify(int i,int l,int r,int u,int v)
    {
        int now=new_node();
        tree[now]=tree[i];
        if(l==r)
        {
            tree[now].sum+=v;
            return now;
        }
        int mid=(l+r)/2;
        if(u<=mid) tree[now].ls=modify(tree[i].ls,l,mid,u,v);
        else tree[now].rs=modify(tree[i].rs,mid+1,r,u,v);
        push_up(now);
        return now;
    }
    int query(int i,int l,int r,int L,int R)
    {
        if(!i) return 0;
        if(L<=l&&r<=R) return tree[i].sum;
        int mid=(l+r)/2;
        int res=0;
        if(L<=mid) res+=query(tree[i].ls,l,mid,L,R);
        if(R>mid) res+=query(tree[i].rs,mid+1,r,L,R);
        return res;
    }
}T;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        int len=strlen(s+1);
        for(int i=1;i<=len;i++)
            t[i]=s[len-i+1];
        t[len+1]='\0';
        T1.insert(s+1,i),T2.insert(t+1,i);
    }
    T1.dfs(1),T2.dfs(1);
    for(int i=1;i<=n;i++)
        bx[++totx]=p[i][0],by[++toty]=p[i][1];
    sort(bx+1,bx+totx+1);
    totx=unique(bx+1,bx+totx+1)-bx-1;
    sort(by+1,by+toty+1);
    toty=unique(by+1,by+toty+1)-by-1;
    for(int i=1;i<=n;i++)
        p[i][0]=lower_bound(bx+1,bx+totx+1,p[i][0])-bx,p[i][1]=lower_bound(by+1,by+toty+1,p[i][1])-by;
    for(int i=1;i<=n;i++)
        pos[p[i][0]].emplace_back(p[i][1]);
    T.build(T.rt[0],1,toty);
    for(int i=1;i<=totx;i++)
    {
        T.rt[i]=T.rt[i-1];
        for(int u:pos[i])
            T.rt[i]=T.modify(T.rt[i],1,toty,u,1);
    }
    while(m--)
    {
        scanf("%s%s",s+1,t+1);
        int lent=strlen(t+1);
        reverse(t+1,t+lent+1);
        auto [xl,xr]=T1.query(s+1);
        auto [yl,yr]=T2.query(t+1);
        if(xl==0||xr==0||yl==0||yr==0)
        {
            printf("0\n");
            continue;
        }
        xl=lower_bound(bx+1,bx+totx+1,xl)-bx,xr=upper_bound(bx+1,bx+totx+1,xr)-bx-1;
        yl=lower_bound(by+1,by+toty+1,yl)-by,yr=upper_bound(by+1,by+toty+1,yr)-by-1;
        int ans=T.query(T.rt[xr],1,toty,yl,yr)-T.query(T.rt[xl-1],1,toty,yl,yr);
        printf("%d\n",ans);
    }
    return 0;
}