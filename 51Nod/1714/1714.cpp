#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
    unsigned long long ans=0;
    bool flag=false;
    for(int i=1;i<=n;i++)
	{
		unsigned long long x;
		scanf("%llu",&x);
        int cnt=0;
        while(x)
		{
            if(x&1) cnt++;
            x>>=1;
        }
        ans^=7*(cnt-1);
    }
    if(ans) printf("B");
    else printf("L");
    return 0;
}
