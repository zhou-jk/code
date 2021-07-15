#include<iostream>
#include<cstdio>
#include<cstring>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=100005;
int n,Q;
int v[N*6],cnt;
struct Query
{
    int a,b,c;
    int v,id;
}q[N*2];
int tot;
int id[N*2];
struct BIT
{
    int C[N*6];
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
        for(int i=x;i<=cnt;i+=lowbit(i))
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
int ans[N];
void solve(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
    static int idl[N*2],totl;
    static int idr[N*2],totr;
    totl=0,totr=0;
    for(int i=l;i<=mid;i++)
        idl[++totl]=id[i];
    for(int i=mid+1;i<=r;i++)
        idr[++totr]=id[i];
    sort(idl+1,idl+totl+1,[=](const int &x,const int &y){return q[x].b>q[y].b;});
    sort(idr+1,idr+totr+1,[=](const int &x,const int &y){return q[x].b>q[y].b;});
    int i=0;
    for(int j=1;j<=totr;j++)
    {
        while(i+1<=totl&&q[idl[i+1]].b>=q[idr[j]].b) T.add(q[idl[i+1]].c,q[idl[i+1]].v),i++;
        if(q[idr[j]].id) ans[q[idr[j]].id]+=T.query(q[idr[j]].c,cnt);
    }
    for(int k=1;k<=i;k++)
        T.add(q[idl[k]].c,-q[idl[k]].v);
    return;
}
int main()
{
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        v[++cnt]=s,v[++cnt]=t,v[++cnt]=s+t;
        q[++tot]={s,t,s+t,1,0};
    }
    for(int i=1;i<=Q;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[++cnt]=a,v[++cnt]=b,v[++cnt]=c;
        q[++tot]={a,b,c,0,i};
    }
    sort(v+1,v+cnt+1);
    cnt=unique(v+1,v+cnt+1)-v-1;
    for(int i=1;i<=tot;i++)
    {
        q[i].a=lower_bound(v+1,v+cnt+1,q[i].a)-v;
        q[i].b=lower_bound(v+1,v+cnt+1,q[i].b)-v;
        q[i].c=lower_bound(v+1,v+cnt+1,q[i].c)-v;
    }
    iota(id+1,id+tot+1,1);
    sort(id+1,id+tot+1,[=](const int &x,const int &y)
    {
        if(q[x].a!=q[y].a) return q[x].a>q[y].a;
        if(q[x].b!=q[y].b) return q[x].b>q[y].b;
        if(q[x].c!=q[y].c) return q[x].c>q[y].c;
        return q[x].id<q[y].id;
    });
    solve(1,tot);
    for(int i=tot-1;i>=1;i--)
        if(q[id[i]].a==q[id[i+1]].a&&q[id[i]].b==q[id[i+1]].b&&q[id[i]].c==q[id[i+1]].c)
        {
            if(q[id[i]].id&&q[id[i+1]].id) ans[q[id[i]].id]=ans[q[id[i+1]].id];
        }
    for(int i=1;i<=Q;i++)
        printf("%d\n",ans[i]);
    return 0;
}