#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1001;
struct Node
{
    int x,y;
}a[N];
int c,n,tot;
int sum[N][N];
int b[10001];
bool check(int x)
{
    if(x>=b[tot]) return true;
    int p=upper_bound(b+1,b+tot+1,b[tot]-x+1)-b-1;
    for(int i=1;i<=p;i++)
        for(int j=1;j<=p;j++)
        {
            int tx=upper_bound(b+1,b+tot+1,b[i]+x-1)-b-1,ty=upper_bound(b+1,b+tot+1,b[j]+x-1)-b-1;
            if(sum[tx][ty]-sum[i-1][ty]-sum[tx][j-1]+sum[i-1][j-1]>=c) return true;
        }
    return false;
}
int main()
{
    scanf("%d%d",&c,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        b[++tot]=a[i].x,b[++tot]=a[i].y;
    }
    sort(b+1,b+tot+1);
    tot=unique(b+1,b+tot+1)-b-1;
    for(int i=1;i<=n;i++)
    {
        int tx=lower_bound(b+1,b+tot+1,a[i].x)-b,ty=lower_bound(b+1,b+tot+1,a[i].y)-b;
        sum[tx][ty]++;
    }
    b[++tot]=10001;
    for(int i=1;i<=tot;i++)
        for(int j=1;j<=tot;j++)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sum[i][j];
    int l=1,r=10000,ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}