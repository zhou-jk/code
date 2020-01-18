#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int base,len;
long long ans;
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res*=a;
        a*=a,b>>=1;
    }
    return res;
}
int calc(int k)
{
    char s[12]={0};
    memset(s,0,sizeof(s));
    sprintf(s,"%d",k);
    int ans=0,w=0;
    len=strlen(s);
    for(int i=0;i<len;i++)
        w=w*10+s[i]-'0',ans+=w-ksm(10,i)+1;
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<10;i++)
        if(n==ksm(10,i)&&m!=i+1)
        {
            printf("0");
            return 0;
        }
    base=calc(n);
    if(m<base)
    {
        printf("0");
        return 0;
    }
    if(m==base)
    {
        printf("%d",n);
        return 0;
    }
    ans=ksm(10,len),m-=base;
    for(int i=1;;++i)
    {
        long long tmp=n*ksm(10,i)-ksm(10,len+i-1);
        if(m>tmp) m-=tmp,ans*=10;
        else break;
    }
    ans+=m-1;
    printf("%lld",ans);
    return 0;
}