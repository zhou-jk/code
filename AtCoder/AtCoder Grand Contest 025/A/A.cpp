#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1061109567;
int n;
int calc(int x)
{
    int res=0;
    while(x)
        res+=x%10,x/=10;
    return res;
}
int main()
{
    scanf("%d",&n);
    int ans=INF;
    for(int a=1;a<n;a++)
    {
        int b=n-a;
        ans=min(ans,calc(a)+calc(b));
    }
    printf("%d",ans);
    return 0;
}