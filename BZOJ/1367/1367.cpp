#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define abs(x) ((x)>=0?(x):(-x))
const int N=1000001;
int n,m;
priority_queue<int,vector<int> >q;
int a[N],b[N];
int main()
{
    scanf("%d%d",&n,&a[1]);
    a[1]--;
    q.push(a[1]);
    b[1]=a[1];
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&b[i]);
        b[i]-=i;
        q.push(b[i]);
        if(q.top()>b[i])
        {
            ans+=q.top()-b[i];
            q.pop();
            q.push(b[i]);
        }
        a[i]=q.top();
    }
    for(int i=n-1;i>=1;i--)
        a[i]=min(a[i],a[i+1]);
    long long res=0;
    for(int i=1;i<=n;i++)
        res+=abs(a[i]-b[i]);
    printf("%lld\n",res);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]+i);
    return 0;
}