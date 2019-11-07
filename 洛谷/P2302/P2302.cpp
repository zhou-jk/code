#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct Node
{
    int id,val;
};
deque<Node>q;
int n,k;
int a[2000001];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        while(!q.empty()&&q.front().id+k<=i)
            q.pop_front();
        while(!q.empty()&&q.back().val<=a[i])
            q.pop_back();
        q.push_back((Node){i,a[i]});
        if(i>=k) printf("%d\n",q.front().val);
    }
    return 0;
}