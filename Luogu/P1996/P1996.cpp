#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
queue<int>q;
int n,m,cnt=1;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
		q.push(i);
    while(!q.empty())
        if(cnt==m)
        {
            cnt=1;
            printf("%d ",q.front());
            q.pop();
        }
        else
        {
            cnt++;
            q.push(q.front());
            q.pop();
        }
    return 0;
}