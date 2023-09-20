#include<iostream>
#include<cstdio>
using namespace std;
char s[5];
int main()
{
    scanf("%s",s);
    int d=0,t=0;
    for(int i=0;i<5;i++)
        if(s[i]=='D') d++;
        else if(s[i]=='T') t++;
    if(d>=3) printf("DRX");
    else printf("T1"); 
    return 0;
}
