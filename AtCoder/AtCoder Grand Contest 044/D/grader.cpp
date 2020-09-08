#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
const int INF=1e9;
int dp[N][N];
char a[N];
const char b[N]="0Atcod3rIsGreat";
int EditDis()
{
    int len1=strlen(a+1),len2=strlen(b+1);
    for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2;j++)
            dp[i][j]=INF;
    for(int i=1;i<=len1;i++)
        dp[i][0]=i;
    for(int j=1;j<=len2;j++)
        dp[0][j]=j;
    for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2;j++)
            dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+(a[i]!=b[j])));
    return dp[len1][len2];
}
int Q;
int main()
{
	while(true)
	{
		string op;
		cin>>op;
		if(op=="?")
		{
			cin>>(a+1);
			cout<<EditDis()<<endl;
			Q++;
		}
		else if(op=="!")
		{
			if(Q>850)
			{
				printf("Your query is too many");
				return 0;
			}
			cin>>(a+1);
			if(strlen(a+1)!=strlen(b+1))
			{
				printf("Your answer is wrong");
				return 0;
			}
			for(int i=1;i<=strlen(b+1);i++)
				if(a[i]!=b[i])
				{
					printf("Your answer is wrong");
					return 0;
				}
		}
	}
	return 0;
}
