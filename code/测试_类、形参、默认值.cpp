#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class Clock {
    public:
        void setTime(int newS = 0, int newM = 0, int newH = 0); //�� int=0, int=0, int=0 
        void showTime();
    private:
        int second, minute, hour;
}; 

void Clock::setTime(int newS, int newM, int newH) { //���� int newS, newM, newH (�������) 
            second = newS; 
            minute = newM;
            hour = newH;
        }
        
void Clock::showTime() {
    cout << hour << ":" << minute << ":" << second << endl; //':'
}

int main() {
    Clock MyClock;
    int second, minute, hour;
    //cin >> second >> minute >> hour;
    MyClock.setTime(); //MyClock.setTime(second, minute, hour);
    MyClock.showTime(); //���� MyClock.setTime; (�������)
    return 0;
}
