#include<iostream>
#include<cstdio>
using namespace std;
const int N=50002;
int n;
int l[N],r[N];
int a[N],b[N],c[N];
int ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&l[i],&r[i]);
    a[1]=1,a[2]=l[1];
    for(int i=2;i<=n;i++)
        if(a[i-1]==l[a[i]]) a[i+1]=r[a[i]];
        else if(a[i-1]==r[a[i]]) a[i+1]=l[a[i]];
        else
        {
            printf("-1");
            return 0;
        }
    if(a[1]!=a[n+1])
    {
        printf("-1");
        return 0;
    }
    for(int i=1;i<=n;i++)
        b[(a[i]-i+n)%n+1]++,c[(a[n-i+1]-i+n)%n+1]++;
    for(int i=1;i<=n;i++)
        ans=max(ans,max(b[i],c[i]));
    printf("%d",n-ans);
    return 0;
}