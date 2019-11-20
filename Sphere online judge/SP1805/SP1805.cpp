#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n;
int a[N];
int pre[N],nxt[N];
int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n==0) return 0;
        long long res=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pre[i]=i,nxt[i]=i;
        }
        for(int i=2;i<=n;i++)
        {
            int j=i;
            while(j>=1&&a[i]<=a[j]) j=pre[j]-1;
            pre[i]=j+1;
        }
        for (int i=n-1;i>=1;i--)
        {
            int j=i;
            while(j<=n&&a[i]<=a[j]) j=nxt[j]+1;
            nxt[i]=j-1;
        }
        for(int i=1;i<=n;i++)
            res=max(res,(long long)(nxt[i]-pre[i]+1)*a[i]);
        printf("%lld\n",res);
    }
    return 0;
}