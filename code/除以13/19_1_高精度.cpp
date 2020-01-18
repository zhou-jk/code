// AC
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using std::swap;

typedef long long ll;

enum OutMode
{
	DIGIT,
	ALPHA
};

enum Error
{
	ERR_TYPE = -2,
	ERR_LEN = -3,
	ERR_MODE = -4
};

class Num
{
  public:
	static const int LEN = 100;
	void init(ll num = 0); //?
	Num(const ll num = 0, const int base = 10, const int base_real = 10) :
		BASE(base), BASE_REAL(base_real)
	{
		init(num);
	}
	int stn(const char s[], const int seg = 1);
	Num(const char s[], const int seg = 1, const int base = 10,
		const int base_real = 10) :
		BASE(base),
		BASE_REAL(base_real)
	{
		stn(s, seg);
	}
	int input(const int seg = 1);
	int output(const OutMode mode = ALPHA) const; //?
	int get_len() const { return len; }
	int &operator[](const int k) { return num[k]; }
	int operator[](const int k) const { return num[k]; }
	Num operator-() const
	{
		Num ret(*this);
		ret.neg = !neg;
		return ret;
	} //?
	bool operator==(const int b) const
	{
		Num tmp(b, BASE, BASE_REAL);
		return !cmp(*this, tmp);
	}
	bool operator!=(const int b) const
	{
		Num tmp(b, BASE, BASE_REAL);
		return cmp(*this, tmp);
	}
	bool operator<(const Num &b) const { return cmp(*this, b) == -1; }
	bool operator>(const Num &b) const { return cmp(*this, b) == 1; }
	Num operator+(const int b) const;  //?
	Num operator+(const Num &b) const; //?
	Num &operator+=(const int b);	  //?
	Num &operator+=(const Num &b);	 //?
	Num operator-(const int b) const;  //?
	Num operator-(const Num &b) const; //?
	Num &operator-=(const int b);	  //?
	Num &operator-=(const Num &b);	 //?
	Num operator*(const int b) const;  //?
	Num operator*(const Num &b) const; //?
	Num &operator*=(const int b);	  //?
	Num &operator*=(const Num &b);	 //?
	Num operator/(const int b) const;  //?
	int operator%(const int b) const;  //?
	Num operator/(const Num &b) const; //?
	Num operator%(const Num &b) const; //?

  private:
	int cmp(const Num &a, const Num &b) const;
	int ctn(char c)
	{
		if (isdigit(c)) return c - '0';
		if (islower(c)) return c - 'a' + 10;
		if (isupper(c)) return c - 'A' + 10;
		return ERR_TYPE;
	}
	int num[LEN], len, BASE, BASE_REAL;
	bool neg;
} a;

int main()
{
	a.input();
	(a / 13).output();
	putchar('\n');
	printf("%d", a % 13);
	return 0;
}

void Num::init(ll num)
{
	neg = num < 0;
	memset(this->num, 0, sizeof this->num);
	for (len = 0; num; ++len)
	{
		this->num[len] = num % BASE;
		num /= BASE;
	}
	if (!len) len = 1;
}

int Num::stn(const char s[], const int seg)
{
	memset(num, 0, sizeof num);
	int a[seg] = {1};
	for (int i = 1; i < seg; ++i) a[i] = a[i - 1] * BASE_REAL;
	int l = neg = s[0] == '-', r = strlen(s) - 1;
	for (int i = r; i >= l; --i)
	{
		int k1 = (r - i) / seg, k2 = (r - i) % seg, tmp;
		num[k1] += (tmp = ctn(s[i])) * a[k2];
		if (tmp < 0) return tmp;
		if (num[k1]) len = k1 + 1;
	}
	if (!len) len = 1;
	return 0;
}

int Num::input(const int seg)
{
	char s[LEN * seg + 1];
	if (scanf("%s", s) == EOF) return EOF;
	return stn(s, seg);
}

int Num::output(const OutMode mode) const
{
	if (neg) putchar('-');
	switch (mode)
	{
		case ALPHA:
			for (int i = len - 1; ~i; --i)
				if (num[i] < 10)
					printf("%d", num[i]);
				else if (num[i] < 36)
					printf("%c", (char)(num[i] - 10 + 'A'));
				else
					return ERR_TYPE;
			break;
		case DIGIT:
			printf("%d", num[len - 1]);
			for (int i = len - 2; ~i; --i)
			{
				int weight1, weight2, tmp1 = BASE - 1, tmp2 = num[i];
				for (weight1 = 0; tmp1; tmp1 /= 10, ++weight1)
					;
				for (weight2 = 0; tmp2; tmp2 /= 10, ++weight2)
					;
				if (!num[i]) weight2 = 1;
				for (int j = 0; j < weight1 - weight2; ++j) putchar('0');
				printf("%d", num[i]);
			}
			break;
		default: return ERR_MODE;
	}
	return 0;
}

