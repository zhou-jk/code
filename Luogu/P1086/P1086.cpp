#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,t,cnt,ans;
struct Node
{
    int x,y,time,w;
}e[4001];
int x;
bool cmp(Node x,Node y)
{
	return x.w>y.w;
}
int main()
{
    scanf("%d%d%d",&m,&n,&t);
    for(int i=1;i<=m;i++)
       	for(int j=1;j<=n;j++)
	   	{
          	scanf("%d",&e[++cnt].w);
            e[cnt].x=i,e[cnt].y=j;
      	}
    sort(e+1,e+cnt+1,cmp);
    e[1].time=e[1].x+1;
    if(e[1].time+e[1].x<=t) ans+=e[1].w;
    for(int i=2;i<=cnt;i++)
	{
        e[i].time=e[i-1].time+abs(e[i].x-e[i-1].x)+abs(e[i].y-e[i-1].y)+1;
        if(e[i].time+e[i].x<=t) ans+=e[i].w;
    }
    printf("%d",ans);
    return 0;
}