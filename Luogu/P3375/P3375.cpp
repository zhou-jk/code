#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000005;
char a[N],b[N];
int lena,lenb;
int fail[N];
int main()
{
    scanf("%s%s",a+1,b+1);
    lena=strlen(a+1),lenb=strlen(b+1);
    int j=0;
    for(int i=2;i<=lenb;i++)
    {
        while(j>0&&b[j+1]!=b[i]) j=fail[j];
        if(b[j+1]==b[i]) j++;
        fail[i]=j;
    }
    for(int i=1;i<=lena;i++)
    {
        while(j>0&&b[j+1]!=a[i]) j=fail[j];
        if(b[j+1]==a[i]) j++;
        if(j==lenb) printf("%d\n",i-lenb+1);
    }
    for(int i=1;i<=lenb;i++)
        printf("%d ",fail[i]);
    return 0;
}