Num Num::operator+(const int b) const
{
	Num ret(*this);
	if (b)
	{
		if ((b < 0) ^ neg)
			ret -= -b;
		else
		{
			ret[0] += b;
			int i;
			for (i = 0; ret[i]; ++i)
			{
				ret[i + 1] += ret[i] / BASE;
				ret[i] %= BASE;
			}
			if (i > ret.len) ret.len = i;
		}
	}
	return ret;
}

Num Num::operator+(const Num &b) const
{
	Num ret(*this);
	if (b != 0)
	{
		if (neg ^ b.neg)
			ret -= -b;
		else
		{
			int &i = ret.len;
			for (i = 0; i < len || i < b.len; ++i)
			{
				ret[i] += b[i];
				ret[i + 1] += ret[i] / BASE;
				ret[i] %= BASE;
			}
			if (ret[i]) ++i;
		}
	}
	return ret;
}

Num &Num::operator+=(const int b)
{
	if (b != 0)
	{
		if ((b < 0) ^ neg)
			*this -= -b;
		else
		{
			num[0] += b;
			for (int i = 0; i < len; ++i)
			{
				num[i + 1] += num[i] / BASE;
				num[i] %= BASE;
			}
			if (num[len]) ++len;
		}
	}
	return *this;
}

Num &Num::operator+=(const Num &b)
{
	if (b != 0)
	{
		if (neg ^ b.neg)
			*this -= -b;
		else
		{
			int i;
			for (i = 0; i < len || i < b.len; ++i)
			{
				num[i] += b[i];
				num[i + 1] += num[i] / BASE;
				num[i] %= BASE;
			}
			len = i;
			if (num[len]) ++len;
		}
	}
	return *this;
}

Num Num::operator-(const int b) const
{
	Num ret(*this);
	if (b)
	{
		if ((b < 0) ^ neg)
			ret += -b;
		else
		{
			ret[0] -= b;
			for (int i = 0; i < len; ++i)
				if (ret[i] < 0)
				{
					--ret[i + 1];
					ret[i] += BASE;
				}
			while (ret.len > 1 && !ret[len - 1]) --ret.len;
		}
	}
	return ret;
}

Num Num::operator-(const Num &b) const
{
	Num ret(*this);
	if (b != 0)
	{
		if (neg ^ b.neg)
			ret += b;
		else if ((neg && b < *this) || (!neg && b > *this))
		{
			ret = b - *this;
			ret.neg = !neg;
		}
		else
		{
			for (int i = 0; i < len; ++i)
			{
				ret[i] -= b[i];
				if (ret[i] < 0)
				{
					--ret[i + 1];
					ret[i] += BASE;
				}
			}
			while (ret.len > 1 && !ret[len - 1]) --ret.len;
			if (ret.len == 1 && !ret[0]) ret.neg = false;
		}
	}
	return ret;
}

Num &Num::operator-=(const int b)
{
	if (b)
	{
		if ((b < 0) ^ neg)
			*this += -b;
		else
		{
			num[0] -= b;
			for (int i = 0; i < len; ++i)
				if (num[i] < 0)
				{
					--num[i + 1];
					num[i] += BASE;
				}
			while (len > 1 && !num[len - 1]) --len;
		}
	}
	return *this;
}

Num &Num::operator-=(const Num &b)
{
	if (b != 0)
	{
		if (neg ^ b.neg)
			*this += -b;
		else if ((neg && b < *this) || (!neg && b > *this))
		{
			*this = b - *this;
			neg = !neg;
		}
		else
		{
			for (int i = 0; i < len; ++i)
			{
				num[i] -= b[i];
				if (num[i] < 0)
				{
					--num[i + 1];
					num[i] += BASE;
				}
			}
			while (len > 1 && !num[len - 1]) --len;
			if (len == 1 && !num[0]) neg = false;
		}
	}
	return *this;
}

Num Num::operator*(const int b) const
{
	Num ret(0LL, BASE, BASE_REAL);
	ret.neg = neg ^ (b < 0);
	int tmp = abs(b);
	for (int i = 0; i < len; ++i) ret[i] = num[i] * tmp;
	int &i = ret.len;
	for (i = 0; ret[i] || i < len; ++i)
	{
		ret[i + 1] += ret[i] / BASE;
		ret[i] %= BASE;
	}
	while (i > 1 && !ret[i - 1]) --i;
	if (i == 1 && !ret[0]) ret.neg = false;
	return ret;
}

