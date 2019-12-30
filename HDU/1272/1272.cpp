#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000001;
int n,a,b,c;
long long sum[N],dp[N];
int q[N],head,tail;
double calc(int k,int j)
{
    return (double)(dp[j]-dp[k]+a*(sum[j]*sum[j]-sum[k]*sum[k])+b*(sum[k]-sum[j]))/(double)(2*a*(sum[j]-sum[k]));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&a,&b,&c);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum[i]=sum[i-1]+x;
        }
        head=1,tail=0;
        dp[0]=0;
        q[++tail]=0;
        for(int i=1;i<=n;i++)
        {
            while(head<tail&&calc(q[head],q[head+1])<sum[i])
                head++;
            dp[i]=dp[q[head]]+a*(sum[i]-sum[q[head]])*(sum[i]-sum[q[head]])+b*(sum[i]-sum[q[head]])+c;
            while(head<tail&&calc(q[tail-1],q[tail])>calc(q[tail],i))
                tail--;
            q[++tail]=i;
        }
        printf("%lld\n",dp[n]);
    }
	return 0;
}