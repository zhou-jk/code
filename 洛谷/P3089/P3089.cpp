#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1001;
int n,ans;
int f[N][N];
struct Node
{
    int x,p;
    bool operator <(const Node &a)const
    {
        return x<a.x;
    }
}a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].p);
    sort(a+1,a+n+1);
    for (int j=1;j<=n;j++)
    {
        int k=j-1,val=f[j][0]+a[j].p;
        for(int i=j+1;i<=n;i++)
        {
            while(k>0&&a[i].x-a[j].x>=a[j].x-a[k].x)
                val=max(val,f[j][k]+a[j].p),k--;
            f[i][j]=max(f[i][j],val);
            ans=max(ans,val+a[i].p);
        }
    }
    for(int j=n;j>0;j--)
    {
        int k=j+1,val=f[j][n+1]+a[j].p;
        for(int i=j-1;i>0;i--)
        {
            while(k<=n&&a[k].x-a[j].x<=a[j].x-a[i].x)
                val=max(val,f[j][k]+a[j].p),k++;
            f[i][j]=max(f[i][j],val);
            ans=max(ans,val+a[i].p);
        }
    }
    printf("%d",ans);
    return 0;
}