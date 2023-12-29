#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int p[N],pos[N];
int pre[N],suf[N];
map<pair<int,int>,int>mp;
struct BIT
{
    int C[N];
    int lowbit(int x)
    {
        return x&-x;
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
}T;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    if(is_sorted(p+1,p+n+1))
    {
        cout<<n-2<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
        pos[p[i]]=i;
    pre[0]=0;
    for(int i=1;i<=n;i++)
        pre[i]=max(pre[i-1],p[i]);
    suf[n+1]=n+1;
    for(int i=n;i>=1;i--)
        suf[i]=min(suf[i+1],p[i]);
    int cnt=0;
    T.clear();
    mp.clear();
    for(int i=1;i<=n;i++)
    {
        if(p[i]==i)
        {
            if(pre[i-1]==i-1)
            {
                cnt++;
            }
            else if(T.getsum(i-1)==i-2)
            {
                int l=pos[pre[i]],r=pos[suf[i]];
                mp[{l,r}]++;
            }
        }
        T.add(p[i],1);
    }
    for(int i=1;i<=n;i++)
        if(p[i]!=i)
        {
            int l=i,r=pos[i];
            if(l>r) swap(l,r);
            if(pos[i]>i)
            {
                if(pre[i-1]==i-1) mp[{l,r}]++;
            }
            else
            {
                if(suf[i+1]==i+1) mp[{l,r}]++;
            }
        }
    int ans=cnt;
    for(auto [lr,v]:mp)
        ans=max(ans,cnt+v);
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