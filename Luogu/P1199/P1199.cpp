#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[501][501];
int ans;
int fm,sm;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            a[j][i]=a[i][j];
        }
    for(int i=1;i<=n;i++)
    {
        sm=fm=0;
        for(int j=1;j<=n;j++)
            if(a[i][j]>fm) sm=fm,fm=a[i][j];
            else if(a[i][j]>sm) sm=a[i][j];
        ans=max(ans,sm);
    }
    printf("1\n%d",ans);
    return 0;
}