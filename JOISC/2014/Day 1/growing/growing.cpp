#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300005;
int n;
int a[N];
int b[N],m;
struct BIT
{
private:
    int n;
    int C[N];
protected:
    int lowbit(int x)
    {
        return x&-x;
    }
public:
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            C[i]=0;
        return;
    }
    void clear()
    {
        for(int i=1;i<=n;i++)
            C[i]=0;
        return;
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
int l[N],r[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        b[++m]=a[i];
    sort(b+1,b+m+1);
    m=unique(b+1,b+m+1)-b-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+m+1,a[i])-b;
    T.init(m);
    for(int i=1;i<=n;i++)
    {
        if(a[i]+1<=m) l[i]=T.query(a[i]+1,m);
        T.add(a[i],1);
    }
    T.clear();
    for(int i=n;i>=1;i--)
    {
        if(a[i]+1<=m) r[i]=T.query(a[i]+1,m);
        T.add(a[i],1);
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=min(l[i],r[i]);
    printf("%lld",ans);
    return 0;
}