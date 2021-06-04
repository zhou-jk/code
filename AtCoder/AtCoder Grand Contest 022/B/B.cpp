#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    if(n==3)
    {
        printf("2 5 63");
        return 0;
    }
    for(int i=2;i<n&&i<=5000;i+=2)
    {
        int j=n-i;
        if(j<=15000&&j%3!=1)
        {
            for(int k=1,v=3;k<=i;k++,v+=6)
                printf("%d ",v);
            for(int k=1,v=2;k<=j;k++,v+=2)
                printf("%d ",v);
            return 0;
        }
    }
    return 0;
}