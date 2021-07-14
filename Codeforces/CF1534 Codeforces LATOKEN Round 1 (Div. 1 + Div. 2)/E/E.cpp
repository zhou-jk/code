#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=505;
int n,k;
int c[N];
int query(const vector<int> &b)
{
    printf("? ");
    for(int u:b)
        printf("%d ",u);
    printf("\n");
    fflush(stdout);
    int v;
    scanf("%d",&v);
    return v;
}
int main()
{
    scanf("%d%d",&n,&k);
    if(k%2==0&&n%2==1)
    {
        printf("-1");
        return 0;
    }
    fill(c+1,c+n+1,1);
    int sum=n;
    while(sum%k!=0)
    {
        for(int i=1;i<=n;i++)
            if(sum%k!=0||c[1]>sum/k) c[i]+=2,sum+=2;
            else break;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>>q;
    for(int i=1;i<=n;i++)
        q.emplace(c[i],i);
    int ans=0;
    while(!q.empty())
    {
        vector<int>id(k);
        for(int i=0;i<k;i++)
            id[i]=q.top().second,q.pop();
        ans^=query(id);
        for(int i=0;i<k;i++)
        {
            c[id[i]]-=1;
            if(c[id[i]]>=1) q.emplace(c[id[i]],id[i]);
        }
    }
    printf("! %d",ans);
    return 0;
}