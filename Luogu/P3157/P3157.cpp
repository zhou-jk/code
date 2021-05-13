#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int a[N],b[N];
struct BIT
{
    int C[N];
    BIT()
    {
        memset(C,0,sizeof(C));
        return;
    }
    void clear()
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
            C[i]+=y;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=C[i];
        return res;
    }
    int query(int l,int r)
    {
        return getsum(r)-getsum(l-1);
    }
}T;
struct Query
{
    int p,v;
    int id;
}q[N<<1],ql[N],qr[N];
int tot;
long long ans[N];
void solve(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
    int totl=0,totr=0;
    for(int i=l;i<=mid;i++)
        ql[++totl]=q[i];
    for(int i=mid+1;i<=r;i++)
        qr[++totr]=q[i];
    sort(ql+1,ql+totl+1,[=](const Query &x,const Query &y){return x.p<y.p;});
    sort(qr+1,qr+totr+1,[=](const Query &x,const Query &y){return x.p<y.p;});
    int j=0;
    for(int i=1;i<=totr;i++)
    {
        while(j+1<=totl&&ql[j+1].p<qr[i].p)
        {
            T.add(ql[j+1].v,1);
            j++;
        }
        ans[qr[i].id]+=T.query(qr[i].v+1,n);
    }
    for(int i=1;i<=j;i++)
        T.add(ql[i].v,-1);
    j=totl+1;
    for(int i=totr;i>=1;i--)
    {
        while(j-1>=1&&ql[j-1].p>qr[i].p)
        {
            T.add(ql[j-1].v,1);
            j--;
        }
        ans[qr[i].id]+=T.query(1,qr[i].v-1);
    }
    for(int i=j;i<=totl;i++)
        T.add(ql[i].v,-1);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    static bool vis[N];
    static int pos[N];
    for(int i=1;i<=n;i++)
        pos[a[i]]=i;
    for(int i=1;i<=m;i++)
        vis[b[i]]=true;
    for(int i=1;i<=n;i++)
        if(!vis[a[i]]) q[++tot]={i,a[i],m+1};
    for(int i=m;i>=1;i--)
        q[++tot]={pos[b[i]],b[i],i};
    solve(1,tot);
    for(int i=m;i>=1;i--)
        ans[i]+=ans[i+1];
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}