#include<iostream>
#include<iomanip>
#include<cstdio>
#include<vector>
using namespace std;
struct BigInteger
{
    static const long long base_=(long long)1e18;
    static const int width_=18;
    vector<long long> val_;
    BigInteger(int num=0)
    {
        do
        {
            val_.push_back(num%base_);
            num/=base_;
        }
        while(num);
    }
    BigInteger(long long num)
    {
        do
        {
            val_.push_back(num % base_);
            num/=base_;
        }
        while(num);
    }
    BigInteger(const string &str)
    {
        int be=0,en=str.size();
        while((en-=width_)>=be)
            val_.push_back(stoll(str.substr(en, width_)));
        if((en+=width_)>be)
            val_.push_back(stoll(str.substr(be,en-be)));
    }
    BigInteger &operator=(int num)
    {
        return *this=BigInteger(num);
    }
    BigInteger &operator=(long long num)
    {
        return *this=BigInteger(num);
    }
    BigInteger &operator=(const string &str)
    {
        return *this=BigInteger(str);
    }
    bool operator<(const BigInteger &obj)const
    {
        if(val_.size()!=obj.val_.size()) return val_.size()<obj.val_.size();
        for(int i=val_.size()-1;i>=0;i--)
            if(val_[i]!=obj.val_[i]) return val_[i]<obj.val_[i];
        return false;
    }
    BigInteger operator+(const BigInteger &obj)const
    {
        BigInteger result;
        int os=max(val_.size(),obj.val_.size());
        result.val_.resize(os);
        for(int i=0;i<os;i++)
        {
            long long tmp=result.val_[i];
            if(i<(int)val_.size()) tmp+=val_[i];
            if(i<(int)obj.val_.size()) tmp+=obj.val_[i];
            if(tmp>=base_)
            {
                tmp-=base_;
                if(i+1>=(int)result.val_.size()) result.val_.push_back(0); 
                result.val_[i+1]++;
            }
            result.val_[i]=tmp;
        }
        return result;
    }
    friend ostream &operator<<(ostream &,const BigInteger &);
};
ostream &operator<<(ostream &out,const BigInteger &obj)
{
    out<<obj.val_.back();
    for(int i=obj.val_.size()-2;i>=0;i--)
        out<<setw(BigInteger::width_)<<setfill('0')<<obj.val_[i];
    return out;
}
const int N=200005; 
int n,k;
string s;
bool vis[N];
BigInteger dp[N];
void solve()
{
    cin>>n>>k;
    cin>>s;
    for(int i=1;i<=n;i++)
        vis[i]=false;
    int len=n/(k+1)+2;
    for(int t=0;t<=k;t++)
        for(int i=n;i>=max(1,n-len*(k-t));i--)
            for(int j=max(0,i-len);j<=t*len&&j<i;j++)
                if(j==0||vis[j])
                {
                    BigInteger v=dp[j]+s.substr(j,i-j);
                    if(!vis[i]||v<dp[i]) dp[i]=v,vis[i]=true;
                }
    cout<<dp[n]<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}