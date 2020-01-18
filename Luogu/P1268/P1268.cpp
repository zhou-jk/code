#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1061109567;
int n,a[31][31],ans;
int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n==0) return 0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                scanf("%d",&a[i][j]);
        ans=a[1][2];
        for(int i=3;i<=n;i++)
        {
            int t=INF;
            for(int j=2;j<i;j++)
                t=min(t,(a[1][i]+a[j][i]-a[1][j])/2);
            ans+=t;
        }
        printf("%d\n",ans);
    }
    return 0;
}