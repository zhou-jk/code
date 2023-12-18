#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N],tot;
bool isprime[N];
void init(int n)
{
    fill(isprime+1,isprime+n+1,true);
    isprime[1]=false;
    for(int i=2;i<=n;i++)
        if(isprime[i])
            for(int j=i+i;j<=n;j+=i)
                isprime[j]=false;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    init(n);
    if(n<=11)
    {
        iota(a+1,a+n+1,1);
        bool flag=false;
        do
        {
            flag=true;
            for(int i=1;i<=n;i++)
                if(!isprime[abs(a[i]-a[i%n+1])])
                {
                    flag=false;
                    break;
                }
            if(flag) break;
        }
        while (next_permutation(a+1,a+n+1));
        if(flag)
        {
            for(int i=1;i<=n;i++)
                cout<<a[i]<<" ";
        }
        else cout<<-1;
        return 0;
    }
    if(n%2==0)
    {
        for(int i=1;i<=n-3;i+=2)
        {
            a[++tot]=i;
            if(i==5) a[++tot]=2;
        }
        for(int i=n;i>=3;i-=2)
        {
            a[++tot]=i;
            if(i==n-4) a[++tot]=n-1;
        }
    }
    else
    {
        for(int i=1;i<=n;i+=2)
        {
            a[++tot]=i;
            if(i==5) a[++tot]=2;
            if(i==n-6) a[++tot]=n-1;
        }
        for(int i=n-3;i>=4;i-=2)
            a[++tot]=i;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}