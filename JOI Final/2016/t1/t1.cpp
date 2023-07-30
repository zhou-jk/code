#include<iostream>
#include<cstdio>
using namespace std;
const int N=20005;
const long long INF=4557430888798830399;
int n,m,k;
int a[N];
long long f[N];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    fill(f+1,f+n+1,INF);
    f[0]=0;
    for(int i=1;i<=n;i++)
    {
        int mx=a[i],mi=a[i];
        for(int j=i-1;j>=max(i-m,0);j--)
        {
            f[i]=min(f[i],f[j]+k+(long long)(i-j)*(mx-mi));
            mi=min(mi,a[j]),mx=max(mx,a[j]);
        }
    }
    printf("%lld",f[n]);
    return 0;
}