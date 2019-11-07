#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[100001],l,r,mid;
bool check(int x)
{
	int k=0,cnt=0;
    for(int i=1;i<=n;i++)
	{
        if(k+a[i]<=x) k+=a[i];
        else k=a[i],cnt++;
    }
    return cnt>=m;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
	{
        scanf("%d",&a[i]);
        r+=a[i];
        l=max(l,a[i]);
    }
    while(l<=r)
	{
        mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%d",l);
    return 0;
}