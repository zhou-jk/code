#include<iostream>
#include<cstdio>
int a[8],sum;
double ans=7*6*5*4*3*2*1;
int main()
{
    for(int i=1;i<=7;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(int i=1;i<=7;i++)
    {
        ans*=a[i];
        if(i!=7) ans/=sum,sum--;
    }
    printf("%.3lf",ans);
    return 0;
}