#include<iostream>
#include<cstdio>
using namespace std;
int f[32005][31],Log[32005];
bool dp[32005][31];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=2;i<=32000;i++)
    {
        if(i>n)
		{
			Log[i]=0;
			continue;
		}
        else
        {
            f[i][1]=i;
            int j=2;
            while((long long)f[i][j-1]*i<=n)
                f[i][j]=f[i][j-1]*i,j++;
            Log[i]=j-1;
        }
    }
    dp[32001][1]=!((n-32001)&1);
    for(int i=32000;i>1;i--)
        for(int j=Log[i];j>0;j--)
            dp[i][j]=(!dp[i][j + 1])&&(!dp[i + 1][j]);
    while(m--)
    {
    	int a,b;
        scanf("%d%d",&a,&b);
        if(a>32000)
        {
        	if((n-a)&1) printf("Yes\n");
			else printf("No\n"); 
		}
		else
		{
			if(dp[a][b]) printf("No\n");
			else printf("Yes\n");
		}
    }
    return 0;
}
