#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n;
int calc(long long x)
{
    if(x==0) return 0;
    int sum=0;
    while(x)
        sum+=x%10,x/=10;
    return sum;
}
int count(long long x)
{
    if(x==0) return 1;
    int cnt=0;
    while(x)
        cnt++,x/=10;
    return cnt;
}
int main()
{
    scanf("%lld",&n);
    int len=count(n);
    if(len==1)
    {
        printf("%lld",n);
        return 0;
    }
    long long pw=1;
    for(int i=1;i<len;i++)
        pw*=10;
    int ans=max(calc(n),calc(n/pw*pw-1));
    printf("%d",ans);
    return 0;
}