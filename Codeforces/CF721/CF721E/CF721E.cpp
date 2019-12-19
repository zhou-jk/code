#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int L,n,p,t;
int dp[N],f[N];
int main()
{
    scanf("%d%d%d%d",&L,&n,&p,&t);
    f[0]=-t;
    for (int i=1,j=0;i<=n;i++,j--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        f[i]=f[i-1];
        dp[i]=dp[i-1];
        while(j<i&&f[j]+t<=r)
        {
            int x=max(f[j]+t,l),y=dp[j]+(r-x)/p,z=r-(r-x)%p;
            if(y>dp[i]||(y==dp[i]&&z<f[i])) dp[i]=y,f[i]=z;
            j++;
        }
    }
    printf("%d",dp[n]);
    return 0;
}