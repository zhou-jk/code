#include <iostream>
using namespace std;

void upper_case_count(char arr[31]) {
    // 请在下面实现统计并输出大写字母个数的功能
    int n = 0;
    for (int i = 0; i < 30; i++) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') n++;
    }
    cout << n << endl;
}
void lower_case_count(char arr[31]) {
    // 请在下面实现统计并输出小写字母个数的功能
    int n = 0;
    for (int i = 0; i < 30; i++) {
        if (arr[i] >= 'a' && arr[i] <= 'z') n++;
    }
    cout << n << endl;
}
void digit_count(char arr[31]) {
    // 请在下面实现统计并输出数字个数的功能
    int n = 0;
    for (int i = 0; i < 30; i++) {
        if (arr[i] >= '0' && arr[i] <= '9') n++;
    }
    cout << n << endl;
}
void space_count(char arr[31]) {
    // 请在下面实现统计并输出空格个数的功能
    int n = 0;
    for (int i = 0; i < 30; i++) {
        if (arr[i] == ' ') n++;
    }
    cout << n << endl;
}

int main() {
    char string[31];
    int i;
    cin.getline(string,31);
    upper_case_count(string);
    lower_case_count(string);
    digit_count(string);
    space_count(string);
    return 0;
    
}
