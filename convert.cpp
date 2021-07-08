#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("data.yml","r",stdin);
	freopen("config.yaml","w",stdout);
	string s;
	getline(cin,s);
	cout<<s<<"\n";
	while(1)
	{
		cin>>s;
		cin>>s;
		if(s!="score:") break;
		int x;
		cin>>x;
		cout<<"  - score: "<<x<<"\n";
		cin>>s>>s;
		cin>>s;
		cout<<"    cases:\n";
		while(1)
		{
			cin>>s;
			string name;
			for(int i=0;i<(int)s.size();i++)
				if(s[i]!='['&&s[i]!=']'&&s[i]!=' '&&s[i]!=','&&s[i]!='\'') name+=s[i];
			cout<<"      - input: "<<name<<".in\n";
			cout<<"        output: "<<name<<".out\n";
			if(s[s.size()-1]==']') break;
		}
	}
}