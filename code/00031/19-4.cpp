// AC
#include <cstdio>
#include <set>

using std::multiset;

const int N = 200000;
int a[N];

int main() {
    int n;
    multiset<int> s;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        s.insert(tmp);
    }
    for (int i = 0; i < n; ++i) {
        int tmp = (n - a[i]) % n;
        multiset<int>::iterator it;
        it = s.lower_bound(tmp);
        if (it == s.end()) it = s.lower_bound(0);
        int tmp1 = *it;
        s.erase(it);
        printf("%d ", (tmp1 + a[i]) % n);
    }
    return 0;
}