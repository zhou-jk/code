#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-4;
double H,S1,V,K,L;
int n,ans;
int main()
{
    scanf("%lf%lf%lf%lf%lf%d",&H,&S1,&V,&L,&K,&n);
    for(int i=0;i<n;i++)
        if(i>=S1-sqrt(H/5)*V-eps&&i<=S1-sqrt((H-K)/5)*V+L+eps) ans++;
    printf("%d",ans);
    return 0;
}