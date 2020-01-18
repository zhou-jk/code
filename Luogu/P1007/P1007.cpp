#include<iostream>
#include<cstdio>
using namespace std;
int n,l;
int ans1,ans2;
int main()
{
    scanf("%d%d",&l,&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ans1=max(ans1,min(l-x+1,x));
        ans2=max(ans2,max(l-x+1,x));
    }
    printf("%d %d",ans1,ans2);
    return 0;
}