// AC
#include <cstdio>
#include <cstdlib>

double calc()
{
	static const int LEN = 20;
	static char s[LEN + 1];
	scanf("%s", s);
	switch (s[0])
	{
		case '+': return calc() + calc();
		case '-': return calc() - calc();
		case '*': return calc() * calc();
		case '/': return calc() / calc();
		default: return atof(s);
	}
}

int main()
{
	printf("%f", calc());
	return 0;
}