#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<vector>
#include<sstream>
using namespace std;
class BigInteger
{
    public :
        //constructor
        BigInteger(int = 0);
        BigInteger(long long);
        BigInteger(const string &);
        BigInteger(const char *str)
        {
            *this = string(str);
        }

        //assignment operators
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

        //relatiional operators
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

        //arithmetic operators
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

        //compound assignment operators
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

        //increment and decrement operators
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

        //input and output
        friend istream &operator>>(istream &, BigInteger &);
        friend ostream &operator<<(ostream &, const BigInteger &);

    protected :
        enum div_type { division, remainder };
        enum cmp_type { with_sign, without_sign };
        static const int base_ = (int)1e4;
        static const int width_ = 4;
        BigInteger(int s, const vector<int> &v) : sign_(s), val_(v) {}
        int cmp(const BigInteger &, cmp_type = with_sign) const;
        BigInteger &delZero();
        BigInteger &add(const BigInteger &);
        BigInteger &sub(const BigInteger &);
        BigInteger &mul(const BigInteger &, const BigInteger &);
        BigInteger &div(BigInteger &, BigInteger, div_type = division);

    private :
        int sign_;
        vector<int> val_;
};

BigInteger::BigInteger(int num) : sign_(0)
{
    if (num < 0) sign_ = -1, num = -num;
    else if (num > 0) sign_ = 1;
    do
    {
        val_.push_back(num % base_);
        num /= base_;
    }
    while (num);
}

BigInteger::BigInteger(long long num) : sign_(0)
{
    if (num < 0) sign_ = -1, num = -num;
    else if (num > 0) sign_ = 1;
    do
    {
        val_.push_back(num % base_);
        num /= base_;
    }
    while (num);
}

BigInteger::BigInteger(const string &str)
{
    sign_ = str[0] == '-' ? -1 : 1;
    int be = str[0] == '-' ? 1 : 0, en = str.size();
    while ((en -= width_) >= be)
    {
        stringstream ss(str.substr(en, width_));
        int temp;
        ss >> temp;
        val_.push_back(temp);
    }
    if ((en += width_) > be)
    {
        stringstream ss(str.substr(be, en - be));
        int temp;
        ss >> temp;
        val_.push_back(temp);
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
    else if (sign_ * obj.sign_ == -1) return *this - -obj;
    else return sign_ == 0 ? obj : *this;
}

BigInteger BigInteger::operator-(const BigInteger &obj) const
{
    if (sign_ * obj.sign_ == 1)
    {
        BigInteger temp;
        return cmp(obj, without_sign) >= 0 ? (temp = *this).sub(obj) : (temp = -obj).sub(*this);
    }
    else if (sign_ * obj.sign_ == -1) return *this + -obj;
    else return sign_ == 0 ? -obj : *this;
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
    if (in >> str) obj = str;
    return in;
}

ostream &operator<<(ostream &out, const BigInteger &obj)
{
    if (obj.sign_ == -1) out << '-';
    out << obj.val_.back();
    for (int i = obj.val_.size() - 2; i >= 0; i--)
        out << setw(BigInteger::width_) << setfill('0') << obj.val_[i];
    return out;
}

int BigInteger::cmp(const BigInteger &obj, cmp_type typ) const
{
    if (typ == with_sign && sign_ != obj.sign_) return sign_ - obj.sign_;
    int sign = typ == with_sign ? sign_ : 1;
    if (val_.size() != obj.val_.size()) return sign * (val_.size() - obj.val_.size());
    for (int i = val_.size() - 1; i >= 0; i--)
        if (val_[i] != obj.val_[i]) return sign * (val_[i] - obj.val_[i]);
    return 0;
}

inline BigInteger &BigInteger::delZero()
{
    while(val_.back() == 0 && val_.size() > 1) val_.pop_back();
    if (val_.back() == 0) sign_ = 0;
    return *this;
}

BigInteger &BigInteger::add(const BigInteger &obj)
{
    int ts = val_.size(), os = obj.val_.size();
    for (int i = 0; i < os; i++) val_[i] += obj.val_[i];
    val_.push_back(0);
    for (int i = 0; i < ts; i++)
        if (val_[i] >= base_) val_[i] -= base_, ++val_[i + 1];
    return delZero();
}

BigInteger &BigInteger::sub(const BigInteger &obj)
{
    int pos = obj.val_.size();
    for (int i = 0; i < pos; i++)
        if ((val_[i] -= obj.val_[i]) < 0) val_[i] += base_, --val_[i + 1];
    while (val_[pos] < 0) val_[pos] += base_, --val_[++pos];
    return delZero();
}

BigInteger &BigInteger::mul(const BigInteger &a, const BigInteger &b)
{
    int as = a.val_.size(), bs = b.val_.size();
    val_.resize(as + bs);
    for (int i = 0; i < as; i++) for (int j = 0; j < bs; j++)
        {
            int x = i + j;
            val_[x] += a.val_[i] * b.val_[j];
            val_[x + 1] += val_[x] / base_;
            val_[x] %= base_;
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
            if (a.cmp(b * BigInteger(mid), without_sign) >= 0) left = mid;
            else right = mid;
        }
        val_[i] = left;
        a.sub(b * BigInteger(left));
        b.val_.erase(b.val_.begin());
    }
    return typ == division ? delZero() : a;
}
const int N=40000001;
int n,type;
int a[N];
long long sum[N];
long long pre[N];
int q[N],head,tail;
template <typename T>
inline T read(T &x)
{
    x=0;
    char ch;
    bool flag=true;
    for(ch=getchar();ch<'0'&&ch>'9';ch=getchar())
        if(ch=='-') flag=false;
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    if(!flag) x=-x;
    return x;
}
template <typename T>
inline void write(T x)
{
    if(x<0) x=-x,putchar('-');
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return;
}
int main()
{
    read(n),read(type);
    if(type==0)
    {
        for(int i=1;i<=n;i++)
            read(a[i]);
    }
    else if(type==1)
    {
        int x,y,z,m;
        read(x),read(y),read(z),read(a[1]),read(a[2]),read(m);
        for(int i=3;i<=n;i++)
            a[i]=(a[i-1]*x+a[i-2]*y+z)&((1<<30)-1);
        int lst=0;
        for(int i=1;i<=m;i++)
        {
            int p,l,r;
            read(p),read(l),read(r);
            for(int j=lst+1;j<=p;j++)
                a[j]=a[j]%(r-l+1)+l;
            lst=p;
        }
    }
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
	q[++tail]=0;
    for(int i=1;i<=n;i++)
	{
		while(head<tail&&sum[i]>=2*sum[q[head+1]]-sum[pre[q[head+1]]]) head++;
		pre[i]=q[head];
		while(head<=tail&&2*sum[q[tail]]-sum[pre[q[tail]]]>=2*sum[i]-sum[pre[i]]) tail--;
		q[++tail]=i;
	}
    BigInteger ans=0;
    for(int i=n;i;i=pre[i])
        ans+=(BigInteger)(sum[i]-sum[pre[i]])*(sum[i]-sum[pre[i]]);
    cout<<ans;
    return 0;
}