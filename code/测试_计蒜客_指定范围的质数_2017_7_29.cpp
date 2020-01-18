#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n = 1000000;
int mark[1000001];

int main() {
    int c;
    memset(mark, 0, sizeof(mark));
    mark[0] = 1;
    mark[1] = 1;
    int m;
    scanf("%i %i", &n, &m); 
    for (c = 2; c * c <= n; c++) {
        if (mark[c] != 1) {
            for (int i = 2; i <= n / c; i++) {
                mark[c * i] = 1;
            }
        }
    }
    for (int i = m; i <= n; i++) {
        if (mark[i] != 1) {
            printf("%i\n", i);
        }
    }
    return 0;
}
