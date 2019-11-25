#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=41;
int n;
int cnta,cntb;
long long m,w[N];
long long suma[1<<(N/2)],sumb[1<<(N/2)],ans;
void dfs(int l,int r,long long sum,long long a[],int &cnt)
{
    if(sum>m) return;
    if(l>r)
    {
        a[++cnt]=sum;
        return;
    }
    dfs(l+1,r,sum+w[l],a,cnt);
    dfs(l+1,r,sum,a,cnt);
    return;
}
int main()
{
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&w[i]);
    dfs(1,n/2,0,suma,cnta);
    dfs(n/2+1,n,0,sumb,cntb);
    sort(suma+1,suma+cnta+1);
    for(int i=1;i<=cntb;i++)
        ans+=upper_bound(suma+1,suma+1+cnta,m-sumb[i])-suma-1;
    printf("%lld",ans);
    return 0;
}