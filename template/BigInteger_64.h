#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
class BigInteger_64
{
public:
    // constructor
    BigInteger_64(int = 0);
    BigInteger_64(long long);
    BigInteger_64(const string &);
    BigInteger_64(const char *str)
    {
        *this = string(str);
    }

    // assignment operators
    BigInteger_64 &operator=(int num)
    {
        return *this = BigInteger_64(num);
    }
    BigInteger_64 &operator=(long long num)
    {
        return *this = BigInteger_64(num);
    }
    BigInteger_64 &operator=(const string &str)
    {
        return *this = BigInteger_64(str);
    }
    BigInteger_64 &operator=(const char *str)
    {
        return *this = BigInteger_64(str);
    }

    // relational operators
    bool operator<(const BigInteger_64 &obj) const
    {
        return cmp(obj) < 0;
    }
    bool operator>(const BigInteger_64 &obj) const
    {
        return cmp(obj) > 0;
    }
    bool operator<=(const BigInteger_64 &obj) const
    {
        return cmp(obj) <= 0;
    }
    bool operator>=(const BigInteger_64 &obj) const
    {
        return cmp(obj) >= 0;
    }
    bool operator==(const BigInteger_64 &obj) const
    {
        return cmp(obj) == 0;
    }
    bool operator!=(const BigInteger_64 &obj) const
    {
        return cmp(obj) != 0;
    }

    // arithmetic operators
    BigInteger_64 operator+() const
    {
        return *this;
    }
    BigInteger_64 operator-() const
    {
        return BigInteger_64(-sign_, val_);
    }
    BigInteger_64 operator+(const BigInteger_64 &) const;
    BigInteger_64 operator-(const BigInteger_64 &) const;
    BigInteger_64 operator*(const BigInteger_64 &) const;
    BigInteger_64 operator/(const BigInteger_64 &) const;
    BigInteger_64 operator%(const BigInteger_64 &) const;

    // compound assignment operators
    BigInteger_64 &operator+=(const BigInteger_64 &obj)
    {
        return *this = *this + obj;
    }
    BigInteger_64 &operator-=(const BigInteger_64 &obj)
    {
        return *this = *this - obj;
    }
    BigInteger_64 &operator*=(const BigInteger_64 &obj)
    {
        return *this = *this * obj;
    }
    BigInteger_64 &operator/=(const BigInteger_64 &obj)
    {
        return *this = *this / obj;
    }
    BigInteger_64 &operator%=(const BigInteger_64 &obj)
    {
        return *this = *this % obj;
    }

    // increment and decrement operators
    BigInteger_64 &operator++()
    {
        return *this += 1;
    }
    BigInteger_64 &operator--()
    {
        return *this -= 1;
    }
    BigInteger_64 operator++(int);
    BigInteger_64 operator--(int);

    // input and output
    friend istream &operator>>(istream &, BigInteger_64 &);
    friend ostream &operator<<(ostream &, const BigInteger_64 &);

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
    static const long long base_ = (long long)1e18;
    static const int width_ = 18;
    BigInteger_64(int s, const vector<long long> &v) : sign_(s), val_(v) {}
    long long cmp(const BigInteger_64 &, cmp_type = with_sign) const;
    BigInteger_64 &delZero();
    BigInteger_64 &add(const BigInteger_64 &);
    BigInteger_64 &sub(const BigInteger_64 &);
    BigInteger_64 &mul(const BigInteger_64 &, const BigInteger_64 &);
    BigInteger_64 &div(BigInteger_64 &, BigInteger_64, div_type = division);

private:
    int sign_;
    vector<long long> val_;
};

BigInteger_64::BigInteger_64(int num) : sign_(0)
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

BigInteger_64::BigInteger_64(long long num) : sign_(0)
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

BigInteger_64::BigInteger_64(const string &str)
{
    sign_ = str[0] == '-' ? -1 : 1;
    int be = str[0] == '-' ? 1 : 0, en = str.size();
    while ((en -= width_) >= be)
    {
        val_.push_back(stoll(str.substr(en, width_)));
    }
    if ((en += width_) > be)
    {
        val_.push_back(stoll(str.substr(be, en - be)));
    }
    delZero();
}

BigInteger_64 BigInteger_64::operator+(const BigInteger_64 &obj) const
{
    if (sign_ * obj.sign_ == 1)
    {
        BigInteger_64 temp;
        return cmp(obj, without_sign) >= 0 ? (temp = *this).add(obj) : (temp = obj).add(*this);
    }
    else if (sign_ * obj.sign_ == -1)
        return *this - -obj;
    else
        return sign_ == 0 ? obj : *this;
}

