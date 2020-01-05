#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int> > q;
int n;
int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
	    scanf("%d",&x);
	    q.push(x);
	    if(x<q.top())
	    {
	        ans+=q.top()-x;
	        q.pop();
	        q.push(x);
	    }
	}
	printf("%d",ans);
	return 0;
}
