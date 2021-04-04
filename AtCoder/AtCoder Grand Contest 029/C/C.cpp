#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n;
int a[N];
bool check(int x)
{
	vector<pair<int,int>>S;
	for(int i=1;i<=n;i++)
		if(a[i]<=a[i-1])
		{
			while(!S.empty()&&S.back().second>a[i]) S.pop_back();
			if(S.empty()) S.emplace_back(2,a[i]);
			else if(S.back().second==a[i]) S.back().first++;
			else S.emplace_back(2,a[i]);
			while(!S.empty()&&S.back().first>x)
			{
				int c=S.back().second;
				if(c==1) return false;
				S.pop_back();
				if(S.empty()) S.emplace_back(2,c-1);
				else if(S.back().second==c-1) S.back().first++;
				else S.emplace_back(2,c-1);
			}
		}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bool flag=true;
	for(int i=1;i<=n;i++)
		if(a[i]<=a[i-1])
		{
			flag=false;
			break;
		}
	if(flag)
	{
		printf("1");
		return 0;
	}
	int l=2,r=n,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}