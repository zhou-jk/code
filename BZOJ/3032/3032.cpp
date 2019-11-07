#include<iostream>
#include<cstdio> 
#include<algorithm>
using namespace std; 
long long n,m,t,x,y,sum[100001],a[100001],b[100001]; 
long long hang()
{
	long long res=0;
    for(int i=1;i<=n;i++)
     	sum[i]=sum[i-1]+a[i]-t/n;
    sort(sum+1,sum+n+1); 
    for(int i=1;i<=n;i++)
     	res+=abs(sum[i]-sum[(n+1)/2]);
    return res;
}
long long lie()
{
	long long res=0;
    for(int i=1;i<=m;i++)
     	sum[i]=sum[i-1]+b[i]-t/m;
    sort(sum+1,sum+m+1); 
    for(int i=1;i<=m;i++)
     	res+=abs(sum[i]-sum[(m+1)/2]);
    return res;
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&t); 
    for(int i=1;i<=t;i++)
      	scanf("%lld%lld",&x,&y),a[x]++,b[y]++; 
    if(t%n==0&&t%m==0)
        printf("both %lld",hang()+lie()); 
    else if(t%n==0) printf("row %lld",hang()); 
    else if(t%m==0) printf("column %lld",lie()); 
    else printf("impossible");
	return 0; 
}
