#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int s[5];
int t[5];
void solve()
{
    scanf("%d%d%d%d",&s[1],&s[2],&s[3],&s[4]);
    for(int i=1;i<=4;i++)
        t[i]=s[i];
    sort(t+1,t+4+1);
    int v1=max(s[1],s[2]),v2=max(s[3],s[4]);
    if(v1>v2) swap(v1,v2);
    if(v1==t[3]&&v2==t[4]) printf("YES\n");
    else printf("NO\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}