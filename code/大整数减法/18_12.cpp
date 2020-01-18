//AC
#include <cstdio>
#include <cstring>

typedef long long ll;

class Num
{
public:
	static const int LEN=200;
	void init(ll num=0);
	Num(const ll num=0) { init(num); }
	void stn(const char s[]);
	Num(const char s[]) { stn(s); }
	void input();
	void output();
	int& operator[](const int k) { return num[k]; }
	Num operator-(Num& b);
private:
	int num[LEN],len;
} a,b;

int main()
{
	a.input(); b.input();
	(a-b).output();
	return 0;
}

void Num::init(ll num)
{
	memset(this->num,0,sizeof this->num);
	for (len=0; num; ++len)
	{
		this->num[len]=num%10;
		num/=10;
	}
	if (!len) len=1;
}

void Num::stn(const char s[])
{
	memset(num,0,sizeof num);
	int tmp=strlen(s);
	for (len=0; len<tmp; ++len) num[len]=s[tmp-1-len]-'0';
	while (len>1&&!num[len-1]) --len;
}

void Num::input()
{
	char s[LEN+1];
	scanf("%s",s);
	stn(s);
}

void Num::output()
{
	for (int i=len-1; ~i; --i) printf("%d",num[i]);
}

Num Num::operator-(Num& b)
{
	Num ret;
	for (int i=0;i<len;++i)
	{
		ret[i]+=num[i]-b[i];
		if (ret[i]<0)
		{
			--ret[i+1];
			ret[i]+=10;
		}
	}
	ret.len=len;
	int &i=ret.len;
	while (i>1&&!ret[i-1]) --i;
	return ret;
}