Num Num::operator*(const Num &b) const
{
	Num ret(0LL, BASE, BASE_REAL);
	ret.neg = neg ^ b.neg;
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < b.len; ++j) ret[i + j] += num[i] * b[j];
	int &l = ret.len;
	l = len + b.len - 1;
	for (int i = 0; i < l; ++i)
	{
		ret[i + 1] += ret[i] / BASE;
		ret[i] %= BASE;
	}
	if (ret[l]) ++l;
	while (l > 1 && !ret[l - 1]) --l;
	if (l == 1 && !ret[0]) ret.neg = false;
	return ret;
}

Num &Num::operator*=(const int b)
{
	neg ^= b < 0;
	for (int i = 0; i < len; ++i) num[i] *= b;
	int i;
	for (i = 0; num[i] || i < len; ++i)
	{
		num[i + 1] += num[i] / BASE;
		num[i] %= BASE;
	}
	len = i;
	while (len > 1 && !num[len - 1]) --len;
	if (len == 1 && !num[0]) neg = false;
	return *this;
}

Num &Num::operator*=(const Num &b)
{
	Num tmp(0LL, BASE, BASE_REAL);
	tmp.neg = neg ^ b.neg;
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < b.len; ++j) tmp[i + j] += num[i] * b[j];
	int &l = tmp.len;
	l = len + b.len - 1;
	for (int i = 0; i < l; ++i)
	{
		tmp[i + 1] += tmp[i] / BASE;
		tmp[i] %= BASE;
	}
	if (tmp[l]) ++l;
	while (l > 1 && !tmp[l - 1]) --l;
	if (l == 1 && !tmp[0]) tmp.neg = false;
	return *this = tmp;
}

Num Num::operator/(const int b) const
{
	Num ret(0LL, BASE, BASE_REAL);
	int tmp = 0;
	if (b != 0)
	{
		ret.neg = neg ^ (b < 0);
		for (int i = len - 1; i >= 0; --i)
		{
			tmp = tmp * BASE + num[i];
			ret = ret * BASE + tmp / b;
			tmp %= b;
		}
		if (ret.len == 1 && !ret[0]) ret.neg = false;
	}
	else
		puts("div 0");
	return ret;
}

int Num::operator%(const int b) const
{
	int tmp = 0;
	if (b != 0)
		for (int i = len - 1; i >= 0; --i)
		{
			tmp = tmp * BASE + num[i];
			tmp %= b;
		}
	else
		puts("div 0");
	return tmp;
}

Num Num::operator/(const Num &b) const
{
	Num tmp(0LL, BASE, BASE_REAL), ret(0LL, BASE, BASE_REAL), s[BASE];
	if (b != 0)
	{
		ret.neg = neg ^ b.neg;
		int l = len - b.len;
		for (int i = l + 1; i < len; ++i) tmp[i - l - 1] = num[i];
		tmp.len = b.len - 1;
		if (!tmp.len) tmp.len = 1;
		for (int i = 1; i < BASE; ++i) { s[i] = b * i; }
		for (int i = l; i >= 0; --i)
		{
			tmp = tmp * BASE + num[i];
			int j;
			for (j = 1; j < BASE; ++j)
				if (s[j] > tmp) break;
			--j;
			tmp -= s[j];
			ret = ret * BASE + j;
		}
		if (ret.len == 1 && !ret[0]) ret.neg = false;
	}
	else
		puts("div 0");
	return ret;
}

Num Num::operator%(const Num &b) const
{
	Num tmp(0LL, BASE, BASE_REAL), s[BASE];
	if (b != 0)
	{
		tmp.neg = neg;
		int l = len - b.len;
		for (int i = l + 1; i < len; ++i) tmp[i - l - 1] = num[i];
		tmp.len = b.len - 1;
		if (!tmp.len) tmp.len = 1;
		for (int i = 1; i < BASE; ++i) s[i] = b * i;
		for (int i = l; i >= 0; --i)
		{
			tmp = tmp * BASE + num[i];
			int j;
			for (j = 1; j < BASE; ++j)
				if (s[j] > tmp) break;
			--j;
			tmp -= s[j];
		}
		if (tmp.len == 1 && !tmp[0]) tmp.neg = false;
	}
	else
		puts("div 0");
	return tmp;
}

int Num::cmp(const Num &a, const Num &b) const
{
	if (!a.neg && b.neg) return 1;
	if (a.neg && !b.neg) return -1;
	if (a.len > b.len) return 1;
	if (b.len > a.len) return -1;
	for (int i = a.len - 1; ~i; --i)
	{
		if (a[i] > b[i]) return a.neg ? -1 : 1;
		if (b[i] > a[i]) return a.neg ? 1 : -1;
	}
	return 0;
}