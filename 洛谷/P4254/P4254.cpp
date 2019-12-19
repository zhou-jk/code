#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001,M=50001;
int n,tot;
double K[N],B[N];
int lazy[N<<2];
double f(int i,int x)
{
    return K[i]*(x-1)+B[i];
}
void update(int i,int l,int r,int t)
{
    if(l==r)
    {
        if(f(t,l)>f(lazy[i],l)) lazy[i]=t;
        return;
    }
    int mid=(l+r)/2;
    if(K[t]>K[lazy[i]])
    {
        if(f(t,mid)>f(lazy[i],mid)) update(i*2,l,mid,lazy[i]),lazy[i]=t;
        else update(i*2+1,mid+1,r,t);
    }
    if(K[t]<K[lazy[i]])
    {
        if(f(t,mid)>f(lazy[i],mid)) update(i*2+1,mid+1,r,lazy[i]),lazy[i]=t;
        else update(i*2,l,mid,t);
    }
    return;
}
double query(int i,int l,int r,int t)
{
    if(l==r) return f(lazy[i],t);
    int mid=(l+r)/2;
    double ans=f(lazy[i],t);
    if(t<=mid) ans=max(ans,query(i*2,l,mid,t));
    if(t>mid)  ans=max(ans,query(i*2+1,mid+1,r,t));
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(s=="Project")
        {
            tot++;
            scanf("%lf%lf",&B[tot],&K[tot]);
            update(1,1,M,tot);
        }
        else if(s=="Query")
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",(int)(query(1,1,M,x)/100));
        }
    }
    return 0;
}