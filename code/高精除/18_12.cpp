//AC
#include <cstdio>
#include <cstring>

typedef long long ll;

class Num
{
public:
	static const int LEN=300;
	void init(ll num=0);
	Num(const ll num=0) { init(num); }
	void stn(const char s[]);
	Num(const char s[]) { stn(s); }
	void input();
	void output();
	int& operator[](const int k) { return num[k]; }
	bool operator>(Num& b) { return cmp(*this,b)==1; }
	Num operator+(const int b);
	void operator-=(Num& b);
	Num operator*(const int b);
	Num operator/(Num& b);
	Num operator%(Num& b);
private:
	int cmp(Num& a,Num& b);
	int num[LEN],len;
} a,b;

int main()
{
	a.input();
	b.input();
	(a/b).output();
	puts("");
	(a%b).output();
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

Num Num::operator+(const int b)
{
	Num ret(*this);
	ret[0]+=b;
	int i;
	for (i=0;ret[i];++i)
	{
		ret[i+1]+=ret[i]/10;
		ret[i]%=10;
	}
	if (i>ret.len) ret.len=i;
	return ret;
}

void Num::operator-=(Num& b)
{
	for (int i=0;i<len;++i)
	{
		num[i]-=b[i];
		if (num[i]<0)
		{
			--num[i+1];
			num[i]+=10;
		}
	}
	while (len>1&&!num[len-1]) --len;
}

Num Num::operator*(const int b)
{
	Num ret;
	for (int i=0;i<len;++i) ret[i]=num[i]*b;
	int &i=ret.len;
	i=0;
	while (ret[i]||i<len)
	{
		ret[i+1]+=ret[i]/10;
		ret[i]%=10;
		++i;
	}
	if (!i) i=1; 
	return ret;
}

/*void Num::operator*=(const int b)
{
	for (int i=0;i<len;++i) num[i]=num[i]*b;
	int bak=len;
	len=0;
	while (num[len]||len<bak)
	{
		num[len+1]+=num[len]/10;
		num[len]%=10;
		++len;
	}
	if (!len) len=1;
}*/

Num Num::operator/(Num& b)
{
	Num tmp,ret,s[10];
	int l=len-b.len;
	//printf("%d\n",l);
	for (int i=l+1;i<len;++i) tmp[i-l-1]=num[i];
	tmp.len=b.len-1;
	if (!tmp.len) tmp.len=1;
	//tmp.output();
	//puts("");
	for (int i=1;i<10;++i) 
	{
		s[i]=b*i;
		//s[i].output();
		//puts("#");
	}
	for (int i=l;i>=0;--i)
	{
		//(tmp*10).output();
		//puts(""); 
		tmp=tmp*10+num[i];
		//tmp.output();
		int j;
		for (j=1;j<10;++j)
			if (s[j]>tmp) break;
		--j;
		//printf(" %d %d\n",i,j);
		tmp-=s[j];
		ret=ret*10+j;
	}
	return ret;
}

Num Num::operator%(Num& b)
{
	Num tmp,ret,s[10];
	int l=len-b.len;
	for (int i=l+1;i<len;++i) tmp[i-l-1]=num[i];
	tmp.len=b.len-1;
	if (!tmp.len) tmp.len=1;
	for (int i=1;i<10;++i) s[i]=b*i;
	for (int i=l;i>=0;--i)
	{
		tmp=tmp*10+num[i];
		int j;
		for (j=1;j<10;++j)
			if (s[j]>tmp) break;
		--j;
		tmp-=s[j];
	}
	return tmp;
}

int Num::cmp(Num& a,Num& b)
{
	if (a.len>b.len) return 1;
	if (b.len>a.len) return -1;
	for (int i=a.len-1;~i;--i)
	{
		if (a[i]>b[i]) return 1;
		if (b[i]>a[i]) return -1;
	}
	return 0;
}

	/*void operator+=(Num& const b)
	{
		if (b.len>len) len=b.len;
		for (int i=0;i<len;++i)
		{
			num[i]+=b[i];
			num[i+1]+=num[i]/10;
			num[i]%=10;
		}
		if (num[len]) ++len;
	}*/
