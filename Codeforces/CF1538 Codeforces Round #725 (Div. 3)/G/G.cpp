#include<iostream>
#include<cstdio>
using namespace std;
int T;
int x,y,a,b;
void solve()
{
    scanf("%d%d%d%d",&x,&y,&a,&b);
    if(x>y) swap(x,y);
    if(a>b) swap(a,b);
    if(a==b)
    {
        printf("%d\n",min(x,y)/a);
        return;
    }
    int c1=min((y-x)/(b-a),min(x/a,y/b));
    x-=a*c1,y-=b*c1;
    int c2=min(x,y)/(a+b);
    x-=(a+b)*c2,y-=(a+b)*c2;
    int c3=min(x/a,y/b);
    int ans=c1+c2*2+c3;
    printf("%d\n",ans);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}