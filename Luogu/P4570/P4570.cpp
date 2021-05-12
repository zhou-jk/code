#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Basis
{
    static const int N=63;
    long long a[N];
    vector<int>b;
    Basis()
    {
        for(int i=0;i<N;i++)
            a[i]=0;
        b.clear();
        return;
    }
    void clear()
    {
        for(int i=0;i<N;i++)
            a[i]=0;
        b.clear();
        return;
    }
    void insert(long long t)
    {
        for(int i=N-1;i>=0;i--)
            if((t>>i)&1)
            {
                if(a[i]) t^=a[i];
                else
                {
                    for(int j=0;j<i;j++)
                        if((t>>j)&1) t^=a[j];
                    for(int j=i+1;j<N;j++)
                        if((a[j]>>i)&1) a[j]^=t;
                    a[i]=t;
                    break;
                }
            }
        b.clear();
        for(int i=0;i<N;i++)
            if(a[i]) b.push_back(i);
        return;
    }
    int size()
    {
        return b.size();
    }
};
const int N=1005;
int n;
struct Node
{
    long long number;
    int magic;
}a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%d",&a[i].number,&a[i].magic);
    sort(a+1,a+n+1,[=](const Node &x,const Node &y){return x.magic>y.magic;});
    Basis lb;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int s=lb.size();
        lb.insert(a[i].number);
        if(lb.size()!=s) ans+=a[i].magic;
    }
    printf("%d",ans);
    return 0;
}