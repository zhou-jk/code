#include<iostream>
#include<cstdio>
using namespace std;
const int N=55;
int T;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    if(sum>=n) printf("%d\n",sum-n);
    else printf("1\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}