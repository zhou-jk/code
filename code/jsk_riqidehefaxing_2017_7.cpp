#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int year,month,day;
    char c;
    cin>>year>>c>>month>>c>>day;
    if (month>12) {
        cout<<"NO";
    }
    else if (day>31){
        cout<<"NO";
    }
    else if ((month==2||month==4||month==6||month==9||month==11)&&day>30) {
        cout<<"NO";
    }
    else if (month==2){
        if (day>29){
            cout<<"NO";
        }
        else if (((year%100==0&&year%400!=0)||year%4!=0)&&day>28) {
            cout<<"NO";
        }
        else {
            cout<<"YES";
        }
    }
    else {
        cout<<"YES";
    }
    return 0;
}
