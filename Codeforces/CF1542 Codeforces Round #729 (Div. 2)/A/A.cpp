#include<iostream>
#include<cstdio>
using namespace std;
const int N=205;
int T;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
        scanf("%d",&a[i]);
    int c1=0,c2=0;
    for(int i=1;i<=2*n;i++)
        if(a[i]%2==1) c1++;
        else c2++;
    if(c1==c2) printf("Yes\n");
    else printf("No\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}