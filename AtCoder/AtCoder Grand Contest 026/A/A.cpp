#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
int a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0;
    for(int i=1,j=1;i<=n;i=j)
    {
        while(j<=n&&a[j]==a[i]) j++;
        ans+=(j-i)/2;
    }
    printf("%d",ans);
    return 0;
}