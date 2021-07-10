#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N=500005;
int T;
int n;
char s[N];
map<pair<int,int>,int>pre;
int ans[N];
void solve()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    pre.clear();
    int d=0,k=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='D') d++;
        else if(s[i]=='K') k++;
        if(k==0||d==0)
        {
            ans[i]=ans[i-1]+1;
            continue;
        }
        int v=__gcd(d,k);
        int a=d/v,b=k/v;
        ans[i]=ans[pre[{a,b}]]+1;
        pre[{a,b}]=i;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
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