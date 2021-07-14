#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100005;
int n,L;
int a[N],b[N];
int sa[N],sb[N];
int main()
{
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    a[0]=0,b[0]=0;
    n++,a[n]=L+1,b[n]=L+1;
    for(int i=1;i<=n;i++)
        sa[i]=a[i]-a[i-1]-1,sb[i]=b[i]-b[i-1]-1;
    long long ans=0;
    for(int i=1,j=1;i<=n;i++)
    {
        long long sum=0;
        int l=n+1,r=0;
        while(j<=n&&sum+sa[j]<=sb[i])
        {
            if(sa[j]) l=min(l,j),r=max(r,j);
            sum+=sa[j],j++;
        }
        if(l<=r)
        {
            if(i<l) ans+=r-i;
            else if(i>r) ans+=i-l;
            else ans+=r-l;
        }
        if(sum!=sb[i])
        {
            printf("-1");
            return 0;
        }
    }
    printf("%lld",ans);
    return 0;
}