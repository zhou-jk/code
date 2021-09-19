#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005,B=55;
int n,m,Q;
int a[N],b[N];
struct BIT
{
    int C[N];
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
}T;
int bel[N];
struct Block
{
    int l,r;
    int p[B+5];
}block[N/B+5];
void update(int k)
{
    vector<int>pos;
    for(int i=block[k].l;i<=block[k].r;i++)
    {
        int l=1,r=n,p=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(mid+T.getsum(mid)>=a[i]) p=mid,r=mid-1;
            else l=mid+1;
        }
        pos.emplace_back(p);
        T.add(p,1);
    }
    for(int v=0;v<=block[k].r-block[k].l+1;v++)
    {
        int l=v>0?block[k].p[v-1]:0,r=n,ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(T.getsum(mid)<=v) ans=mid,l=mid+1;
            else r=mid-1;
        }
        block[k].p[v]=ans;
    }
    for(int p:pos)
        T.add(p,-1);
    return;
}
int query(int x)
{
    int ans=a[x];
    for(int i=x+1;i<=block[bel[x]].r;i++)
        if(ans>=a[i]) ans++;
    for(int i=bel[x]+1;i<=m;i++)
    {
        int v=lower_bound(block[i].p,block[i].p+block[i].r-block[i].l+1+1,ans)-block[i].p;
        ans+=v;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        a[i]=i-b[i];
    for(int i=1;i<=n;i++)
        bel[i]=(i-1)/B+1;
    m=(n-1)/B+1;
    for(int i=1;i<=m;i++)
        block[i].l=(i-1)*B+1,block[i].r=min(i*B,n);
    for(int k=1;k<=m;k++)
    {
        vector<int>pos;
        for(int i=block[k].l;i<=block[k].r;i++)
        {
            int l=1,r=n,p=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(mid+T.getsum(mid)>=a[i]) p=mid,r=mid-1;
                else l=mid+1;
            }
            pos.emplace_back(p);
            T.add(p,1);
        }
        for(int v=0;v<=block[k].r-block[k].l+1;v++)
        {
            int l=v>0?block[k].p[v-1]:0,r=n,ans=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(T.getsum(mid)<=v) ans=mid,l=mid+1;
                else r=mid-1;
            }
            block[k].p[v]=ans;
        }
        for(int p:pos)
            T.add(p,-1);
    }
    scanf("%d",&Q);
    while(Q--)
    {
        int op,i;
        scanf("%d",&op);
        if(op==1)
        {
            int x;
            scanf("%d%d",&i,&x);
            b[i]=x,a[i]=i-b[i];
            update(bel[i]);
        }
        else if(op==2)
        {
            scanf("%d",&i);
            printf("%d\n",query(i));
        }
    }
    return 0;
}