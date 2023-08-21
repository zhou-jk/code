#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int N=200005;
int n;
long long m;
int a[N];
int l[N],r[N];
long long c[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%lld",&m);
    a[0]=n,a[n+1]=n;
    stack<int>s;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&a[s.top()]<=a[i]) s.pop();
        if(s.empty()) l[i]=0;
        else l[i]=s.top();
        s.emplace(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&a[s.top()]<a[i]) s.pop();
        if(s.empty()) r[i]=n+1;
        else r[i]=s.top();
        s.emplace(i);
    }
    for(int i=0;i<=n;i++)
        c[i]=0;
    for(int i=1;i<=n;i++)
        if(a[r[i]]!=a[i]) c[r[i]-l[i]-1]+=min(a[l[i]],a[r[i]])-a[i];
    long long ans=0;
    for(int i=n;i>=1;i--)
        if(m>=c[i]*i) ans+=c[i]*(i-1),m-=c[i]*i;
        else ans+=m-(m+i-1)/i,m=0;
    printf("%lld\n",ans);
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