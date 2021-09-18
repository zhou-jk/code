#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n,a,b;
char s[N];
void solve()
{
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",s+1);
    if(b>=0) printf("%d\n",(a+b)*n);
    else
    {
        int c0=0,c1=0;
        for(int i=1,j=1;i<=n;i=j)
        {
            while(j<=n&&s[i]==s[j]) j++;
            if(s[i]=='0') c0++;
            else if(s[i]=='1') c1++;
        }
        int v=c0<c1?0:1;
        int ans=0;
        int len=0;
        for(int i=1,j=1;i<=n;i=j)
        {
            while(j<=n&&s[i]==s[j]) j++;
            if(s[i]-'0'==v) ans+=(j-i)*a+b;
            else len+=j-i;
        }
        ans+=len*a+b;
        printf("%d\n",ans);
    }
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