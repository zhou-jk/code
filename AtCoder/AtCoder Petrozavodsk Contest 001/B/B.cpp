#include<iostream>
#include<cstdio>
using namespace std;
const int N=10005;
int n;
int a[N],b[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    long long x=0,y=0;
    for(int i=1;i<=n;i++)
        if(a[i]>=b[i]) y+=a[i]-b[i];
        else
        {
            x+=(b[i]-a[i]+1)/2;
            if((b[i]-a[i])%2==1) y++;
        }
    if(x>=y) printf("Yes");
    else printf("No");
    return 0;
}