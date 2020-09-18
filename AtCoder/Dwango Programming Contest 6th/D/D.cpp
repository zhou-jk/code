#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
const int N=100005;
int n;
int a[N];
int deg[N];
set<int>S;
set<pair<int,int> >e;
bool book[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),deg[a[i]]++;
	if(n==2) return printf("-1"),0;
	for(int i=1;i<=n;i++)
		S.insert(i),e.insert(make_pair(-deg[i],i));
	int pre=0;
	vector<int>ans;
	for(int i=1;i<=n-3;i++)
	{
		int u;
		if(-(e.begin()->first)==n-i) u=e.begin()->second;
		else if(*S.begin()!=pre) u=*S.begin();
		else if(S.size()>=2) u=*(++S.begin());
		else return printf("-1"),0;
		S.erase(u);
		e.erase(make_pair(-deg[u],u));
		book[u]=true;
		if(!book[a[u]])
		{
			e.erase(make_pair(-deg[a[u]],a[u]));
			deg[a[u]]--;
			e.insert(make_pair(-deg[a[u]],a[u]));
		}
		pre=a[u];
		ans.push_back(u);
	}
	vector<int>d;
	for(int u:S)
		d.push_back(u);
	bool flag=false;
	for(int i=0;i<d.size();i++)
		for(int j=i+1;j<d.size();j++)
			if(a[d[i]]==d[j]&&a[d[j]]==d[i]&&!flag)
			{
				flag=true;
				int k;
				for(k=0;k<d.size();k++)
					if(k!=i&&k!=j) break;
				if(pre!=d[i]&&a[d[i]]!=d[k]&&a[d[k]]!=d[j]) ans.push_back(d[i]);
				else if(pre!=d[j]&&a[d[j]]!=d[k]&&a[d[k]]!=d[i]) ans.push_back(d[j]);
				else return printf("-1"),0;
				ans.push_back(d[k]);
				if(pre!=d[i]&&a[d[i]]!=d[k]&&a[d[k]]!=d[j]) ans.push_back(d[j]);
				else if(pre!=d[j]&&a[d[j]]!=d[k]&&a[d[k]]!=d[i]) ans.push_back(d[i]);
				else return printf("-1"),0;
				break;
			}
	if(!flag)
	{
		for(int i=n-2;i<=n;i++)
		{
			int u;
			if(-(e.begin()->first)==n-i) u=e.begin()->second;
			else if(*S.begin()!=pre) u=*S.begin();
			else if(S.size()>=2) u=*(++S.begin());
			else return printf("-1"),0;
			S.erase(u);
			e.erase(make_pair(-deg[u],u));
			book[u]=true;
			if(!book[a[u]])
			{
				e.erase(make_pair(-deg[a[u]],a[u]));
				deg[a[u]]--;
				e.insert(make_pair(-deg[a[u]],a[u]));
			}
			pre=a[u];
			ans.push_back(u);
		}
	}
	for(int u:ans)
		printf("%d ",u);
	return 0;
}
