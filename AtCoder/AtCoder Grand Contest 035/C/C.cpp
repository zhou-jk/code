#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n;
vector<pair<int,int> >res;
int main()
{
	scanf("%d",&n);
	int k=1;
	while(k<n) k<<=1;
	if(k==n)
	{
		printf("No");
		return 0;
	}
	res.push_back(make_pair(1,2));
	res.push_back(make_pair(2,3));
	res.push_back(make_pair(3,n+1));
	res.push_back(make_pair(n+1,n+2));
	res.push_back(make_pair(n+2,n+3));
	for(int i=2;2*i+1<=n;i++)
	{
		res.push_back(make_pair(2*i,2*i+1));
		res.push_back(make_pair(2*i+1,n+1));
		res.push_back(make_pair(n+1,n+2*i));
		res.push_back(make_pair(n+2*i,n+2*i+1));
	}
	if(n%2==0)
	{
		for(int x=2;x<=n-1;x++)
		{
			int y=n^1^x;
			if(y!=x&&y>=2&&y<=n-1)
			{
				int i,j;
				if(x&1) i=x;
				else i=x+n;
				if(y&1) j=y;
				else j=y+n;
				res.push_back(make_pair(n,i));
				res.push_back(make_pair(n+n,j));
				break;
			}
		}
	}
	printf("Yes\n");
	for(auto [x,y]:res)
		printf("%d %d\n",x,y);
	return 0;
}

