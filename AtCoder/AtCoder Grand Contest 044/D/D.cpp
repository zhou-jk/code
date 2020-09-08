#include<iostream>
#include<cstdio>
using namespace std;
const int L=128,N=65;
const char ch[]={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
int len;
int cnt[N];
int query(const string &s)
{
	cout<<"? "<<s<<endl; 
	int ans;
	cin>>ans;
	return ans;
}
bool check(const string &s)
{
	return query(s)==len-s.size();
}
string merge(int l,int r)
{
	if(l==r) return string(cnt[l],ch[l]);
	int mid=(l+r)/2;
	string a=merge(l,mid),b=merge(mid+1,r);
	string t;
	int i=0,j=0;
	while(i<a.size()&&j<b.size())
	{
		if(check(t+a[i]+b.substr(j))) t+=a[i],i++;
		else t+=b[j],j++;
	}
	while(i<a.size())
		t+=a[i],i++;
	while(j<b.size())
		t+=b[j],j++;
	return t;
}
int main()
{
	for(int i=0;i<62;i++)
		cnt[i]=L-query(string(L,ch[i])),len+=cnt[i];
	string ans=merge(0,62);
	cout<<"! "<<ans<<endl;
	return 0;
}
