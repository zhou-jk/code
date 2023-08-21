#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2005;
const int INF=1061109567;
int n;
struct Seg
{
    int l,r;
}seg[N];
int f[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&seg[i].l,&seg[i].r);
    sort(seg+1,seg+n+1,[=](const Seg &a,const Seg &b){return (a.r<b.r)||(a.r==b.r&&a.l<b.l);});
    fill(f+1,f+n+1,INF);
    for(int i=2;i<=n;i++)
    {
        int j=i-1,mx=0;
        for(j=i-1;j>=1;j--)
            if(seg[j].r>=seg[i].l)
            {
                mx=max(mx,seg[j].l);
            }
            else break;
        mx=min(mx,seg[i].l);
        if(j==i-1) continue;
        f[i]=i-2;
        for(int k=1;seg[k].r<mx;k++)
            f[i]=min(f[i],f[k]+i-k-2);
    }
    int ans=INF;
    for(int i=0;i<=n;i++)
        ans=min(ans,f[i]+n-i);
    printf("%d\n",ans);
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}