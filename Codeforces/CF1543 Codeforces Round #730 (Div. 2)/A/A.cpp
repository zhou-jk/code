#include<iostream>
#include<cstdio>
using namespace std;
int T;
long long a,b;
void solve()
{
    scanf("%lld%lld",&a,&b);
    if(a==b)
    {
        printf("0 0\n");
        return;
    }
    if(a<b) swap(a,b);     
    printf("%lld %lld\n",a-b,min((a+a-b-1)/(a-b)*(a-b)-a,a-a/(a-b)*(a-b)));
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}