#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct student {
	student(int& new_score, string& new_name): score(new_score), name(new_name) {}
    int score;
    string name;
}; 

int main() {
    int input;
    string name;
    vector <student> students;
    while (cin >> name >> input) {
        students.push_back(student(input, name));
    }
    sort(students.begin(), students.end(), [](student& a, student& b) {
        return a.score < b.score || a.score == b.score && a.name <= b.name;
    });
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].name << ' ' << students[i].score << endl;
    }
    cout << students.size();
    return 0; 
}
