#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
class BigInteger
{
public:
    // constructor
    BigInteger(int = 0);
    BigInteger(long long);
    BigInteger(const string &);
    BigInteger(const char *str)
    {
        *this = string(str);
    }

    // assignment operators
    BigInteger &operator=(int num)
    {
        return *this = BigInteger(num);
    }
    BigInteger &operator=(long long num)
    {
        return *this = BigInteger(num);
    }
    BigInteger &operator=(const string &str)
    {
        return *this = BigInteger(str);
    }
    BigInteger &operator=(const char *str)
    {
        return *this = BigInteger(str);
    }

    // relational operators
    bool operator<(const BigInteger &obj) const
    {
        return cmp(obj) < 0;
    }
    bool operator>(const BigInteger &obj) const
    {
        return cmp(obj) > 0;
    }
    bool operator<=(const BigInteger &obj) const
    {
        return cmp(obj) <= 0;
    }
    bool operator>=(const BigInteger &obj) const
    {
        return cmp(obj) >= 0;
    }
    bool operator==(const BigInteger &obj) const
    {
        return cmp(obj) == 0;
    }
    bool operator!=(const BigInteger &obj) const
    {
        return cmp(obj) != 0;
    }

    // arithmetic operators
    BigInteger operator+() const
    {
        return *this;
    }
    BigInteger operator-() const
    {
        return BigInteger(-sign_, val_);
    }
    BigInteger operator+(const BigInteger &) const;
    BigInteger operator-(const BigInteger &) const;
    BigInteger operator*(const BigInteger &) const;
    BigInteger operator/(const BigInteger &) const;
    BigInteger operator%(const BigInteger &) const;

    // compound assignment operators
    BigInteger &operator+=(const BigInteger &obj)
    {
        return *this = *this + obj;
    }
    BigInteger &operator-=(const BigInteger &obj)
    {
        return *this = *this - obj;
    }
    BigInteger &operator*=(const BigInteger &obj)
    {
        return *this = *this * obj;
    }
    BigInteger &operator/=(const BigInteger &obj)
    {
        return *this = *this / obj;
    }
    BigInteger &operator%=(const BigInteger &obj)
    {
        return *this = *this % obj;
    }

    // increment and decrement operators
    BigInteger &operator++()
    {
        return *this += 1;
    }
    BigInteger &operator--()
    {
        return *this -= 1;
    }
    BigInteger operator++(int);
    BigInteger operator--(int);

    // input and output
    friend istream &operator>>(istream &, BigInteger &);
    friend ostream &operator<<(ostream &, const BigInteger &);

protected:
    enum div_type
    {
        division,
        remainder
    };
    enum cmp_type
    {
        with_sign,
        without_sign
    };
    static const int base_ = (int)1e9;
    static const int width_ = 9;
    BigInteger(int s, const vector<int> &v) : sign_(s), val_(v) {}
    int cmp(const BigInteger &, cmp_type = with_sign) const;
    BigInteger &delZero();
    BigInteger &add(const BigInteger &);
    BigInteger &sub(const BigInteger &);
    BigInteger &mul(const BigInteger &, const BigInteger &);
    BigInteger &div(BigInteger &, BigInteger, div_type = division);

private:
    int sign_;
    vector<int> val_;
};

BigInteger::BigInteger(int num) : sign_(0)
{
    if (num < 0)
        sign_ = -1, num = -num;
    else if (num > 0)
        sign_ = 1;
    do
    {
        val_.push_back(num % base_);
        num /= base_;
    } while (num);
}

BigInteger::BigInteger(long long num) : sign_(0)
{
    if (num < 0)
        sign_ = -1, num = -num;
    else if (num > 0)
        sign_ = 1;
    do
    {
        val_.push_back(num % base_);
        num /= base_;
    } while (num);
}

BigInteger::BigInteger(const string &str)
{
    sign_ = str[0] == '-' ? -1 : 1;
    int be = str[0] == '-' ? 1 : 0, en = str.size();
    while ((en -= width_) >= be)
    {
        val_.push_back(stoi(str.substr(en, width_)));
    }
    if ((en += width_) > be)
    {
        val_.push_back(stoi(str.substr(be, en - be)));
    }
    delZero();
}

