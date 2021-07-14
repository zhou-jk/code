#include<iostream>
#include<cstdio>
using namespace std;
const int N=55;
int T;
int n,m;
char s[N][N];
bool check(char a,char b)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if((i+j)%2==0)
            {
                if(s[i][j]!='.'&&s[i][j]!=a) return false;
            }
            else
            {
                if(s[i][j]!='.'&&s[i][j]!=b) return false;
            }
    return true;
}
void print(char a,char b)
{
    printf("YES\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if((i+j)%2==0) printf("%c",a);
            else printf("%c",b);
        printf("\n");
    }
    return;
}
void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    if(check('R','W')) print('R','W');
    else if(check('W','R')) print('W','R');
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