#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
void solve()
{
    int xa,ya,xb,yb,xc,yc;
    scanf("%d%d",&xa,&ya);
    scanf("%d%d",&xb,&yb);
    scanf("%d%d",&xc,&yc);
    int x1=xa-xb,x2=xa-xc,y1=ya-yb,y2=ya-yc;
    int x,y;
    if((x1>=0)!=(x2>=0)) x=0;
    else x=min(abs(x1),abs(x2));
    if((y1>=0)!=(y2>=0)) y=0;
    else y=min(abs(y1),abs(y2));
    printf("%d\n",x+y+1);
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