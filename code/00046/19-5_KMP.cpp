// AC
#include <cstdio>

const int LEN = 1000000;
char str[LEN + 1], pat[LEN + 1];
int next[LEN];

void MakeNext(const char str[], int next[]) {
    next[0] = -1;
    for (int i = 1, j = -1; str[i]; ++i) {
        while (~j && str[j + 1] != str[i]) j = next[j];
        if (str[j + 1] == str[i]) ++j;
        next[i] = j;
    }
}

void Kmp(const char str[], const char pat[]) {
    for (int i = 0, j = -1; str[i]; ++i) {
        while (~j && pat[j + 1] != str[i]) j = next[j];
        if (pat[j + 1] == str[i]) ++j;
        if (!pat[j + 1]) printf("%d\n", i - j + 1);
    }
}

int main() {
    scanf("%s%s", str, pat);
    MakeNext(pat, next);
    Kmp(str, pat);
    for (int i = 0; pat[i]; ++i) printf("%d ", next[i] + 1);
    return 0;
}