#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=31;
long long n;
int len;
char s[N];
char calc(long long id)
{
    if(id<=len) return s[id];
    long long tmp=len;
    while((tmp*2)<id) tmp*=2;
    if(id-tmp==1) return calc(tmp);
    else return calc(id-tmp-1);
}
int main()
{
    scanf("%s%lld",s+1,&n);
    len=strlen(s+1);
    printf("%c",calc(n));
    return 0;
}