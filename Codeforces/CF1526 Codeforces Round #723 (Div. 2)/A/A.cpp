#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=55;
int T;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    int l=1,r=2*n;
    for(int i=1;i<=2*n;i++)
        if(i%2==1) printf("%d ",a[l++]);
        else printf("%d ",a[r--]);
    printf("\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}