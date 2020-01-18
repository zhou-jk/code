// AC
#include <cstdio>

int main()
{
	int a, b, ans;
	char op;
	scanf("%d %c %d", &a, &op, &b);
	switch (op)
	{
		case '+': ans = a + b; break;
		case '-': ans = a - b; break;
		case '*': ans = a * b; break;
		case '/': ans = a / b; break;
		case '%': ans = a % b; break;
	}
	printf("%d", ans);
	return 0;
}