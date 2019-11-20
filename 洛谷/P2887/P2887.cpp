#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=2501;
int n,m;
struct Node
{
    int l,r,id;
    bool operator>(const Node &b)const
    {
        return r>b.r;
    }
}a[N];
bool book[N];
priority_queue<Node,vector<Node>,greater<Node> >q;
struct SPF
{
    int val,num;
}b[N];
bool cmp(SPF x,SPF y)
{
    return x.val<y.val;
}
int ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].id=i;
    }
    for(int i=1;i<=m;i++)
        scanf("%d%d",&b[i].val,&b[i].num);
    sort(b+1,b+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        while(!q.empty()) q.pop();
        for(int j=1;j<=n;j++)
            if(b[i].val>=a[j].l&&!book[a[j].id]) q.push(a[j]);
        while(!q.empty())
        {
            Node u=q.top();
            q.pop();
            if(b[i].val<=u.r)
            {
                b[i].num--;
                ans++;
                book[u.id]=true;
            }
            if(b[i].num==0) break;
        }
    }
    printf("%d",ans);
    return 0;
}