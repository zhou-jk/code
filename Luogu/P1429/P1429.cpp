#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
double ans=2e9;
struct Node
{
	double x,y;
}a[200001],f[200001];
bool cmp(Node a, Node b)
{
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
inline double count(Node a,Node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void calc(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2,cnt=0;
	calc(l,mid);
    calc(mid+1,r);
	for(int i=mid+1;i<=r;i++)
		if(a[i].x-a[mid].x<ans) f[++cnt]=a[i];
    for(int i=l;i<=mid;i++)
    {
		if(a[mid].x-a[i].x>=ans) continue;
		for(int j=1;j<=cnt;j++)
            ans=min(ans,count(a[i],f[j]));
	}
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
    calc(1,n);
    printf("%.4lf",ans);
    return 0;
}