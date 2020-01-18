#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
deque<int>q;
int n,cnt;
char ch1,ch2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>ch1>>ch2;
        int k;
        if(ch1=='A'&&ch2=='L') q.push_front(++cnt);
        else if(ch1=='A'&&ch2=='R') q.push_back(++cnt);
        else if(ch1=='D'&&ch2=='L')
        {
            scanf("%d",&k);
            for(int j=1;j<=k;j++)
                q.pop_front();
        }
        else if(ch1=='D'&&ch2=='R')
        {
            scanf("%d",&k);
            for(int j=1;j<=k;j++)
                q.pop_back();
        }
    }
    for(auto it:q)
        printf("%d\n",it);
    return 0;
}