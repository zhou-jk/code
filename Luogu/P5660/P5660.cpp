#include<iostream>
#include<cstdio>
using namespace std;
const int N=8;
char s[N+1];
int main()
{
    scanf("%s",s+1);
    int ans=0;
    for(int i=1;i<=N;i++)
        if(s[i]=='1') ans++;
    printf("%d",ans);
    return 0;
}