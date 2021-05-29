#include<iostream>
#include<cstdio>
#include<cstring>
#include<unordered_map>
#include<algorithm>
using namespace std;
const int N=200005;
const int MOD=1000000007;
int n;
int a[N],b[N],c[N];
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=1LL*res*a%MOD;
        a=1LL*a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int x)
{
    return ksm(x,MOD-2);
}
struct BIT
{
    int C[N];
    BIT()
    {
        memset(C,0,sizeof(C));
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]=(C[i]+y)%MOD;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res=(res+C[i])%MOD;
        return res;
    }
    int query(int l,int r)
    {
        return (getsum(r)-getsum(l-1)+MOD)%MOD;
    }
}TC;
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        int sum,tag;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%MOD;
        return;
    }
    void mul(int i,int v)
    {
        tree[i].sum=1LL*tree[i].sum*v%MOD;
        tree[i].tag=1LL*tree[i].tag*v%MOD;
        return;
    }
    void push_down(int i)
    {
        if(tree[i].tag==1) return;
        mul(i*2,tree[i].tag);
        mul(i*2+1,tree[i].tag);
        tree[i].tag=1;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tag=1;
        if(l==r)
        {
            tree[i].sum=0;
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void modifyadd(int i,int u,int v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].sum=(tree[i].sum+v)%MOD;
            return;
        }
        push_down(i);
        if(u<=tree[i*2].r) modifyadd(i*2,u,v);
        else modifyadd(i*2+1,u,v);
        push_up(i);
        return;
    }
    void modifymul(int i,int l,int r,int v)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return mul(i,v);
        push_down(i);
        if(l<=tree[i*2].r) modifymul(i*2,l,r,v);
        if(r>=tree[i*2+1].l) modifymul(i*2+1,l,r,v);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l>r) return 0;
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
        push_down(i);
        int res=0;
        if(l<=tree[i*2].r) res=(res+query(i*2,l,r))%MOD;
        if(r>=tree[i*2+1].l) res=(res+query(i*2+1,l,r))%MOD;
        return res;
    }
}T;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        c[i]=i;
    sort(c+1,c+n+1,[=](const int &x,const int &y){return a[x]<a[y];});
    for(int i=1;i<=n;i++)
        b[c[i]]=i;
    for(int i=1;i<=n;i++)
        if(a[i]<b[i])
        {
            printf("0");
            return 0;
        }
    int sum=1;
    for(int i=1;i<=n;i++)
        sum=1LL*sum*(a[i]-b[i]+1)%MOD;
    T.build(1,1,n);
    int ans=0;
    int inv2=getinv(2);
    for(int k=1;k<=n;k++)
    {
        ans=(ans+1LL*T.query(1,1,c[k]-1)*getinv(a[c[k]]-b[c[k]]+1)%MOD*sum%MOD*inv2)%MOD;
        ans=(ans+1LL*TC.query(c[k]+1,n)*sum)%MOD;
        ans=(ans-1LL*T.query(1,c[k]+1,n)*getinv(a[c[k]]-b[c[k]]+1)%MOD*sum%MOD*inv2%MOD+MOD)%MOD;
        TC.add(c[k],1);
        T.modifymul(1,1,n,1LL*(a[c[k]]-b[c[k]])*getinv(a[c[k]]-b[c[k]]+1)%MOD);
        T.modifyadd(1,c[k],a[c[k]]-b[c[k]]);
    }
    printf("%d",ans);
    return 0;
}