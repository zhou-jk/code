#include<iostream>
#include<cstdio>
using namespace std;
int n,a,b;
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    if((b-a-1)%2==1) printf("Alice");
    else printf("Borys");
    return 0;
}