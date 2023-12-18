#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=55;
const int MOD=1000000007;
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(long long)res*a%MOD;
        a=(long long)a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int x)
{
    return qpow(x,MOD-2);
}
int fac[N],ifac[N];
void init(int n=50)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=(long long)fac[i-1]*i%MOD;
    ifac[n]=getinv(fac[n]);
    for(int i=n;i>=1;i--)
        ifac[i-1]=(long long)ifac[i]*i%MOD;
    return;
}
int a[N];
int s[N];
int n;
int f[10][N];
int calc(int p)
{
    int cnt[10]={};
    for(int i=1;i<=p;i++)
        cnt[s[i]]++;
    for(int i=1;i<=p&&s[i]==0;i++)
        cnt[s[i]]--;
    if(p==n)
    {
        int mx=*max_element(cnt,cnt+9+1);
        if(mx==0) return 0;
        for(int i=9;i>=0;i--)
            if(cnt[i]==mx) return i;
        return 0;
    }
    int res=0;
    for(int m=1;m<=9;m++)
    {
        for(int c=0;c<=n-p;c++)
        {
            int ret=n-p-c;
            bool flag=true;
            vector<int>v;
            for(int i=0;i<=9;i++)
                if(i!=m)
                {
                    int lim=c+cnt[m]-(i>m)-cnt[i];
                    v.emplace_back(i);
                    if(lim<0)
                    {
                        flag=false;
                        break;
                    }
                }
            if(!flag) continue;
            for(int i=0;i<=9;i++)
                for(int j=0;j<=ret;j++)
                    f[i][j]=0;
            f[0][0]=1;
            for(int i=1;i<=9;i++)
            {
                int lim=c+cnt[m]-(v[i-1]>m)-cnt[v[i-1]];
                for(int j=0;j<=ret;j++)
                    if(f[i-1][j])
                        for(int k=0;k<=lim&&j+k<=ret;k++)
                            f[i][j+k]=(f[i][j+k]+(long long)f[i-1][j]*ifac[k])%MOD;
            }
            res=(res+(long long)f[9][ret]*ifac[c]%MOD*fac[n-p]%MOD*m)%MOD;
        }
    }
    return res;
}
void solve()
{
    string str;
    cin>>str;
    n=str.size();
    for(int i=1;i<=n;i++)
        a[i]=str[i-1]-'0';
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i>=2)
        {
            for(int j=1;j<=9;j++)
            {
                s[i]=j;
                ans=(ans+calc(i))%MOD;
            }
        }
        s[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=(i==1?1:0);j<a[i];j++)
        {
            s[i]=j;
            ans=(ans+calc(i))%MOD;
        }
        s[i]=a[i];
    }
    ans=(ans+calc(n))%MOD;
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}