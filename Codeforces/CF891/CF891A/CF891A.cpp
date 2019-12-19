#include<iostream>
#include<cstdio>
using namespace std;
const int N=200001;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int n;
int a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(n==1&&a[1]==1)
    {
        printf("0");
        return 0;
    }
    int k=a[1],cnt=(a[1]==1);
    for(int i=2;i<=n;i++)
    {
        k=gcd(k,a[i]);
        if(a[i]==1)cnt++;
    }
    if(k!=1)
    {
        printf("-1");
        return 0;
    }
    int p=0,ans=3000;
    for(int i=1;i<=n;i++)
    {
        int k=a[i];
        for(int j=i+1;j<=n;j++)
        {
            k=gcd(k,a[j]);
            if(k==1)
            {
                p=j-i+1;
                break;
            }
        }
        ans=min(ans,p);
    }
    printf("%d",ans+n-2-cnt);
    return 0;
}