BigInteger BigInteger::operator+(const BigInteger &obj) const
{
    if (sign_ * obj.sign_ == 1)
    {
        BigInteger temp;
        return cmp(obj, without_sign) >= 0 ? (temp = *this).add(obj) : (temp = obj).add(*this);
    }
    else if (sign_ * obj.sign_ == -1)
        return *this - -obj;
    else
        return sign_ == 0 ? obj : *this;
}

BigInteger BigInteger::operator-(const BigInteger &obj) const
{
    if (sign_ * obj.sign_ == 1)
    {
        BigInteger temp;
        return cmp(obj, without_sign) >= 0 ? (temp = *this).sub(obj) : (temp = -obj).sub(*this);
    }
    else if (sign_ * obj.sign_ == -1)
        return *this + -obj;
    else
        return sign_ == 0 ? -obj : *this;
}

inline BigInteger BigInteger::operator*(const BigInteger &obj) const
{
    BigInteger temp;
    return (temp.sign_ = sign_ * obj.sign_) == 0 ? temp : temp.mul(*this, obj);
}

inline BigInteger BigInteger::operator/(const BigInteger &obj) const
{
    BigInteger temp, mod = *this;
    return cmp(obj, without_sign) < 0 || (temp.sign_ = sign_ * obj.sign_) == 0 ? temp : temp.div(mod, obj);
}

inline BigInteger BigInteger::operator%(const BigInteger &obj) const
{
    BigInteger temp, mod = *this;
    return cmp(obj, without_sign) < 0 || (temp.sign_ = sign_) == 0 ? mod : temp.div(mod, obj, remainder);
}

inline BigInteger BigInteger::operator++(int)
{
    BigInteger temp = *this;
    ++*this;
    return temp;
}

inline BigInteger BigInteger::operator--(int)
{
    BigInteger temp = *this;
    --*this;
    return temp;
}

inline istream &operator>>(istream &in, BigInteger &obj)
{
    string str;
    if (in >> str)
        obj = str;
    return in;
}

ostream &operator<<(ostream &out, const BigInteger &obj)
{
    if (obj.sign_ == -1)
        out << '-';
    out << obj.val_.back();
    for (int i = obj.val_.size() - 2; i >= 0; i--)
        out << setw(BigInteger::width_) << setfill('0') << obj.val_[i];
    return out;
}

int BigInteger::cmp(const BigInteger &obj, cmp_type typ) const
{
    if (typ == with_sign && sign_ != obj.sign_)
        return sign_ - obj.sign_;
    int sign = typ == with_sign ? sign_ : 1;
    if (val_.size() != obj.val_.size())
        return sign * (val_.size() - obj.val_.size());
    for (int i = val_.size() - 1; i >= 0; i--)
        if (val_[i] != obj.val_[i])
            return sign * (val_[i] - obj.val_[i]);
    return 0;
}

inline BigInteger &BigInteger::delZero()
{
    while ((int)val_.size() > 1 && val_.back() == 0)
        val_.pop_back();
    if (val_.empty() || val_.back() == 0)
        sign_ = 0;
    return *this;
}

BigInteger &BigInteger::add(const BigInteger &obj)
{
    int os = obj.val_.size();
    val_.push_back(0);
    for (int i = 0; i < os; i++)
    {
        long long tmp = (long long)val_[i] + obj.val_[i];
        if (tmp >= base_)
            tmp -= base_, ++val_[i + 1];
        val_[i] = tmp;
    }
    return delZero();
}

BigInteger &BigInteger::sub(const BigInteger &obj)
{
    int pos = obj.val_.size();
    for (int i = 0; i < pos; i++)
    {
        long long tmp = (long long)val_[i] - obj.val_[i];
        if (tmp < 0)
            tmp += base_, --val_[i + 1];
        val_[i] = tmp;
    }
    while (val_[pos] < 0)
        val_[pos] += base_, --val_[++pos];
    return delZero();
}

