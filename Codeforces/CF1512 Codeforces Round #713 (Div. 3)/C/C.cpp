#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int T;
int n;
int a,b;
char s[N];
void solve()
{
    scanf("%d%d",&a,&b);
    scanf("%s",s+1);
    n=a+b;
    for(int i=1;i<=n/2;i++)
    {
        if(s[i]!='?'&&s[n-i+1]!='?'&&s[i]!=s[n-i+1])
        {
            printf("-1\n");
            return;
        }
        if(s[i]=='0'||s[n-i+1]=='0') s[i]=s[n-i+1]='0',a-=2;
        else if(s[i]=='1'||s[n-i+1]=='1') s[i]=s[n-i+1]='1',b-=2;
    }
    if(n%2==1)
    {
        if(s[n/2+1]=='0') a--;
        if(s[n/2+1]=='1') b--;
    }
    if(a<0||b<0)
    {
        printf("-1\n");
        return;
    }
    for(int i=1;i<=n/2;i++)
        if(s[i]=='?'&&s[n-i+1]=='?')
        {
            if(a>b) s[i]=s[n-i+1]='0',a-=2;
            else s[i]=s[n-i+1]='1',b-=2;
        }
    if(n%2==1&&s[n/2+1]=='?')
    {
        if(a>b) s[n/2+1]='0',a--;
        else s[n/2+1]='1',b--;
    }
    if(a==0&&b==0) printf("%s\n",s+1);
    else printf("-1\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}