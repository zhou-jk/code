#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200001;
const int INF=1061109567;
pair<int,int>a[N];
int n;
vector<int>p[N];
int main()
{
    scanf("%d",&n);
	for(int i=1;i<=n;i++)
    {
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	int tot=0;
	for(int i=1;i<=n;i++)
    {
		p[++tot].push_back(a[i].second);
		while(a[i].first==a[i+1].first) p[tot].push_back(a[++i].second);
	}
	bool flag=false;
	int now=INF,ans=1;
	for(int i=1;i<=tot;i++)
		if(flag)
        {
			if(now<p[i][0]) now=p[i][p[i].size()-1];
			else ans++,flag=false,now=p[i][0];
		}
		else
        {
			if(now>p[i][p[i].size()-1]) now=p[i][0];
			else flag=true,now=p[i][p[i].size()-1];
		}
    printf("%d",ans);
	return 0;
}
