#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=500005;
int n,m;
int a[N];
int pos[N];
struct BIT
{
    int n;
    int c[N];
    BIT()
    {
        n=0;
        memset(c,0,sizeof(c));
        return;
    }
    void resize(int _n)
    {
        n=_n;
        return;
    }
    void clear()
    {
        for(int i=0;i<=n;i++)
            c[i]=0;
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            c[i]+=y;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=c[i];
        return res;
    }
    int query(int l,int r)
    {
        if(l>r) return 0;
        return getsum(r)-getsum(l-1);
    }
}T;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    T.resize(n);
    T.clear();
    int cnt=0;
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,T.query(pos[a[i]]+1,i-1)-a[i]);
        if(pos[a[i]]) T.add(pos[a[i]],-1);
        else cnt++;
        T.add(i,1);
        pos[a[i]]=i;
    }
    int mex=1;
    while(pos[mex]) mex++;
    for(int i=n;i>=1;i--)
        if(pos[a[i]])
        {
            ans=max(ans,T.query(pos[a[i]]+1,n)-a[i]);
            pos[a[i]]=0;
        }
    ans=max(ans,cnt-mex);
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}