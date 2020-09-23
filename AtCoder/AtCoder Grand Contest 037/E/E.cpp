#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5005;
int n,k;
string s;
int main()
{
	cin>>n>>k;
	cin>>s;
	char c='z'+1;
	int L=0,R=0;
	string tmp;
	for(int i=0;i<=n;i++)
		tmp+='z';
	for(int i=0,j=0;i<n;i=j)
	{
		j=i;
		while(j<n&&s[i]==s[j]) j++;
		if(s[i]<c) c=s[i],L=i,R=j-1,tmp=s.substr(j);
		else if(s[i]==c&&j-i>R-L+1) L=i,R=j-1,tmp=s.substr(j);
		else if(s[i]==c&&j-i==R-L+1&&s.substr(j)<tmp) L=i,R=j-1,tmp=s.substr(j);
	}
	if(k==1)
	{
		if(s[n-1]!=c)
		{
			string t=s;
			reverse(t.begin(),t.end());
			s+=t;
			s=s.substr(L,n);
			cout<<s; 
		}
		else
		{
			int cnt=0,now=n-1;
			while(now>=0&&s[now]==c) now--,cnt++;
			string t=s;
			reverse(t.begin(),t.end());
			string st=s+t;
			st=st.substr(now+1,n);
			t=s;
			reverse(t.begin(),t.end());
			s+=t;
			s=s.substr(L,n);
			cout<<min(st,s);
		}
		return 0;
	}
	if(R!=n-1)
	{
		int cnt=0,now=n-1;
		while(now>=0&&s[now]==c) now--,cnt++;
		string t=s.substr(0,now+1);
		reverse(t.begin(),t.end());
		if(cnt*2<R-L+1||(cnt*2==R-L+1&&tmp<t))
		{
			string t=s;
			reverse(t.begin(),t.end());
			s+=t;
			int r=(n-1-L)+n,l=r-n+1;
			s=s.substr(l,n);
			k--;
		}
	}
	int pre=n-1;
	while(pre>=0&&s[pre]==c) pre--;
	pre++;
	for(int i=1;i<k;i++)
	{
		string t=s;
		reverse(t.begin(),t.end());
		s+=t;
		int r=(n-1-pre)+n,l=r-n+1;
		s=s.substr(l,n);
		pre=n-1;
		while(pre>=0&&s[pre]==c) pre--;
		pre++;
		if(pre==0) break;
	}
	string t=s;
	reverse(t.begin(),t.end());
	s+=t;
	int l=pre,r=l+n-1;
	s=s.substr(l,n);
	cout<<s;
	return 0;
}
