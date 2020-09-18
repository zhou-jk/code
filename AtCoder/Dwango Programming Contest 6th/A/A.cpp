#include<iostream>
#include<cstdio>
using namespace std;
const int N=55;
int n; 
string s[N];
string t;
int a[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i]>>a[i];
	cin>>t;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(s[i]==t)
		{
			for(int j=i+1;j<=n;j++)
				ans+=a[j];
			printf("%d",ans);
			return 0;
		}
	return 0;
}
