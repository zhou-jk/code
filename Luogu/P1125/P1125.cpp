#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[101];
int n;
int c;
int Max=-999,Min=999;
int main()
{
    scanf("%s",s+1);
    for(int i=1;i<=strlen(s+1);i++)
    {
        int b=0;
        for(int j=1;j<=strlen(s+1);j++)
            if(s[i]==s[j]) b++;
        if(b>Max) Max=b;
        if(b<Min) Min=b;
    }
    n=Max-Min;
    for(int i=2;i<n;i++)
        if(n%i==0)
        {
            printf("No Answer\n0");
            return 0;
        }
    if(n==2) printf("Lucky Word\n2");
    else if(n==1||n==0) printf("No Answer\n0");
    else if(c==0) printf("Lucky Word\n%d",n);
    return 0;
}