#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
int a[N],b[N];
long long c[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    int maxa=0;
    for(int i=1;i<=n;i++)
        maxa=max(maxa,a[i]),c[i]=max(c[i-1],(long long)maxa*b[i]);
    for(int i=1;i<=n;i++)
        printf("%lld\n",c[i]);
    return 0;
}