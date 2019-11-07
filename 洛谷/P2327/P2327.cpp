#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,ans=0;
int a[10001],f[10001];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<=a[1];i++)
    {
        memset(f,0,sizeof(f));
        f[1]=i;
        f[2]=a[1]-i;
        for(int i=3;i<=n;i++)
            f[i]=a[i-1]-f[i-2]-f[i-1];
        if(a[n]==f[n]+f[n-1]) ans++; 
    }
    printf("%d",ans);
    return 0;
}