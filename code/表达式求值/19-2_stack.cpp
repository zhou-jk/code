#include <cstdio>
#include <stack>

using std::getchar;
using std::printf;
using std::scanf;
using std::stack;

const int P = 10000;
int p[128];
stack<int> s1;
stack<char> s2;

void calc(char op)
{
	int a = s1.top();
	s1.pop();
	int b = s1.top();
	s1.pop();
	switch (op)
	{
		case '+': s1.push((a + b) % P); break;
		case '*': s1.push((a * b) % P); break;
	}
}

int main()
{
	int num;
	p['+'] = 1;
	p['*'] = 2;
	while (scanf("%d", &num) != EOF)
	{
		num %= P;
		s1.push(num);
		char op = getchar();
		if (op == '+' || op == '*')
		{
			while (!s2.empty() && p[s2.top()] >= p[op])
			{
				calc(s2.top());
				s2.pop();
			}
			s2.push(op);
		}
		else
			break;
	}
	while (!s2.empty())
	{
		calc(s2.top());
		s2.pop();
	}
	printf("%d", s1.top());
	return 0;
}