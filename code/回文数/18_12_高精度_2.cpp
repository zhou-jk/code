// AC
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

using std::swap;

typedef long long ll;

class Num
{
  public:
	static const int LEN = 200;
	const int BASE;
	void init(ll num = 0);
	Num(const ll num = 0, const int base = 10) : BASE(base) { init(num); }
	int stn(const char s[]);
	Num(const char s[], const int base = 10) : BASE(base) { stn(s); }
	int input();
	void output() const;
	int get_len() const { return len; }
	int &operator[](const int k) { return num[k]; }
	int operator[](const int k) const { return num[k]; }
	Num &operator+=(const Num &b);

  private:
	int ctn(char c)
	{
		if (isdigit(c)) return c - '0';
		if (islower(c)) return c - 'a' + 10;
		if (isupper(c)) return c - 'A' + 10;
		return -1;
	}
	int num[LEN], len;
};

bool check(const Num &num)
{
	int len = num.get_len();
	for (int i = 0; i<len>> 1; ++i)
		if (num[i] != num[len - 1 - i]) return false;
	return true;
}

Num reversal(Num num)
{
	int len = num.get_len();
	for (int i = 0; i<len>> 1; ++i) swap(num[i], num[len - 1 - i]);
	return num;
}

int main()
{
	int base;
	scanf("%d", &base);
	Num num(0LL, base);
	num.input();
	int ans;
	for (ans = 0; ans < 30 && !check(num); ++ans) num += reversal(num);
	if (check(num))
		printf("STEP=%d", ans);
	else
		puts("Impossible!");
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
	int tmp = strlen(s);
	for (len = 0; len < tmp; ++len)
	{
		num[len] = ctn(s[tmp - 1 - len]);
		if (num[len] < 0) return num[len];
	}
	while (len > 1 && !num[len - 1]) --len;
	return 0;
}

int Num::input()
{
	char s[LEN + 1];
	scanf("%s", s);
	return stn(s);
}

void Num::output() const
{
	for (int i = len - 1; ~i; --i) printf("%d", num[i]);
}

Num &Num::operator+=(const Num &b)
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
	return *this;
}