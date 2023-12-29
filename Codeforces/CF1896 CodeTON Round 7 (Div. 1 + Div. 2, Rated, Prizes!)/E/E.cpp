#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n;
int a[N];
struct BIT
{
    int n;
    int C[N+N];
    void resize(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            C[i]=0;
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
}T;
int ans[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    T.resize(n*2);
    for(int i=n;i>=1;i--)
        if(a[i]>=i) T.add(a[i]+n,1);
    for(int i=n;i>=1;i--)
    {
        int to=a[i];
        if(a[i]<i) to+=n;
        ans[a[i]]=to-i-T.getsum(to);
        T.add(to,1);
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
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