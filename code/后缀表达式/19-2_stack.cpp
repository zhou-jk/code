#include <cctype>
#include <cstdio>
#include <stack>

using std::scanf;
using std::stack;

const int LEN = 1000;
char s[LEN + 1];

int main()
{
	int tmp = 0;
	stack<int> stk;
	scanf("%s", s);
	for (int i = 0; s[i] != '@'; ++i)
		if (isdigit(s[i]))
			tmp = (tmp << 1) + (tmp << 3) + (s[i] ^ 48);
		else
		{
			if (s[i] == '.')
			{
				stk.push(tmp);
				tmp = 0;
			}
			else
			{
				int a = stk.top();
				stk.pop();
				int b = stk.top();
				stk.pop();
				switch (s[i])
				{
					case '+': stk.push(b + a); break;
					case '-': stk.push(b - a); break;
					case '*': stk.push(b * a); break;
					case '/': stk.push(b / a); break;
				}
			}
		}
	printf("%d", stk.top());
	return 0;
}