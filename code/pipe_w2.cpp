#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100000, M = 200000, LEN = 100000;
vector<pair<int, int> > edge1[LEN];
int fa[N];

inline int read()
{
    int x = 0;
    int w = 0;
    char ch = 0;
    while (ch < '0' || ch > '9') w |= ch == '-', ch = getchar();
    while (ch >= '0' && ch <= '9')
	x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

inline int get_fa(int k)
{
    return fa[k] == k ? k : fa[k] = get_fa(fa[k]);
}

int main()
{
    freopen("pipe.in", "r", stdin);
    freopen("pipe.out", "w", stdout);
    int t;
    t = read();
    for (int i = 0; i < t; i++)
    {
	int n = read(), m = read();
	for (int j = 0; j < n; j++) fa[j] = j;
	for (int j = 0; j < LEN; j++) edge1[j].clear();
	for (int j = 0; j < m; j++)
	{
	    int u = read(), v = read(), len = read();
	    edge1[len - 1].push_back(make_pair(u - 1, v - 1));
	}
	int tmp = 0, ans = 0;
	bool b = true;
	for (int j = 0; j < LEN; j++)
	{
	    if (!edge1[j].size()) continue;
	    if (b)
		for (int k = 0; k < edge1[j].size(); k++)
		{
		    int x = get_fa(edge1[j][k].first),
			y = get_fa(edge1[j][k].second);
		    if (x != y) tmp++;
		}
	    for (int k = 0; k < edge1[j].size(); k++)
	    {
		int x = get_fa(edge1[j][k].first),
		    y = get_fa(edge1[j][k].second);
		if (x != y) ans += j + 1, fa[x] = y, tmp--;
	    }
	    if (tmp) b = false;
	}
	printf("%d\n", ans);
	if (b)
	    puts("Yes");
	else
	    puts("No");
    }
    return 0;
}