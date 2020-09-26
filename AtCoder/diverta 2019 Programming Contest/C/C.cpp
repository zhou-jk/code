#include<iostream>
#include<cstdio>
using namespace std;
const int N=10005;
int n;
string s[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	int ans=0;
	int A=0,B=0,BA=0;
	for(int i=1;i<=n;i++)
	{
		for(size_t j=1;j<s[i].size();j++)
			if(s[i][j-1]=='A'&&s[i][j]=='B') ans++;
		if(s[i].front()=='B'&&s[i].back()=='A') BA++;
		else if(s[i].front()=='B') B++;
		else if(s[i].back()=='A') A++;
	}
	if(BA>0)
	{
		if(A>0&&B>0) A--,B--,BA--,ans+=2;
		else if(A>0) A--,BA--,ans++;
		else if(B>0) B--,BA--,ans++;
		else BA--;
	}
	ans+=min(A,B)+BA;
	printf("%d",ans);
	return 0;
}
