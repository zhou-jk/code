#include<iostream>
#include<cstdio>
#include<tuple>
#include<vector>
using namespace std;
const int N=100005;
int n;
int a[N];
vector<tuple<int,int,int>>res;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int x=0;
	for(int i=1;i<=n;i++)
		x^=a[i];
	if(n%2==0)
	{
		if(x!=0)
		{
			printf("NO");
			return 0;
		}
		else n--;
	}
	for(int i=1;i+2<=n;i+=2)
		res.emplace_back(i,i+1,i+2);
	for(int i=1;i+1<n-1;i+=2)
		res.emplace_back(i,i+1,n);
	printf("YES\n");
	int k=res.size();
	printf("%d\n",k);
	for(auto [i,j,k]:res)
		printf("%d %d %d\n",i,j,k);
	return 0;
}
