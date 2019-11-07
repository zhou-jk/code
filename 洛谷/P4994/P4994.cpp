#include<iostream>
#include<cstdio>
using namespace std;
int m;
int main()
{
    scanf("%d",&m);
    int f0=1,f1=1,f2;
    for(int i=1;;i++)
    {
        f2=(f0+f1)%m,f0=f1,f1=f2;
        if(f0%m==0&&f1%m==1)
        {
            printf("%d",i+1);
            return 0;
        }
    }
    return 0;
}