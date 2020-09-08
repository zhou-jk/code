#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int K=105,N=1005;
int k,n;
int a[K];
vector<int>merge(const vector<int>&a,const vector<int>&b)
{
	vector<int>res;
	size_t i=0,j=0;
	while(i<a.size()&&j<b.size())
	{
		if(a[i]<b[j]) res.push_back(a[i]),i++;
		else res.push_back(b[j]),j++;
	}
	while(i<a.size())
		res.push_back(a[i]),i++;
	while(j<b.size())
		res.push_back(b[j]),j++;
	return res;
}
int ans[N],tot;
int b[K];
bool pos[K];
vector<int>add(int len)
{
	for(int i=1;i<=k;i++)
		pos[i]=false,b[i]=a[i];
	vector<int>pre;
	for(int i=tot,j=1;i>=1&&j<=k-len;i--,j++)
		pre.push_back(ans[i]);
	for(int u:pre)         
		pos[u]=true;        
	for(int i=1;i<=k;i++)
		if(!pos[i]) b[i]--;
	for(int i=1;i<=k;i++)
		if(b[i]<0) return {k+1};
	int Min=*min_element(b+1,b+k+1),Max=*max_element(b+1,b+k+1);
	if(Min*2>=Max)
	{
		vector<int>res;
		for(int i=1;i<=k;i++)
			if(!pos[i]) res.push_back(i);
		return res;
	}
	else if(Min*2+1==Max)
	{
		vector<int>x,y;
		for(int i=1;i<=k;i++)
			if(!pos[i]&&b[i]==Max) x.push_back(i);
		for(int i=1;i<=k;i++)
			if(!pos[i]&&b[i]==Min) x.push_back(i);
		for(int i=1;i<=k;i++)
			if(!pos[i]&&b[i]!=Min&&b[i]!=Max) y.push_back(i);
		vector<int>res=merge(x,y);
		pre.insert(pre.end(),res.begin(),res.end());
		int L=0,R=(int)(pre.size())-1;
		for(int i=0;i<pre.size();i++)
		{                  
			if(b[pre[i]]==Max) L=max(L,i);
			if(b[pre[i]]==Min) R=min(R,i);
		}
		if(L<R) return res;
		else return {k+1};
	}
	else return {k+1};
}
void solve()
{
	vector<int>res={k+1};
	for(int len=1;len<=k&&tot+len<=n;len++)
	{
		int d=k-len;
		if(tot-d>=0)
		{
			vector<int>now=add(len);
			res=min(res,now);
		}
	}
	for(int u:res)
	{
		ans[++tot]=u;
		a[u]--;
		printf("%d ",u);
	}
	return;
}
int main()
{
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]),n+=a[i];
	int Min=*min_element(a+1,a+k+1),Max=*max_element(a+1,a+k+1);
	if(2*Min+1<=Max)
	{
		printf("-1");
		return 0;
	}
	while(tot<n)
		solve();
	return 0;
}
