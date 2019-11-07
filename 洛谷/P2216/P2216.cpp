#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int INF=1061109567;
struct Node
{
    int id,val;
};
int a,b,n;
int v[1001][1001],mx[1001][1001],mn[1001][1001],t1[1001],t2[1001];
int val[1001],pos[1001];
int ans=INF;
deque<Node>q;
int main()
{
    scanf("%d%d%d",&a,&b,&n);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			scanf("%d",&v[i][j]);
	for(int i=1;i<=a;i++)
	{
        while(!q.empty()) q.pop_back();
		for(int j=1;j<=b;j++)
		{
            while(!q.empty()&&q.front().id+n<=j)
                q.pop_front(); 
            while(!q.empty()&&q.back().val<=v[i][j])
                q.pop_back();
            q.push_back((Node){j,v[i][j]});
			if(j>=n) mx[i][j]=q.front().val;
		}
        while(!q.empty()) q.pop_back();
		for(int j=1;j<=b;j++)
		{
            while(!q.empty()&&q.front().id+n<=j)
                q.pop_front(); 
            while(!q.empty()&&q.back().val>=v[i][j])
                q.pop_back();
			q.push_back((Node){j,v[i][j]});
			if(j>=n) mn[i][j]=q.front().val;
		}
	}
	for(int i=n;i<=b;i++)
	{
		while(!q.empty()) q.pop_back();
		for(int j=1;j<=a;j++)
		{
            while(!q.empty()&&q.front().id+n<=j)
                q.pop_front();
            while(!q.empty()&&q.back().val>=mn[j][i])
                q.pop_back();
            q.push_back((Node){j,mn[j][i]});
			if(j>=n) t1[j]=q.front().val;
		}
		while(!q.empty()) q.pop_back();
		for(int j=1;j<=a;j++)
		{
            while(!q.empty()&&q.front().id+n<=j)
                q.pop_front();
            while(!q.empty()&&q.back().val<=mx[j][i])
                q.pop_back();
            q.push_back((Node){j,mx[j][i]});
			if(j>=n) t2[j]=q.front().val;
		}
		for(int i=n;i<=a;i++)
            ans=min(ans,t2[i]-t1[i]);
	}
	printf("%d",ans);
	return 0;
}