#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int l,n,m,k,t,test,sum[4000001];
char s[1001];
bool flag;
long long ans;
vector<int>tri[4000001];
vector<char>cha[4000001];
void build(char *s)
{
	k=1;
	l=strlen(s);
	for (int i=0;i<=l;i++)
	{
		flag=false;
		sum[k]++;
		for (int j=0;j<cha[k].size();j++)
			if (cha[k][j]==s[i])
			{
				k=tri[k][j];
				flag=true;
				break;
			}
		if (flag)continue;
		cha[k].push_back(s[i]);
		tri[k].push_back(++m);
		k=m;
	}
	sum[k]++;
}
void find(char *s)
{
	k=1;
	l=strlen(s);
	for (int i=0;i<=l;i++)
	{
		for (int j=0;j<cha[k].size();j++)
			if (cha[k][j]==s[i])
			{
				t=tri[k][j];
				break;
			}
		ans+=(sum[k]-sum[t])*(2*i+1);
		k=t;
	}
	ans+=(sum[k]-1)*2*(l+1);
}
int main()
{
	while (scanf("%d",&n)!=EOF&&n>0)
	{
		m=1;
		memset(sum,0,sizeof(sum));
		ans=0;
		for (int i=0;i<4000001;i++) {
			tri[i].clear();
			cha[i].clear();
		} 
		for (int i=1;i<=n;i++)
		{
			scanf("%s",s);
            build(s); find(s);
		}
		printf("Case %d: %lld\n",++test,ans);
	}
	return 0;
}
