// AC
#include <cctype>
#include <cstdio>
#include <cstring>

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
	static const int LEN = 300;
	void init(ll num = 0);
	Num(const ll num = 0, const int base = 10) : BASE(base) { init(num); }
	int stn(const char s[]);
	Num(const char s[], const int base = 10) : BASE(base) { stn(s); }
	int input();
	int output(const OutMode mode = ALPHA) const;
	int get_len() const { return len; }
	int &operator[](const int k) { return num[k]; }
	int operator[](const int k) const { return num[k]; }
	Num &operator*=(const Num &b);

  private:
	int ctn(char c)
	{
		if (isdigit(c)) return c - '0';
		if (islower(c)) return c - 'a' + 10;
		if (isupper(c)) return c - 'A' + 10;
		return ERR_TYPE;
	}
	int num[LEN], len, BASE;
};

Num pow(Num a, int b)
{
	Num ret(1);
	for (; b; b >>= 1)
	{
		if (b & 1) ret *= a;
		a *= a;
	}
	return ret;
}

int main()
{
	Num a(2);
	int n;
	scanf("%d", &n);
	pow(a, n).output();
	return 0;
}

void Num::init(ll num)
{
	memset(this->num, 0, sizeof this->num);
	for (len = 0; num; ++len)
	{
		this->num[len] = num % BASE;
		num /= BASE;
	}
	if (!len) len = 1;
}

int Num::stn(const char s[])
{
	memset(num, 0, sizeof num);
	int j = strlen(s) - 1;
	for (len = 0; ~j; ++len)
	{
		if (len == LEN) return ERR_LEN;
		int tmp;
		for (; ~j && (tmp = ctn(s[j])) + num[len] < BASE; --j)
		{
			if (tmp < 0) return tmp;
			num[len] += tmp;
		}
	}
	return 0;
}

int Num::input()
{
	char s[LEN + 1];
	if (scanf("%s", s) == EOF) return EOF;
	return stn(s);
}

int Num::output(const OutMode mode) const
{
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

Num &Num::operator*=(const Num &b)
{
	Num tmp;
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
	*this = tmp;
	return *this;
}