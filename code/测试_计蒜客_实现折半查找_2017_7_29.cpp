#include <cstdio>
#include <iostream>

using namespace std;

int numbers[1000001];

int main() {
    int n;
    int k;
    int m;
    int i;
    int j;
    // 反复读入数字和查找数字的数量
    while (scanf("%d %d", &n, &k) != EOF) {
        // 读入给定的数字
        for (i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }
        
        for (j = 0; j < k; j++) {
            // 读入待查找的数字，
            scanf("%i", &m);

            // 请在下面完成查找读入数字的功能
            int mid, l = 0 , r = n - 1;
            bool b = true;
            while (l <= r) {
                mid = (l + r) / 2;
                if (numbers[mid] == m) {
                    printf("%d", mid + 1);
                    if (j < k - 1) {
                        printf(" ");
                    }
                    b = false;
                    break;
                }
                if (numbers[mid] > m) {
                    r = mid - 1;
                } 
                if (numbers[mid] < m) {
                    l = mid + 1;
                }
            }
            if (b) {
                printf("0");
                if (j < k - 1) {
                    printf(" ");
                }
            }
        }

    }
    return 0;
}
