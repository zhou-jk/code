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
const int N=105;
int n;
int a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    Basis lb;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        int s=lb.size();
        lb.insert(a[i]);
        if(lb.size()==s) ans+=a[i];
    }
    printf("%lld",ans);
    return 0;
}