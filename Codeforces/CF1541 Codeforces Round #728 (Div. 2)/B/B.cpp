#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int T;
int n;
int a[N];
vector<int>pos[N<<1];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=2*n;i++)
        pos[i].clear();
    for(int i=1;i<=n;i++)
        pos[a[i]].emplace_back(i);
    long long ans=0;
    for(int x=1;x<=2*n;x++)
        for(int y=1;x*y<=2*n;y++)
            for(int i:pos[x])
            {
                int j=x*y-i;
                if(j>i&&j<=n&&a[j]==y) ans++;
            }
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