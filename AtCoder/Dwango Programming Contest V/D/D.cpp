#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100005,M=2005;
int n,D;
int x[N],y[N];
int cnt[M][M];
int s2[M][M],s3[M][M];
int getsum2(int x1,int y1,int x2,int y2)
{
	if(x1>x2) return 0;
	if(y1>y2) return 0;
	int res=s2[x2][y2];
	if(x1-1>=0) res-=s2[x1-1][y2];
	if(y1-1>=0) res-=s2[x2][y1-1];
	if(x1-1>=0&&y1-1>=0) res+=s2[x1-1][y1-1];
	return res;
}
int getsum3(int x1,int y1,int x2,int y2)
{
	if(x1>x2) return 0;
	if(y1>y2) return 0;
	int res=s3[x2][y2];
	if(x1-1>=0) res-=s3[x1-1][y2];
	if(y1-1>=0) res-=s3[x2][y1-1];
	if(x1-1>=0&&y1-1>=0) res+=s3[x1-1][y1-1];
	return res;
}
bool check2(int x,int y,int b)
{
	return getsum2(x+b+1,y+b+1,x+D-1,y+D-1)==0;
}
bool check3(int x,int y,int b)
{
	return getsum3(x,y,x+b,y+b)==getsum3(0,0,D-1,D-1);
}
int main()
{
	scanf("%d%d",&n,&D);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		cnt[x[i]%D][y[i]%D]++;
	int a=0;
	for(int i=0;i<D;i++)
		for(int j=0;j<D;j++)
			a=max(a,(int)ceil(sqrt(cnt[i][j])));
	a--;
	for(int i=0;i<D;i++)
		for(int j=0;j<D;j++)
		{
			if(cnt[i][j]>a*a&&cnt[i][j]<=a*(a+1)) s2[i][j]++;
			else if(cnt[i][j]>a*(a+1)) s3[i][j]++;
		}
	for(int i=0;i<D;i++)
		for(int j=0;j<D;j++)
			s2[i+D][j]=s2[i][j+D]=s2[i+D][j+D]=s2[i][j],s3[i+D][j]=s3[i][j+D]=s3[i+D][j+D]=s3[i][j];
	for(int i=0;i<D+D;i++)
		for(int j=0;j<D+D;j++)
		{
			if(i-1>=0) s2[i][j]+=s2[i-1][j];
			if(j-1>=0) s2[i][j]+=s2[i][j-1];
			if(i-1>=0&&j-1>=0) s2[i][j]-=s2[i-1][j-1];
			if(i-1>=0) s3[i][j]+=s3[i-1][j];
			if(j-1>=0) s3[i][j]+=s3[i][j-1];
			if(i-1>=0&&j-1>=0) s3[i][j]-=s3[i-1][j-1];
		}
	int res=D-1;
	for(int i=0;i<D;i++)
		for(int j=0;j<D;j++)
		{
			int l=0,r=D-1,ans=-1;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(check2(i,j,mid)&&check3(i,j,mid)) ans=mid,r=mid-1;
				else l=mid+1;
			}
			if(ans!=-1) res=min(res,ans);
		}
	printf("%d",a*D+res);
	return 0;
}
