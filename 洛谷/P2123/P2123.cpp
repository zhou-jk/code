#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T,n;
long long ans,sum;
struct Node
{
    int a,b;
}a[20001];
bool cmp(Node x,Node y)
{
	int dis1=x.a>x.b?1:(x.a==x.b?0:-1),dis2=y.a>y.b?1:(y.a==y.b?0:-1);
    if(dis1!=dis2) return dis1<dis2;
    if(x.a<x.b) return x.a<y.a;
    return x.b>y.b;
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
    	ans=sum=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].a,&a[i].b);
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
            sum+=a[i].a,ans=max(ans,sum)+a[i].b;
        printf("%lld\n",ans);
    }
    return 0;
}