#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    int n=rand()%100+1;
    for(int i=1;i<=n;i++)
        printf("%d",rand()%2);
    return 0;

}