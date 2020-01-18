#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string s;
int n;
int num[100001],p[100001];
int ans;
int main()
{
	cin>>s;
	n=1;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') num[n]=(num[n]*10+s[i]-'0')%10000; 
		else p[n++]=i;
	n++;
	for(int i=1;i<=n;i++)
		if(s[p[i]]=='*') num[i+1]=num[i]*num[i+1]%10000,num[i]=0;
	for(int i=1;i<=n;i++)
        ans=(ans+num[i])%10000;
	printf("%d",ans);
	return 0;
}