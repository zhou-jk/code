//AC
#include <cstdio>
#include <cstring>

class Num
{
public:
	static const int LEN=200;
	void init(long long num=0)
	{
		memset(this->num,0,sizeof this->num);
		for (len=0; num; ++len)
		{
			this->num[len]=num%10;
			num=num/10;
		}
		if (len==0) len=1;
	}
	Num(long long num=0)
	{
		init(num);
	}
	void stn(char s[])
	{
		memset(num,0,sizeof num);
		int tmp=strlen(s);
		for (len=0; len<tmp; ++len) num[len]=s[tmp-1-len]-'0';
	}
	Num(char s[])
	{
		stn(s);
	}
	void input()
	{
		char s[LEN+1];
		scanf("%s",s);
		stn(s);
	}
	void output()
	{
		for (int i=len-1; ~i; --i) printf("%d",num[i]);
	}
	int &operator[](int k)
	{
		return num[k];
	}
	Num *operator*(Num &b)
	{
		Num *ret=new Num;
		Num &r=*ret;
		for (int i=0; i<len; ++i)
			for (int j=0; j<b.len; ++j)
				r[i+j]+=num[i]*b[j];
		int &l=r.len;
		l=len+b.len-1;
		for (int i=0; i<l; ++i)
		{
			r[i+1]+=r[i]/10;
			r[i]%=10;
		}
		if (r[l]) ++l;
		while (l>1&&!r[l-1]) --l; 
		return ret;
	}
private:
	int num[LEN],len;
} a,b;

int main()
{
	a.input();
	b.input();
	(*(a*b)).output();
	return 0;
}
