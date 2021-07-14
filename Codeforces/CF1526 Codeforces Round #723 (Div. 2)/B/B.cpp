#include<iostream>
#include<cstdio>
using namespace std;
int T;
int n;
void solve()
{
    scanf("%d",&n);
    int y=n%11;
    int x=n/11-10*y;
    if(x<0) printf("NO\n");
    else printf("YES\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}