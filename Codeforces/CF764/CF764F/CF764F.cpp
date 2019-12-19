#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=200001;
multiset<int> s1,s2;
int n,w,k;
int a[N],t[N];
int main()
{
    scanf("%d%d%d",&n,&w,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	int time=0,num=0,sum=0,ans=0;
    int l=1,r=1;
	while(r<=n)
	{
		s1.insert(t[r]);
		time+=(t[r]+1)/2;
		if(s1.size()>w)
		{
			s2.insert(*(s1.begin()));
			time+=*(s1.begin())/2;
			s1.erase(s1.begin());
		}
		sum+=a[r++];
		while(l<=r&&time>k)
		{
			if(t[l]>=*(s1.begin()))
			{
				s1.erase(s1.find(t[l]));
				time-=(t[l]+1)/2;
				if(s2.size())
				{
					multiset<int>::iterator it=s2.end();
					it--;
					s1.insert(*it);
					time-=*it/2;
					s2.erase(it);
				}
			}
			else 
			{
				s2.erase(s2.find(t[l]));
				time-=t[l];
			}
			sum-=a[l++];
		}
		ans=max(ans,sum);
	}
	printf("%d",ans);
	return 0;
}