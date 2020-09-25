#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int N=400005;
int n;
long long k;
int a[N];
int pos[N],nxt[N];
int f[N][60];
int vis[N];
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i+n]=a[i];
	for(int i=n*2;i>=1;i--)
		nxt[i]=pos[a[i]],pos[a[i]]=i;
	f[0][0]=1;
	for(int i=n;i>=1;i--)
		if(nxt[i]>n)
		{
			if(nxt[i]==n+n) f[i][0]=0;
			else f[i][0]=nxt[i]-n+1;
		}
		else
		{
			if(nxt[i]==n) f[i][0]=1;
			else f[i][0]=f[nxt[i]+1][0];
		}
	for(int i=1;i<=log2(k);i++)
		for(int u=0;u<=n;u++)
			f[u][i]=f[f[u][i-1]][i-1];
	int p=0;
	for(int i=0;i<=log2(k);i++)
		if(k&(1LL<<i)) p=f[p][i];
	if(p==0) return 0;
	stack<int>s;
	for(int i=p;i<=n;i++)
	{
		if(vis[a[i]])
		{
			while(!s.empty()&&s.top()!=a[i]) vis[s.top()]--,s.pop();
			if(!s.empty()) vis[s.top()]--,s.pop();
		}
		else s.push(a[i]),vis[a[i]]++;
	}
	vector<int>res;
	while(!s.empty()) res.push_back(s.top()),s.pop();
	reverse(res.begin(),res.end());
	for(int u:res)
		printf("%d ",u);
	return 0;
}
