#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int a[500001];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        k^=a[i];
    if(k==0)
    {
        printf("lose");
        return 0;
    }
    for(int i=1;i<=n;i++)
        if((a[i]^k)<a[i])
        {
            printf("%d %d\n",a[i]-(a[i]^k),i);
            a[i]^=k;
            break;
        }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}