#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
char s[N];
void solve()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        if(s[i]!='1')
        {
            printf("YES\n");
            return;
        }
    printf("NO\n");
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