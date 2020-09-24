#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2005;
int n;
int a[N][N];
bool fl[N][N],fr[N][N];
vector<int>pos[N];
int main()
{
	freopen("114.in","r",stdin);
	freopen("114.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i-1;j++)
			scanf("%1d",&a[i][j]),a[j][i]=a[i][j]^1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]) pos[i].push_back(j);
	for(int i=1;i<=n;i++)
		fl[i][i]=fr[i][i]=true;
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			int l=lower_bound(pos[i].begin(),pos[i].end(),i+1)-pos[i].begin(),r=upper_bound(pos[i].begin(),pos[i].end(),j)-pos[i].begin()-1;
			for(int p=l;p<=r;p++)
			{
				int k=pos[i][p];
				fl[i][j]|=fr[i+1][k]&fl[k][j];
				if(fl[i][j]) break;
			}
			l=lower_bound(pos[j].begin(),pos[j].end(),i)-pos[j].begin(),r=upper_bound(pos[j].begin(),pos[j].end(),j-1)-pos[j].begin()-1;
			for(int p=l;p<=r;p++)
			{
				int k=pos[j][p];
				fr[i][j]|=fr[i][k]&fl[k][j-1];
				if(fr[i][j]) break;
			}
		}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(fr[1][i]&&fl[i][n]) ans++;
	printf("%d",ans);
	return 0;
}
