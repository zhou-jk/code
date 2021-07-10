#include<iostream>
#include<cstdio>
using namespace std;
const int N=500005;
int n,k;
char s[N];
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    int p=1;
    for(int i=2;i<=n;i++)
    {
        int u=i%p==0?p:i%p;
        if(s[i]>s[u]) break;
        else if(s[i]<s[u]) p=i;
    }
    for(int i=1;i<=k;)
        for(int j=1;j<=p&&i<=k;i++,j++)
            printf("%c",s[j]);
    return 0;
}