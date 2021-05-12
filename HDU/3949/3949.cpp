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
            if(a[i]) b.push_back(a[i]);
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
            if((k>>i)&1) res^=b[i];
        return res;
    }
};
const int N=10005;
int T;
int n,Q;
long long a[N];
int Case;
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    Basis lb;
    for(int i=1;i<=n;i++)
        lb.insert(a[i]);
    scanf("%d",&Q);
    printf("Case #%d:\n",++Case);
    while(Q--)
    {
        long long k;
        scanf("%lld",&k);
        printf("%lld\n",lb.kth_xor(k));
    }
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}