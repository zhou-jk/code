#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,mod;
long long sum;
long long ans[21][21],a[21][21],b[21][21];
int to[21];
char ch[21];
void kmp()
{
    int c=0;
	for(int i=2;i<=m;i++)
	{
	    while(c&&ch[i]!=ch[c+1]) c=to[c];
	    if(ch[i]==ch[c+1]) c++;
	    to[i]=c;
	}
    return;
}
void mul()
{
	memset(b,0,sizeof(b));
	for(int j=0;j<m;j++)
	    for(int k=0;k<m;k++)
	        b[0][j]=(b[0][j]+ans[0][k]*a[k][j])%mod;
	memcpy(ans,b,sizeof(b));
}
void mulself()
{
	memset(b,0,sizeof(b));
	for(int i=0;i<m;i++)
	    for(int j=0;j<m;j++)
	        for(int k=0;k<m;k++)
	            b[i][j]=(b[i][j]+a[i][k]*a[k][j])%mod;
	memcpy(a,b,sizeof(b));
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&mod);
	scanf("%s",ch+1);
	kmp();
	for(int i=0;i<m;i++)
	    for(int j=0;j<=9;j++)
	    {
	  	    int t=i;
	  	    while(t && ch[t+1]-'0'!=j) t=to[t];
	  	    if(ch[t+1]-'0'==j) t++;
	  	    a[i][t]++;
	    }
	ans[0][0]=1;
	while(n)
	{
	    if(n&1) mul();
	    n>>=1;
	    mulself();
	}
	for(int i=0;i<m;i++)
        sum=(sum+ans[0][i])%mod;
	printf("%lld",sum);
	return 0;
}