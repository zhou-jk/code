#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
    for(int i=1;i<(1<<n);i++)
    {
        for(int j=0;j<(1<<n);j++)
            if(__builtin_popcount(i&j)&1) printf("A");
            else printf("B");
        printf("\n");
    }
    return 0;
}