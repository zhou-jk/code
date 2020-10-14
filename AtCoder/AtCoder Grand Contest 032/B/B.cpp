#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	vector<pair<int,int> >res;
	if(n&1)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i<j&&i+j!=n) res.push_back(make_pair(i,j));
	}
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i<j&&i+j!=n+1) res.push_back(make_pair(i,j));
	}
	int m=res.size();
	printf("%d\n",m);
	for(auto [x,y]:res)
		printf("%d %d\n",x,y);
	return 0;
}
