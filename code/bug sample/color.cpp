#include <cstdio>

int main()
{
	char **sss = new char *[3];
	for (int i = 0; i < 3; ++i)
		sss[i] = new char[2];
	return 0;
}