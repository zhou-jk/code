#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=30;
int n;
char s[N];
int pos[N];
void solve()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    fill(pos+1,pos+26+1,-1);
    for(int i=1;i<=n;i++)
        if(pos[s[i]-'a'+1]!=-1)
        {
            printf("NO\n");
            return;
        }
        else pos[s[i]-'a'+1]=i;
    if(pos[1]==-1)
    {
        printf("NO\n");
        return;
    }
    int l=pos[1],r=pos[1];
    for(int i=2;i<=n;i++)
        if(pos[i]+1==l) l=pos[i];
        else if(pos[i]-1==r) r=pos[i];
        else
        {
            printf("NO\n");
            return;
        }
    printf("YES\n");
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