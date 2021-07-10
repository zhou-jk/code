#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<tuple>
using namespace std;
int L;
int n,m;
vector<tuple<int,int,int>>edge;
int main()
{
	scanf("%d",&L);
	int n=log2(L)+1;
	for(int i=1;i<n;i++)
		edge.emplace_back(i,i+1,1<<(i-1)),edge.emplace_back(i,i+1,0);
	for(int i=1;i<n;i++)
		if(L&(1<<(i-1))) edge.emplace_back(i,n,(L>>i)<<i);
	int m=edge.size();
	printf("%d %d\n",n,m);
	for(auto [u,v,w]:edge)
		printf("%d %d %d\n",u,v,w);
	return 0;
}