#include<iostream>
#include<cstdio>
using namespace std;
int n;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x<0) x=-x;
        ans=gcd(ans,x);
    }
    printf("%d",ans);
    return 0;
}