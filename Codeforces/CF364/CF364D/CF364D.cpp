#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
const int N=1000001;
int n;
long long a[N];
long long d[N],cnt;
long long num[N],ans;
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
int brand()
{
    return (rand()<<15)+(rand()<<1)+(rand()&1);
}
int main()
{
	srand((unsigned)time(NULL));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
	int k=12;
	while(k--)
    {
		long long x=a[brand()%n+1];
        int cnt=0;
        for(int i=1;i<=sqrt(x);i++)
            if(x%i==0)
            {
                d[++cnt]=i;
                if(x/i!=i) d[++cnt]=x/i;
            }
		sort(d+1,d+cnt+1);
        memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)
            num[lower_bound(d+1,d+cnt+1,gcd(x,a[i]))-d]++;
		for(int i=cnt;i>=1;i--)
        {
			int tmp=0;
			for(int j=i+1;j<=cnt;j++)
				if(d[j]%d[i]==0) tmp+=num[j];
			if((num[i]+tmp)*2>=n)
            {
                ans=max(ans,d[i]);
                break;
            }
		}
	}
	printf("%lld",ans);
    return 0;
}
