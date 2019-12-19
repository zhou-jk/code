#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int T,n;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        set<string> vs01,vs10;
        map<string,int> book;
        bool s0=false,s1=false;
        int s01=0,s10=0;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            book[s]=i;
            int len=s.size();
            if(s[0]=='0'&&s[len-1]=='0') s0=true;
            else if(s[0]=='1'&&s[len-1]=='1') s1=true;
            else if(s[0]=='0'&&s[len-1]=='1')
            {
                s01++;
                string tmp=s;
                reverse(tmp.begin(),tmp.end());
                if(vs10.find(tmp)!=vs10.end()) vs10.erase(tmp);
                else vs01.insert(s);
            }
            else
            {
                s10++;
                string tmp=s;
                reverse(tmp.begin(),tmp.end());
                if(vs01.find(tmp)!=vs01.end()) vs01.erase(tmp);
                else vs10.insert(s);
            }
        }
        if(s0&&s1&&s01==0&&s10==0)
        {
            printf("-1\n");
            continue;
        }
        if(vs01.size()<vs10.size()) swap(vs01,vs10);
        int ans=abs(s10-s01)/2;
        printf("%d\n",ans);
        set<string>::iterator it=vs01.begin();
        for(int i=1;i<=ans;i++)
        {
            printf("%d ",book[*it]);
            it++;
        }
        printf("\n");
    }
    return 0;
}