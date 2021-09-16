#include<iostream>
#include<cstdio>
using namespace std;
int x,y;
int main()
{
    scanf("%d%d",&x,&y);
    if(x%y!=0) printf("%d",x);
    else printf("-1");
    return 0;
}