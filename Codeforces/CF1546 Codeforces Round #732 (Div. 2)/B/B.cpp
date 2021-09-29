#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,m;
char s[N],res[N];
void solve()
{
    scanf("%d%d",&n,&m);
    scanf("%s",res+1);
    for(int i=2;i<=2*n-1;i++)
    {
        scanf("%s",s+1);
        for(int j=1;j<=m;j++)
            res[j]^=s[j];
    }
    printf("%s\n",res+1);
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