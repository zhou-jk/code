#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
string s;
string solve(int l,int r)
{
    string t=s.substr(l,r-l+1);
    int m=t.size();
    if(t.front()=='a')
    {
        vector<int>a,b;
        vector<int>pos(m);
        for(int i=0;i<m;i++)
            if(t[i]=='a') a.emplace_back(i),pos[i]=a.size()-1;
            else b.emplace_back(i),pos[i]=b.size()-1;
        string res="ab";
        int now=b[0];
        for(int i=1;i<m/2;i++)
            if(a[i]>now) res+="ab",now=b[i];
        return res;
    }
    else
    {
        vector<int>a,b;
        vector<int>pos(m);
        for(int i=0;i<m;i++)
            if(t[i]=='a') a.emplace_back(i),pos[i]=a.size()-1;
            else b.emplace_back(i),pos[i]=b.size()-1;
        string res="";
        for(int i=0;i<=m/2;i++)
        {
            string str;
            for(int j=0;j<m;j++)
                if(pos[j]>=i) str+=t[j];
            res=max(res,str);
        }
        return res;
    }
}
int main()
{
    cin>>n;
    cin>>s;
    int cnt=0;
    string res;
    for(int j=2*n-1,i;j>=0;j=i)
    {
        if(s[j]=='a') cnt++;
        else cnt--;
        i=j-1;
        while(i>=0&&cnt!=0)
        {
            if(s[i]=='a') cnt++;
            else cnt--;
            i--;
        }
        string t=solve(i+1,j);
        res=max(res,t+res);
    }
    cout<<res;
    return 0;
}