#include <iostream>
#include <cstdio>

using namespace std;

int main() {
   char str[] = "Hello";
   char* s = str;
   char* s1 = "Hello";
   char** s2 = &s1;
   s[1] = 'x';
   cout << s << ' ' << s1 << ' ' << s2 << endl;
   printf("%p %s %p %s %p %s", s, s, s1, s1, s2, s2); //s2不能作为字符串输出 
}
