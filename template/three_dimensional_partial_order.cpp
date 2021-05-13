#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005,K=200005;
int n,k;
int a[N],b[N],c[N];
struct BIT
{
    int C[K];
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
        for(int i=x;i<=k;i+=lowbit(i))
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
int id[N];
int tl[N],tr[N];
int ans[N];
int res[N];
void solve(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
    int totl=0,totr=0;
    for(int i=l;i<=mid;i++)
        tl[++totl]=id[i];
    for(int i=mid+1;i<=r;i++)
        tr[++totr]=id[i];
    sort(tl+1,tl+totl+1,[=](const int &x,const int &y){return b[x]<b[y];});
    sort(tr+1,tr+totr+1,[=](const int &x,const int &y){return b[x]<b[y];});
    int j=0;
    for(int i=1;i<=totr;i++)
    {
        while(j+1<=totl&&b[tl[j+1]]<=b[tr[i]])
        {
            T.add(c[tl[j+1]],1);
            j++;
        }
        ans[tr[i]]+=T.getsum(c[tr[i]]);
    }
    for(int i=1;i<=j;i++)
        T.add(c[tl[i]],-1);
    return;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=1;i<=n;i++)
        id[i]=i;
    sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]!=a[y]?a[x]<a[y]:(b[x]!=b[y]?b[x]<b[y]:c[x]<c[y]);});
    solve(1,n);
    for(int i=n-1;i>=1;i--)
        if(a[id[i]]==a[id[i+1]]&&b[id[i]]==b[id[i+1]]&&c[id[i]]==c[id[i+1]]) ans[id[i]]=ans[id[i+1]];
    for(int i=1;i<=n;i++)
        res[ans[i]]++;
    for(int i=0;i<n;i++)
        printf("%d\n",res[i]);
    return 0;
}