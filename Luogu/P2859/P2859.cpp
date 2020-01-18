#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=50001;
int n;
struct Node
{
    int id,l,r;
    bool operator>(const Node &b)const
    {
        if(r!=b.r) return r>b.r;
        else return l<b.r;
    }
}a[N];
priority_queue<Node,vector<Node>,greater<Node> >q;
bool cmp(Node x,Node y)
{
    if(x.l!=y.l) return x.l<y.l;
    else return x.r<y.r;
}
int ans=1;
int res[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    q.push(a[1]);
    res[a[1].id]=1;
    for(int i=2;i<=n;i++)
    {
        if(!q.empty()&&q.top().r<a[i].l)
        {
            res[a[i].id]=res[q.top().id];
            q.pop();
        }
        else res[a[i].id]=++ans;
        q.push(a[i]);
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        printf("%d\n",res[i]);
    return 0;
}