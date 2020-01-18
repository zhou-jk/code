#include <cstdio>

#define chose(a, b) numbers[a] > numbers[b] ? a : b //)后面可以没有空格 ()内的空格不影响 

using namespace std;

void swap(int& a, int& b) {
    int t;
    t = a;
    a = b;
    b = t;
}

int main() {
    int n = 10;
    int m;
    int numbers[10];
    int i;
    
    // 读入给定的数字
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < n; i++) {
        m = i;
        for (int j = i + 1; j < n; j++) {
            m = chose(m, j);
        }
        swap(numbers[i], numbers[m]);
    }
    for (int i = 0; i < n - 1; i++) {
        printf("%i ", numbers[i]);
    }
    printf("%i\n", numbers[n - 1]);
    return 0;
}
