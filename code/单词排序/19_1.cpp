// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::sort;
using std::unique;

const int N_WORD = 100;
struct Word
{
	static const int LEN = 50;
	char word[LEN + 1];
} ans[N_WORD];

bool cmp(Word &a, Word &b)
{
	return strcmp(a.word, b.word) < 0;
}

bool cmp1(Word &a, Word &b)
{
	return strcmp(a.word, b.word) == 0;
}

int main()
{
	int n = 0;
	while (scanf("%s", ans[n].word) != EOF) ++n;
	sort(ans, ans + n, cmp);
	n = unique(ans, ans + n, cmp1) - ans;
	for (int i = 0; i < n; ++i) puts(ans[i].word);
	return 0;
}