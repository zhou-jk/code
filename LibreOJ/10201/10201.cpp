#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
bool isprime(int x)
{
    if(x==1) return false;
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    if(n==1)
    {
        printf("1\n1");
        return 0;
    }
    else if(n==2)
    {
        printf("1\n1 1");
        return 0;
    }
    printf("2\n");
    for(int i=2;i<=n+1;i++)
    {
        if(isprime(i)) printf("1 ");
        else printf("2 ");
    }
    return 0;
}