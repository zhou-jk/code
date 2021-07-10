#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,q;
char s[N];
int sum[N];
int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+s[i]-'a'+1;
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",sum[r]-sum[l-1]);
    }
    return 0;
}