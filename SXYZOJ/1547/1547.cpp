#include<iostream>
#include<cstdio>
using namespace std;
int ksm(int a,int b,int p)
{
    int res=1;
    while(b)
    {
        if(b&1) res=1LL*res*a%p;
        a=1LL*a*a%p,b>>=1;
    }
    return res;
}
int a,b,k;
int main()
{
    scanf("%d%d%d",&a,&b,&k);
    int s=a+b;
    a=1LL*a*ksm(2,k,s)%s,b=1LL*b*ksm(2,k,s)%s;
    printf("%d",min(a,b));
    return 0;
}