#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int n,h[1000001],val[1000001];
int ans[1000001],res;
stack<int>s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&h[i],&val[i]);
	for(int i=1;i<=n;i++)
	{
        while(!s.empty()&&h[s.top()]<=h[i])
		    s.pop();
	    if(!s.empty()) ans[s.top()]+=val[i];
	    s.push(i);
    }
	while(!s.empty())
		s.pop();
	for(int i=n;i>=1;i--)
	{
        while(!s.empty()&&h[s.top()]<=h[i])
		    s.pop();
	    if(!s.empty()) ans[s.top()]+=val[i];
	    s.push(i);
    }
	for(int i=1;i<=n;i++)
		res=max(res,ans[i]);
    printf("%d",res);
	return 0;
}