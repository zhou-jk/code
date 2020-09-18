#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=305;
int h,w,k;
char s[N][N];
int ans[N][N];
bool book[N];
int main()
{
	scanf("%d%d%d",&h,&w,&k);
	for(int i=1;i<=h;i++)
		scanf("%s",s[i]+1);
	book[0]=book[h+1]=true;
	int tot=0;
	for(int i=1;i<=h;i++)
	{
		vector<int>pos;
		for(int j=1;j<=w;j++)
			if(s[i][j]=='#') pos.push_back(j);
		if(pos.empty())
		{
			book[i]=true;
			continue;
		}
		for(int l=1;l<pos.size();l++)
		{
			tot++;
			for(int j=pos[l-1];j<pos[l];j++)
				ans[i][j]=tot;
		}
		ans[i][pos.back()]=++tot;
		for(int j=pos.front()-1;j>=1;j--)
			if(!ans[i][j]) ans[i][j]=ans[i][j+1];
		for(int j=pos.front()+1;j<=w;j++)
			if(!ans[i][j]) ans[i][j]=ans[i][j-1];
	}
	for(int i=1;i<=h;i++)
		if(book[i]&&!book[i-1])
		{
			for(int j=1;j<=w;j++)
				ans[i][j]=ans[i-1][j];
			book[i]=false;
		}
	for(int i=h;i>=1;i--)
		if(book[i]&&!book[i+1])
		{
			for(int j=1;j<=w;j++)
				ans[i][j]=ans[i+1][j];
			book[i]=false;
		}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
