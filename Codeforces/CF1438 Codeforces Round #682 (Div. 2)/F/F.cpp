#include<iostream>
#include<cstdio>
#include<cassert>
#include<ctime>
#include<random>
#include<algorithm>
using namespace std;
const int N=(1<<19)+5;
int T;
int h;
int n;
unsigned rand(unsigned l,unsigned r)
{
	static mt19937 myrand(time(NULL));
	return myrand()%(r-l+1)+l;
}
int ask(int u,int v,int w)
{
	assert(u!=v&&v!=w&&u!=w);
	assert(1<=u&&u<=n);
	assert(1<=v&&v<=n);
	assert(1<=w&&w<=n);
	printf("? %d %d %d\n",u,v,w);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
void submit(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
	return;
}
int cnt[N];
int id[N];
int main()
{
	scanf("%d",&h);
	n=(1<<h)-1;
	for(int i=1;i<=420;i++)
	{
		int u=rand(1,n),v=rand(1,n),w=rand(1,n);
		while(u==v||v==w||u==w) u=rand(1,n),v=rand(1,n),w=rand(1,n);
		cnt[ask(u,v,w)]++;
	}
	for(int i=1;i<=n;i++)
		id[i]=i;
	sort(id+1,id+n+1,[=](const int &x,const int &y){return cnt[x]>cnt[y];});
	int x=id[1],y=id[2];
	for(int i=1;i<=n;i++)
		if(i!=x&&i!=y)
		{
			int z=ask(x,y,i);
			if(z!=x&&z!=y) submit(i);
		}
	return 0;
}
