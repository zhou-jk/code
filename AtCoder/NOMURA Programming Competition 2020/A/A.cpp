#include<iostream>
#include<cstdio>
using namespace std;
int h1,m1,h2,m2,k;
int main()
{
	scanf("%d%d%d%d%d",&h1,&m1,&h2,&m2,&k);
	int ansh=h2-h1,ansm=m2-m1;
	if(ansm<0) ansm+=60,ansh--;
	if(ansh<0) ansh+=24;
	int t=ansh*60+ansm;
	t-=k;
	printf("%d",max(t,0));
	return 0;
}

