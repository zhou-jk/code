#include <cstdio>

using namespace std;

int main(int argc, char **argv) {
	for (int i = 0; i < argc; i++) {
		argv[i] = "999";
		printf("%s %p %p %c %p\n", argv[i], argv[i], *argv[i], *argv[i], argc);
    }
}
