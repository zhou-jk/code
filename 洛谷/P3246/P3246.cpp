#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
using namespace std;
const int N=100005;
pair<int,int> Min[N][17];
int n,Q;
stack<int>s;
long long a[N],sum[N];
long long dp[N],f[N];
long long h[N],g[N];
void init()
{
    for(int i=1;i<=n;i++)
        Min[i][0]=make_pair(a[i],i);
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
    return;
}
pair<int,int> RMQ(int l,int r)
{
    int k=log2(r-l+1);
    return min(Min[l][k],Min[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    init();
    while(!s.empty()) s.pop();
    for(int i=1;i<=n;i++)
    {
        long long num=1,now=dp[i-1];
        while(!s.empty()&&a[s.top()]>=a[i]) now-=sum[s.top()]*a[s.top()],num+=sum[s.top()],s.pop();
        s.push(i);
        now+=num*a[i];
        sum[s.top()]=num;
        dp[i]=now;
    }
    while(!s.empty()) s.pop();
    for(int i=n;i>=1;i--)
    {
        long long num=1,now=g[i+1];
        while(!s.empty()&&a[s.top()]>=a[i])
            now-=sum[s.top()]*a[s.top()],num+=sum[s.top()],s.pop();    
        s.push(i);
        now+=num*a[i];
        sum[s.top()]=num;
        g[i]=now;
    }
    for(int i=1;i<=n;i++)
        f[i]=f[i-1]+dp[i];
    for(int i=n;i>=1;i--)
        h[i]=h[i+1]+g[i];
    while(Q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int p=RMQ(l,r).second;
        long long ans=a[p]*(p-l+1)*(r-p+1);
        ans+=(f[r]-f[p])-dp[p]*(r-p);
        ans+=(h[l]-h[p])-g[p]*(p-l);
        printf("%lld\n",ans);
    }
    return 0;
}