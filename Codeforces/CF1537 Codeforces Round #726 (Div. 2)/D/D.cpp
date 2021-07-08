#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int T;
int n;
void solve()
{
    scanf("%d",&n);
    if(n&1)
    {
        printf("Bob\n");
        return;
    }
    int pw=0;
    while(n%2==0) n/=2,pw++;
    if(n==1&&(pw&1)) printf("Bob\n");
    else printf("Alice\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}