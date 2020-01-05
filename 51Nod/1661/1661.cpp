#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
long long a[N];
long long b[N];
long long k;
long long sg(long long a)
{
    if(a==1) return 0;
    if((a-1)%k==0) return sg((a-1)/k);
    else return a-a/k-(a%k!=0);
}
long long find(long long a,long long y,long long c)
{
    if(a>=y&&a<c) return a;
    if((c-1)/k<a) return c;
    return find(a*k+1,y,c);
}
long long solve(long long a)
{
    long long l=1,r=1e18;
    while(l<=r)
	{
        long long mid=(l+r)/2;
        if((mid-1-(mid-1)/k)>=a) r=mid-1;
        else l=mid+1;
    }
    return l;
}
int main()
{
    scanf("%d%lld",&n,&k);
    long long ans=0;
    for(int i=1;i<=n;i++)
	{
        scanf("%lld",&a[i]);
        b[i]=sg(a[i]);
        ans^=b[i];
    }
    if(ans==0)
    {
    	printf("Bob");
    	return 0;
	}
    printf("Alice ");
    for(int i=1;i<=n;i++)
	{
        if(a[i]==1) continue;
        long long now=solve(ans^b[i]);
        now=find(now,a[i]/k+(a[i]%k!=0),a[i]);
        if(now<a[i])
		{
            printf("%d %lld",i,now);
            return 0;
        }
    }
    return 0;
}
