// AC
#include <algorithm>
#include <cctype>
#include <cstdio>
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
	static const int LEN = 5000;
	void init(ll num = 0);
	Num(const ll num = 0, const int base = 10) : BASE(base) { init(num); }
	int stn(const char s[]);
	Num(const char s[], const int base = 10) : BASE(base) { stn(s); }
	int input();
	int output(const OutMode mode = ALPHA) const;
	int get_len() const { return len; }
	ll &operator[](const int k) { return num[k]; }
	ll operator[](const int k) const { return num[k]; }
	Num &operator*=(const int b);

  private:
	int ctn(char c)
	{
		if (isdigit(c)) return c - '0';
		if (islower(c)) return c - 'a' + 10;
		if (isupper(c)) return c - 'A' + 10;
		return ERR_TYPE;
	}
	ll num[LEN];
	int len, BASE;
};

int main()
{
	int n;
	scanf("%d", &n);
	Num a(1, 100000000);
	for (int i = 2; i <= n; ++i) a *= i;
	a.output(DIGIT);
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

Num &Num::operator*=(const int b)
{
	for (int i = 0; i < len; ++i) num[i] *= b;
	int i;
	for (i = 0; num[i] || i < len; ++i)
	{
		num[i + 1] += num[i] / BASE;
		num[i] %= BASE;
	}
	len = i;
	while (len > 1 && !num[len - 1]) --len;
	return *this;
}