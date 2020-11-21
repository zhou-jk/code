#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=55;
int n,m;
string s[N];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int j=0;j<m;j++)
	{
		vector<string>pos;
		for(int i=0;i<n;i++)
			if(s[i][j]=='#') pos.emplace_back(s[i]);
		for(size_t i=1;i<pos.size();i++)
			if(pos[i]!=pos[i-1])
			{
				printf("No");
				return 0;
			}
	}
	printf("Yes");
	return 0;
}
