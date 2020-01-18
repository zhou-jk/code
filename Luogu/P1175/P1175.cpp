#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int N=101;
stack<char>ch;
char s[N];
int first[N],len;
char pre[N];
int ans[N],tot,cnt;
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res*=a;
		a*=a,b>>=1;
	}
	return res;
}
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	first['(']=first[')']=first['^']=2,first['*']=first['/']=1;
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='0'&&s[i]<='9') pre[++cnt]=s[i];
		if(s[i]=='(') ch.push('(');
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
		{
			while(!ch.empty()&&first[ch.top()]>=first[s[i]])
			{
				if(ch.top()=='(') break;
				pre[++cnt]=ch.top();
                ch.pop();
			}
            ch.push(s[i]);
		}
		if(s[i]==')')
		{
			while(ch.top()!='(')
			{
				pre[++cnt]=ch.top();
                ch.pop();
			}
            ch.pop();
		}		
	}
    while(!ch.empty())
        pre[++cnt]=ch.top(),ch.pop();
    for(int i=1;i<=cnt;i++)
        printf("%c ",pre[i]);
    printf("\n");
	for(int i=1;i<=cnt;i++) 
	{
		if(pre[i]>='0'&&pre[i]<='9') ans[++tot]=pre[i]-'0';
		else if(pre[i]<'0'||pre[i]>'9')
		{
			if(pre[i]=='+')	ans[tot-1]+=ans[tot];
			if(pre[i]=='-')	ans[tot-1]-=ans[tot];
			if(pre[i]=='*')	ans[tot-1]*=ans[tot];
			if(pre[i]=='/')	ans[tot-1]/=ans[tot];
			if(pre[i]=='^') ans[tot-1]=ksm(ans[tot-1],ans[tot-1]);
			tot--;
			for(int j=1;j<=tot;j++)
				printf("%d ",ans[j]);
			for(int j=i+1;j<=cnt;j++)
				printf("%c ",pre[j]);
			printf("\n");
		}
	}
	return 0;
}