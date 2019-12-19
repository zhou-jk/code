#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=150005;
int T;
char s[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		vector<int>res;
		for(int i=1;i<=n;i++)
			if(s[i]=='o')
			{
				int j;
				for(j=i;j<=n&&s[j]=='o';j++);
				if((i>2&&s[i-2]=='t'&&s[i-1]=='w')&&(j<n&&s[j]=='n'&&s[j+1]=='e'))
				{
					if(i+2<=j) res.push_back(i-1),res.push_back(j);
					else for(register int k=i;k<j;k++) res.push_back(k);
				}
				else if(i>2&&s[i-2]=='t'&&s[i-1]=='w')
				{
					if(i+1<=j) res.push_back(i-1);
					else
					{
						for(int k=i;k<j;k++)
							res.push_back(k);
					}
				}
				else if(j<n&&s[j]=='n'&&s[j+1]=='e')
				{
					if(i+1<=j)res.push_back(j);
					else
					{
						for(int k=i;k<j;k++)
							res.push_back(k);
					}
				}
				i=j;
			}
		printf("%u\n",res.size());
		for(auto u:res)
			printf("%d ",u);
		printf("\n");
	}
	return 0;
}