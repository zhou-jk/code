#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    double sum=420000.0/n,res=420000.0/n;
    for(int i=1;i<n;i++)
        sum*=(2*i-1.0)/(2*i),res+=sum;
    printf("%.2lf",res);
    return 0;
}