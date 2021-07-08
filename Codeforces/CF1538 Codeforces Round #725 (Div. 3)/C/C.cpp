#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int T;
int n,l,r;
int a[N];
long long res;
void solve(int l,int r,int x)
{
    if(l==r) return;
    int mid=(l+r)/2;
    solve(l,mid,x);
    solve(mid+1,r,x);
    vector<int>pre,nxt;
    for(int i=l;i<=mid;i++)
        pre.emplace_back(a[i]);
    for(int i=mid+1;i<=r;i++)
        nxt.emplace_back(a[i]);
    sort(pre.begin(),pre.end());
    sort(nxt.begin(),nxt.end());
    for(int i=0,j=nxt.size()-1;i<(int)pre.size();i++)
    {
        while(j>=0&&pre[i]+nxt[j]>x) j--;
        res+=j;
    }
    return;
}
long long calc(int x)
{
    res=0;
    solve(1,n,x);
    return res;
}
void solve()
{
    scanf("%d%d%d",&n,&l,&r);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    long long ans=calc(r)-calc(l-1);
    printf("%lld\n",ans);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}