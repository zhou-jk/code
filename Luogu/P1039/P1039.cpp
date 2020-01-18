#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
const int N=21;
string S[10]=
{
    "Today is Sunday.",
    "Today is Monday.",
    "Today is Tuesday.",
    "Today is Wednesday.",
    "Today is Thursday.",
    "Today is Friday.",
    "Today is Saturday.",
};
int m,n,p;
int real,fake,ans;
int match[N];
struct Sen
{
    int id;
    string s;
}sen[105];
map<string,int> book;
bool judge(int id,bool flag)
{
    if(match[id]==-1)
    {
        match[id]=flag;
        if(flag) real++;
        else fake++;
    }
    else return match[id]!=flag;
    return fake>n||real>m-n;
}
void check(int id,string day)
{
    memset(match,-1,sizeof(match));
    real=fake=0;
    for(int i=1;i<=p;++i)
    {
        if(sen[i].s.find("I am guilty.")!=-1)
        {
            if(judge(sen[i].id,sen[i].id==id)) return;
        }
        if(sen[i].s.find("I am not guilty")!=-1)
        {
            if(judge(sen[i].id,sen[i].id!=id)) return;
        }
        int pos=sen[i].s.find(" is guilty.");
        if(pos!=-1)
        {
            string tmp=sen[i].s;
            tmp.erase(pos,11);
            if(judge(sen[i].id,book[tmp]==id)) return;
        }
        pos=sen[i].s.find(" is not guilty.");
        if(pos!=-1)
        {
            string tmp=sen[i].s;
            tmp.erase(pos,15);
            if(judge(sen[i].id,book[tmp]!=id))
                return;
        }
        if(sen[i].s.find("Today is ")!=-1)
        {
            if(judge(sen[i].id,sen[i].s==day)) return;
        }
    }
    if(ans&&ans!=id)
    {
        printf("Cannot Determine");
        exit(0);
    }
    ans=id;
    return;
}
string s[N];
int main()
{
    scanf("%d%d%d",&m,&n,&p);
    for(int i=1;i<=m;i++)
    {
        cin>>s[i];
        book[s[i]]=i;
    }
    for(int i=1;i<=p;i++)
    {
        string name;
        cin>>name;
        name.erase(name.size()-1,1);
        string a;
        getline(cin,a);
        a.erase(0,1);
        if(a[a.size()-1]=='\n'||a[a.size()-1]=='\r') a.erase(a.size()-1,1);
        sen[i].id=book[name];
        sen[i].s=a;
    }
    for(int i=1;i<=m;i++)
        for(int j=0;j<7;j++)
            check(i,S[j]);
    if(!ans) printf("Impossible");
    else cout<<s[ans];
    return 0;
}