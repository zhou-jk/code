#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int N=200005;
const long long INF=1e18;
int n,k;
vector<int>val[N];
multiset<pair<long long,int> >q1,q2,q3;
multiset<pair<long long,int> >n1,n2,n3;
int cnt[N];
long long res[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int c,v;
		scanf("%d%d",&c,&v);
		val[c].push_back(v);
	}
	for(int c=1;c<=k;c++)
		sort(val[c].begin(),val[c].end(),greater<int>());
	for(int c=1;c<=k;c++)
		if(val[c].size()>=2)
		{
			q2.insert(make_pair(val[c][0]+val[c][1],c));
			if(val[c].size()>=3) q3.insert(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c));
		}
	for(int t=1;t<=n;t++)
	{
		if(res[t-1]!=-1)
		{
			long long ans1=-INF,ans2=-INF,ans3=-INF,ans4=-INF;
			if(!q1.empty()) ans1=q1.rbegin()->first;
			if(!n1.empty()&&!q2.empty()) ans2=-n1.begin()->first+q2.rbegin()->first;
			if(!n2.empty()&&!q3.empty()) ans3=-n2.begin()->first+q3.rbegin()->first;
			if(!n3.empty()&&q2.size()>=2) ans4=-n3.begin()->first+(q2.rbegin()->first)+((++q2.rbegin())->first);
			long long ans=max({ans1,ans2,ans3,ans4});
			if(ans!=-INF)
			{
				if(ans==ans1)
				{
					n1.insert(*q1.rbegin());
					int c=q1.rbegin()->second;
					if(cnt[c]==1)
					{
						n2.insert(make_pair(val[c][0]+val[c][1],c));
						if(val[c].size()>=3) n3.erase(n3.find(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c)));
					}
					cnt[c]++;
					if(cnt[c]==1)
					{
						n2.erase(n2.find(make_pair(val[c][0]+val[c][1],c)));
						if(val[c].size()>=3) n3.insert(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c));
					}
					q1.erase(--q1.end());
				}
				else if(ans==ans2)
				{
					int c=n1.begin()->second;
					if(cnt[c]==1)
					{
						n2.insert(make_pair(val[c][0]+val[c][1],c));
						if(val[c].size()>=3) n3.erase(n3.find(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c)));
					}
					cnt[c]--;
					if(cnt[c]==1)
					{
						n2.erase(n2.find(make_pair(val[c][0]+val[c][1],c)));
						if(val[c].size()>=3) n3.insert(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c));
					}
					q1.insert(*n1.begin());
					n1.erase(n1.begin());
					c=q2.rbegin()->second;
					if(val[c].size()>=3) q3.erase(q3.find(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c)));
					for(size_t i=2;i<val[c].size();i++)
						q1.insert(make_pair(val[c][i],c));
					n2.insert(*q2.rbegin());
					q2.erase(--q2.end());
				}
				else if(ans==ans3)
				{
					int c=n2.begin()->second;
					q2.insert(*n2.begin());
					if(val[c].size()>=3) q3.insert(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c));
					for(size_t i=2;i<val[c].size();i++)
						q1.erase(q1.find(make_pair(val[c][i],c)));
					n2.erase(n2.begin());
					c=q3.rbegin()->second;
					cnt[c]++;
					n1.insert(make_pair(val[c][2],c));
					n3.insert(*q3.rbegin());
					for(size_t i=3;i<val[c].size();i++)
						q1.insert(make_pair(val[c][i],c));
					q2.erase(q2.find(make_pair(val[c][0]+val[c][1],c)));
					q3.erase(--q3.end());
				}
				else if(ans==ans4)
				{
					int c=n3.begin()->second;
					cnt[c]--;
					n1.erase(n1.find(make_pair(val[c][2],c)));
					q3.insert(*n3.begin());
					q2.insert(make_pair(val[c][0]+val[c][1],c));
					for(size_t i=3;i<val[c].size();i++)
						if(q1.find(make_pair(val[c][i],c))!=q1.end()) q1.erase(q1.find(make_pair(val[c][i],c)));
					n3.erase(n3.begin());
					c=q2.rbegin()->second;
					if(val[c].size()>=3) q3.erase(q3.find(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c)));
					for(size_t i=2;i<val[c].size();i++)
						q1.insert(make_pair(val[c][i],c));
					n2.insert(*q2.rbegin());
					c=(++q2.rbegin())->second;
					if(val[c].size()>=3) q3.erase(q3.find(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c)));
					for(size_t i=2;i<val[c].size();i++)
						q1.insert(make_pair(val[c][i],c));
					n2.insert(*(++q2.rbegin()));
					q2.erase(--(--q2.end()));
					q2.erase(--q2.end());
				}
				res[t]=res[t-1]+ans;
			}
			else res[t]=-1;
		}
		else if(res[t-2]==-1) res[t]=-1;
		else
		{
			long long ans=res[t-2];
			if(!q2.empty())
			{
				ans+=q2.rbegin()->first;
				int c=q2.rbegin()->second;
				if(val[c].size()>=3) q3.erase(q3.find(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c)));
				for(size_t i=2;i<val[c].size();i++)
					q1.insert(make_pair(val[c][i],c));
				n2.insert(*q2.rbegin());
				q2.erase(--q2.end());
			}
			res[t]=ans;
		}
		printf("%lld\n",res[t]);
	}
	return 0;
}