BigInteger_64 BigInteger_64::operator-(const BigInteger_64 &obj) const
{
    if (sign_ * obj.sign_ == 1)
    {
        BigInteger_64 temp;
        return cmp(obj, without_sign) >= 0 ? (temp = *this).sub(obj) : (temp = -obj).sub(*this);
    }
    else if (sign_ * obj.sign_ == -1)
        return *this + -obj;
    else
        return sign_ == 0 ? -obj : *this;
}

inline BigInteger_64 BigInteger_64::operator*(const BigInteger_64 &obj) const
{
    BigInteger_64 temp;
    return (temp.sign_ = sign_ * obj.sign_) == 0 ? temp : temp.mul(*this, obj);
}

inline BigInteger_64 BigInteger_64::operator/(const BigInteger_64 &obj) const
{
    BigInteger_64 temp, mod = *this;
    return cmp(obj, without_sign) < 0 || (temp.sign_ = sign_ * obj.sign_) == 0 ? temp : temp.div(mod, obj);
}

inline BigInteger_64 BigInteger_64::operator%(const BigInteger_64 &obj) const
{
    BigInteger_64 temp, mod = *this;
    return cmp(obj, without_sign) < 0 || (temp.sign_ = sign_) == 0 ? mod : temp.div(mod, obj, remainder);
}

inline BigInteger_64 BigInteger_64::operator++(int)
{
    BigInteger_64 temp = *this;
    ++*this;
    return temp;
}

inline BigInteger_64 BigInteger_64::operator--(int)
{
    BigInteger_64 temp = *this;
    --*this;
    return temp;
}

inline istream &operator>>(istream &in, BigInteger_64 &obj)
{
    string str;
    if (in >> str)
        obj = str;
    return in;
}

ostream &operator<<(ostream &out, const BigInteger_64 &obj)
{
    if (obj.sign_ == -1)
        out << '-';
    out << obj.val_.back();
    for (int i = obj.val_.size() - 2; i >= 0; i--)
        out << setw(BigInteger_64::width_) << setfill('0') << obj.val_[i];
    return out;
}

long long BigInteger_64::cmp(const BigInteger_64 &obj, cmp_type typ) const
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

inline BigInteger_64 &BigInteger_64::delZero()
{
    while ((int)val_.size() > 1 && val_.back() == 0)
        val_.pop_back();
    if (val_.empty() || val_.back() == 0)
        sign_ = 0;
    return *this;
}

BigInteger_64 &BigInteger_64::add(const BigInteger_64 &obj)
{
    int os = obj.val_.size();
    val_.push_back(0);
    for (int i = 0; i < os; i++)
    {
        long long tmp = val_[i] + obj.val_[i];
        if (tmp >= base_)
            tmp -= base_, ++val_[i + 1];
        val_[i] = tmp;
    }
    return delZero();
}

BigInteger_64 &BigInteger_64::sub(const BigInteger_64 &obj)
{
    int pos = obj.val_.size();
    for (int i = 0; i < pos; i++)
    {
        long long tmp = val_[i] - obj.val_[i];
        if (tmp < 0)
            tmp += base_, --val_[i + 1];
        val_[i] = tmp;
    }
    while (val_[pos] < 0)
        val_[pos] += base_, --val_[++pos];
    return delZero();
}

BigInteger_64 &BigInteger_64::mul(const BigInteger_64 &a, const BigInteger_64 &b)
{
    int as = a.val_.size(), bs = b.val_.size();
    val_.resize(as + bs);
    for (int i = 0; i < as; i++)
        for (int j = 0; j < bs; j++)
        {
            int x = i + j;
            __int128 tmp = val_[x] + (__int128)a.val_[i] * b.val_[j];
            val_[x + 1] += tmp / base_;
            tmp %= base_;
            val_[x] = tmp;
        }
    return delZero();
}

BigInteger_64 &BigInteger_64::div(BigInteger_64 &a, BigInteger_64 b, div_type typ)
{
    int move = a.val_.size() - b.val_.size();
    val_.resize(move + 1);
    b.val_.insert(b.val_.begin(), move, 0);
    for (int i = move; i >= 0; i--)
    {
        long long left = 0, right = base_;
        while (left + 1 < right)
        {
            long long mid = (left + right) >> 1;
            if (a.cmp(b * BigInteger_64(mid), without_sign) >= 0)
                left = mid;
            else
                right = mid;
        }
        val_[i] = left;
        a.sub(b * BigInteger_64(left));
        b.val_.erase(b.val_.begin());
    }
    return typ == division ? delZero() : a;
}
int main()
{
    BigInteger_64 a,b;
    cin>>a>>b;
    cout<<a+b<<"\n"<<a-b<<"\n"<<a*b<<"\n"<<a/b<<"\n"<<a%b;
    return 0;
}