#include<iostream>
#include<cstdio>
using namespace std;
int T,n;
int main()
{
    scanf("%d",&T);
	while(T--)
    {
        scanf("%d",&n);
        int sg=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sg^=x;
        }
        if(sg) printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}