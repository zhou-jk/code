#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int vis[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int p[]={0,3,5,7,11,13,17,19,23,29,31,37};
int T;
char str[10];
int a[100];
int b[66666];
int cnt,len;
int isprime(int n)
{
    if(n==1) return true;
	for(int i=2;i*i<=n;i++)
		if(n%i==0) return false;
    return true;
}
void init()
{
	for(int i=1;i<=12;i++)
		for(int j=1;p[j]<=vis[i];j++)
			if(isprime(i*100+p[j])) a[++cnt]=i*100+p[j];
	for(int i=4;i<=9999;i+=4)
		if((i%100!=0||i%400==0)&&isprime(i*10000+229)) b[++len]=i*10000+229;
	for(int i=1;i<=9999;i++)
		for(int j=1;j<=cnt;j++)
			if(isprime(i*10000+a[j])) b[++len]=i*10000+a[j];
	return;
}
int main()
{
	init();
    scanf("%d",&T);
	while(T--)
    {
		scanf("%s",str);
		int ans=0;
		for(int i=1;i<=len;i++)
        {
			int x=b[i];
            bool flag=true;
			for(int j=7;j>=0;j--,x/=10)
				if(str[j]-'0'!=x%10&&str[j] != '-')
                {
                    flag=false;
                    break;
                }
            if(flag) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}