// AC
#include <cstdio>

const int N = 200000;
int a[N];
char s[N + 1];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int l = 0, r = n - 1, now = 0, cnt = 0;
    while (l <= r) {
        int tmp = -1;
        if (a[l] > now && a[r] > now) {
            if (a[l] == a[r]) {
                int i, cnt1, cnt2;
                for (i = l + 1; a[i] > a[i - 1] && i <= r; ++i)
                    ;
                cnt1 = i - l;
                for (i = r - 1; a[i] > a[i + 1] && i >= l; --i)
                    ;
                cnt2 = r - i;
                if (cnt1 > cnt2)
                    while (cnt1--) s[cnt++] = 'L';
                else
                    while (cnt2--) s[cnt++] = 'R';
                break;
            } else
                tmp = a[l] > a[r];
        } else {
            if (a[l] > now) tmp = 0;
            if (a[r] > now) tmp = 1;
        }
        if (tmp == -1) break;
        if (tmp) {
            now = a[r--];
            s[cnt++] = 'R';
        } else {
            now = a[l++];
            s[cnt++] = 'L';
        }
    }
    printf("%d\n", cnt);
    puts(s);
    return 0;
}