#include<iostream>
#include<cstdio>
using namespace std;
int T,n;
int main()
{
    scanf("%d",&T);
    while(T--)
	{
        scanf("%d",&n);
        if((n-2)%7==0||n%7==0) printf("B\n");
        else printf("A\n");
    }
    return 0;
}
