#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
char a[N],b[N],c[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	scanf("%s",c+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i]&&b[i]!=c[i]&&a[i]!=c[i]) ans+=2;
		else if(a[i]==b[i]&&b[i]==c[i]);
		else if(a[i]==b[i]||b[i]==c[i]||a[i]==c[i]) ans++;
	printf("%d",ans);
	return 0;
}
