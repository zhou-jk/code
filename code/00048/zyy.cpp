// AC
#include <cstdio>
#include <cstring>

const int LEN = 1000000;
char str[LEN + 1];
int next[LEN];

void MakeNext(const char str[], int next[]) {
    next[0] = -1;
    for (int i = 1, j = -1; str[i]; ++i) {
        while (~j && str[j + 1] != str[i]) j = next[j];
        j += str[j + 1] == str[i];
        next[i] = j;
    }
}

int main() {
    freopen("zyy.in", "r", stdin);
    freopen("zyy.out", "w", stdout);
    gets(str);
    MakeNext(str, next);
    int len = strlen(str);
    printf("%d", len - 1 - next[len - 1]);
}
