// AC
#include <cstdio>

const int LEN = 200000;
const char pat[] = "wzpakzjoi";
char str[LEN + 1];

int main() {
    freopen("wzp.in", "r", stdin);
    freopen("wzp.out", "w", stdout);
    int ans = 0;
    scanf("%s", str);
    for (int i = 0; str[i]; ++i) {
        int j;
        for (j = 0; pat[j]; ++j)
            if (str[i + j] != pat[j]) break;
        ans += !pat[j];
    }
    printf("%d", ans);
    return 0;
}
