#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct Basis
{
private:
    static const int N=63;
    long long a[N];
    vector<long long>b;
    int cnt;
public:
    Basis()
    {
        cnt=0;
        for(int i=0;i<N;i++)
            a[i]=0;
        b.clear();
        return;
    }
    void clear()
    {
        cnt=0;
        for(int i=0;i<N;i++)
            a[i]=0;
        b.clear();
        return;
    }
    void insert(const long long &x)
    {
        cnt++;
        long long t=x;
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
    int size()const
    {
        return b.size();
    }
    long long max_xor()const
    {
        long long res=0;
        for(int i=N-1;i>=0;i--)
            res^=a[i];
        return res;
    }
    long long kth_xor(const long long &x)const
    {
        long long k=x;
        if(size()!=cnt) k--;
        if(k>(1LL<<size())-1) return -1;
        long long res=0;
        for(int i=0;i<(int)b.size();i++)
            if((k>>i)&1) res^=a[b[i]];
        return res;
    }
    long long rank(const long long &x)const
    {
        long long res=0;
        for(int i=0;i<(int)b.size();i++)
            if((x>>b[i])&1) res+=1LL<<i;
        return res;
    }
};
const int N=100005;
const int MOD=10086;
int n,Q;
int a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&Q);
    Basis lb;
    for(int i=1;i<=n;i++)
        lb.insert(a[i]);
    int ans=lb.rank(Q)%MOD;
    for(int i=1;i<=n-lb.size();i++)
        ans=ans*2%MOD;
    ans=(ans+1)%MOD;
    printf("%d",ans);
    return 0;
}