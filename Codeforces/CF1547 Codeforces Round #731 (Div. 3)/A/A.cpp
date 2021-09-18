#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int xa,ya,xb,yb,xf,yf;
void solve()
{
    scanf("%d%d",&xa,&ya);
    scanf("%d%d",&xb,&yb);
    scanf("%d%d",&xf,&yf);
    int ans=abs(xa-xb)+abs(ya-yb);
    if((xa==xb&&xa==xf&&min(ya,yb)<=yf&&yf<=max(ya,yb))||(ya==yb&&ya==yf&&min(xa,xb)<=xf&&xf<=max(xa,xb))) ans+=2;
    printf("%d\n",ans);
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}