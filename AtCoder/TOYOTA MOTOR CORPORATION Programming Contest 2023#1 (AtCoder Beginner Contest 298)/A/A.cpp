#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
char s[N];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    bool f1=false,f2=true;
    for(int i=1;i<=n;i++)
        if(s[i]=='o') f1=true;
        else if(s[i]=='x') f2=false;
    if(f1&&f2) printf("Yes");
    else printf("No");
    return 0;
}