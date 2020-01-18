#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using std::abs;
using std::vector;

const char FIRST_CH = 'a', LAST_CH = 'z';
const int LEN = 20, KIND_CH = LAST_CH - FIRST_CH + 1;
vector<int> g1[KIND_CH], g2[KIND_CH];
char s[LEN + 1];
bool f[KIND_CH], vis[KIND_CH];

void dfs(int k)
{
    vis[k] = true;
    for (int i = 0; i < g1[k].size(); ++i)
        if (!vis[g1[k][i]])
            dfs(g1[k][i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    int k;
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        int tmp1 = s[0] - FIRST_CH, tmp2 = s[strlen(s) - 1] - FIRST_CH;
        f[tmp1] = f[tmp2] = true;
        g1[tmp1].push_back(tmp2);
        g2[tmp2].push_back(tmp1);
        k = tmp1;
    }
    int cnt = 0;
    for (int i = 0; i < KIND_CH; ++i)
        if (f[i])
        {
            if (abs((int)g1[i].size() - (int)g2[i].size()) > 1) //unsigned int不能有负数
            {
                puts("impossible");
                return 0;
            }
            if (g1[i].size() - g2[i].size() == 1)
            {
                k = i;
                ++cnt;
                if (cnt > 1)
                {
                    puts("impossible");
                    return 0;
                }
            }
        }
    dfs(k);
    for (int i = 0; i < KIND_CH; ++i)
        if (f[i] && !vis[i])
        {
            puts("impossible");
            return 0;
        }
    if (cnt)
        puts("Euler path");
    else
        puts("Euler loop");
    return 0;
}