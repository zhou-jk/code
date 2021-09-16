#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=1000000007;
int n,m;
int a[N];
int C[6][6];
int pw[N][6],s[6][N];
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        int sum[6];
        int tag;
    }tree[N<<2];
    void push_up(int i)
    {
        for(int j=0;j<=5;j++)
            tree[i].sum[j]=(tree[i*2].sum[j]+tree[i*2+1].sum[j])%MOD;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tag=-1;
        if(l==r)
        {
            for(int j=0;j<=5;j++)
                tree[i].sum[j]=1LL*a[l]*pw[l+1][j]%MOD;
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void cover(int i,int x)
    {
        tree[i].tag=x;
        for(int j=0;j<=5;j++)
            tree[i].sum[j]=1LL*x*(s[j][tree[i].r]-s[j][tree[i].l-1]+MOD)%MOD;
        return;
    }
    void push_down(int i)
    {
        if(tree[i].tag==-1) return;
        cover(i*2,tree[i].tag);
        cover(i*2+1,tree[i].tag);
        tree[i].tag=-1;
        return;
    }
    void modify(int i,int l,int r,int x)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return cover(i,x);
        push_down(i);
        if(l<=tree[i*2].r) modify(i*2,l,r,x);
        if(r>=tree[i*2+1].l) modify(i*2+1,l,r,x);
        push_up(i);
        
        return;
    }
    int query(int i,int l,int r,int L,int k)
    {
        if(l<=tree[i].l&&tree[i].r<=r)
        {
            int res=0;
            for(int j=0;j<=k;j++)
               if((k-j)%2==0) res=(res+1LL*C[k][j]*pw[L][k-j]%MOD*tree[i].sum[j])%MOD;
               else res=(res-1LL*C[k][j]*pw[L][k-j]%MOD*tree[i].sum[j])%MOD;
            res=(res+MOD)%MOD;
            return res;
        }
        push_down(i);
        int res=0;
        if(l<=tree[i*2].r) res=(res+query(i*2,l,r,L,k))%MOD;
        if(r>=tree[i*2+1].l) res=(res+query(i*2+1,l,r,L,k))%MOD;
        return res;
    }
}T;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n+1;i++)
    {
        pw[i][0]=1;
        for(int j=1;j<=5;j++)
            pw[i][j]=1LL*pw[i][j-1]*i%MOD;
    }
    for(int j=0;j<=5;j++)
    {
        s[j][0]=pw[1][j];
        for(int i=1;i<=n;i++)
            s[j][i]=(s[j][i-1]+pw[i+1][j])%MOD;
    }
    for(int i=0;i<=5;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
    T.build(1,1,n);
    while(m--)
    {
        char ch=getchar();
        while(ch!='='&&ch!='?') ch=getchar();
        if(ch=='=')
        {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            T.modify(1,l,r,x);
        }
        else if(ch=='?')
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",T.query(1,l,r,l,k));
        }
    }
    return 0;
}
