#include<iostream>
#include<cstdio>
using namespace std;
int n;
void solve()
{
    scanf("%d",&n);
    if(n<=4) printf("Bob\n");
    else printf("Alice\n");
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