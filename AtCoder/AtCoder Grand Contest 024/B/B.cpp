#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
int p[N];
int a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        a[p[i]]=i;
    int cnt=0,res=0;
    for(int i=1;i<=n;i++)
        if(a[i]>a[i-1]) cnt++,res=max(res,cnt);
        else cnt=1;
    printf("%d",n-res);
    return 0;
}