BigInteger &BigInteger::mul(const BigInteger &a, const BigInteger &b)
{
    int as = a.val_.size(), bs = b.val_.size();
    val_.resize(as + bs);
    for (int i = 0; i < as; i++)
        for (int j = 0; j < bs; j++)
        {
            int x = i + j;
            long long tmp = val_[x] + (long long)a.val_[i] * b.val_[j];
            val_[x + 1] += tmp / base_;
            tmp %= base_;
            val_[x] = tmp;
        }
    return delZero();
}

BigInteger &BigInteger::div(BigInteger &a, BigInteger b, div_type typ)
{
    int move = a.val_.size() - b.val_.size();
    val_.resize(move + 1);
    b.val_.insert(b.val_.begin(), move, 0);
    for (int i = move; i >= 0; i--)
    {
        int left = 0, right = base_;
        while (left + 1 < right)
        {
            int mid = (left + right) >> 1;
            if (a.cmp(b * BigInteger(mid), without_sign) >= 0)
                left = mid;
            else
                right = mid;
        }
        val_[i] = left;
        a.sub(b * BigInteger(left));
        b.val_.erase(b.val_.begin());
    }
    return typ == division ? delZero() : a;
}
BigInteger gcd(BigInteger a,BigInteger b)
{
    return b==0?a:gcd(b,a%b);
}
#include<cassert>
const int C[3]={38247,62231,67876};
const long long INF=7000000000000; 
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    long long d=exgcd(b,a%b,x,y);
    long long tmp=x;
    x=y,y=tmp-a/b*y;
    return d;
}
long long CRT(const vector<int> &a,const vector<int> &r)
{
    assert(a.size()==r.size());
    int k=a.size();
    long long n=1,ans=0;
    for(int i=0;i<k;i++)
        n*=r[i];
    for(int i=0;i<k;i++)
    {
        long long m=n/r[i],b,y;
        exgcd(m,r[i],b,y);
        ans=(ans+(__int128)a[i]*m%n*b%n)%n;
    }
    return (ans%n+n)%n;
}
BigInteger query(long long k)
{
    cout<<"? "<<k<<endl;
    BigInteger res;
    cin>>res;
    return res;
}
bool check(long long u,int op,long long k)
{
    for(int i=0;i<3;i++)
        if(i==op)
        {
            if(k%C[i]!=u%C[i]) return false;
        }
        else if(k%C[i]==u%C[i]) return false;
    return true;
}
long long findk(long long u,long long op)
{
    long long k=u%C[op];
    while(k<INF&&!check(u,op,k)) k+=C[op];
    if(k<INF) return k;
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    long long u,v;
    cin>>u>>v;
    BigInteger nu=query(u),nv=query(v); 
    BigInteger a[3]={0,0,0},b[3]={0,0,0};
    for(int op=0;op<=1;op++)
        if(u%C[op]==v%C[op]) a[op]=b[op]=gcd(nu,query(findk(u,op)));
    if(a[0]==0&&b[1]==0)
    {
        long long k=CRT({(int)(u%C[0]),(int)(v%C[1])},{C[0],C[1]});
        while(k%C[2]==u%C[2]||k%C[2]==v%C[2]||k%C[1]==u%C[1]||k%C[0]==v%C[0]) k+=(long long)C[0]*C[1];
        BigInteger nk=query(k);
        a[0]=gcd(nu,nk),b[1]=gcd(nv,nk);
    }
    if(a[1]==0&&b[0]==0)
    {
        long long k=CRT({(int)(u%C[1]),(int)(v%C[0])},{C[1],C[0]});
        while(k%C[2]==u%C[2]||k%C[2]==v%C[2]||k%C[0]==u%C[0]||k%C[1]==v%C[1]) k+=(long long)C[0]*C[1];
        BigInteger nk1=query(k);
        a[1]=gcd(nu,nk1),b[0]=gcd(nv,nk1);
    }
    for(int op=0;op<=1;op++)
    {
        if(a[op]==0) a[op]=gcd(nu,query(findk(u,op)));
        if(b[op]==0) b[op]=gcd(nv,query(findk(v,op)));
    }
    a[2]=nu/a[0]/a[1],b[2]=nv/b[0]/b[1];
    BigInteger res=a[0]+a[1]+a[2]+b[0]+b[1]+b[2];
    cout<<"! "<<res<<endl;
    return 0;
}