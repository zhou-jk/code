#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N],b[N];
pair<int,int> p[N];
int q[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),p[i]=make_pair(a[i],i);
	sort(p+1,p+n+1,greater<pair<int,int> >());
	set<pair<int,int> >S;
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),q[i]=i,S.insert(make_pair(b[i],i));
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int u=p[i].second;
		if(a[u]<=b[q[u]])
		{
			S.erase(S.lower_bound(make_pair(b[q[u]],u)));
			continue;
		}
		set<pair<int,int> >::iterator A=S.lower_bound(make_pair(b[q[u]],u)),B=S.lower_bound(make_pair(a[u],0));
		if(B==S.end())
		{
			printf("No");
			return 0;
		}
		int v=B->second;
		S.erase(A);
		S.erase(B);
		swap(q[u],q[v]);
		S.insert(make_pair(b[q[v]],v));
		ans++;
	}
	if(ans<=n-2) printf("Yes");
	else printf("No");
	return 0;
}
