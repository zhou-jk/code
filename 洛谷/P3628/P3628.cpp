#include<iostream>
#include<cstdio>
using namespace std;
int n,a,b,c;
long long sum[1000001],f[1000001];
int q[1000001],head=1,tail=1;
double calc(int k,int j)
{
    return (double)(f[j]-f[k]+a*(sum[j]*sum[j]-sum[k]*sum[k])+b*(sum[k]-sum[j]))/(double)(2*a*(sum[j]-sum[k]));
}
int main()
{
    scanf("%d%d%d%d",&n,&a,&b,&c);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum[i]=sum[i-1]+x;
    }
	for(int i=1;i<=n;i++)
	{
		while(head<tail&&calc(q[head],q[head+1])<sum[i])
            head++;
		f[i]=f[q[head]]+a*(sum[i]-sum[q[head]])*(sum[i]-sum[q[head]])+b*(sum[i]-sum[q[head]])+c;
		while(head<tail&&calc(q[tail-1],q[tail])>calc(q[tail],i))
            tail--;
		q[++tail]=i;
	}
	printf("%lld",f[n]);
	return 0;
}