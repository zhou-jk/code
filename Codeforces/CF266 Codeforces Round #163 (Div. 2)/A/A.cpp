#include<iostream>
#include<cstdio>
using namespace std;
const int N=55;
int n;
char s[N];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    int ans=0;
    for(int i=1,j=1;i<=n;i=j)
    {
        while(j<=n&&s[i]==s[j]) j++;
        ans+=j-i-1;
    }
    printf("%d",ans);
    return 0;
}