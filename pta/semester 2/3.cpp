#include <iostream>
using namespace std;

template<typename T>
class Complex {
private:
    T real;
    T img;

public:
    Complex(T real = 0, T img = 0) : real(real), img(img) {}

    Complex operator+(const Complex& other) {
        return Complex(this->real + other.real, this->img + other.img);
    }

    void print() const {
        cout << "(" << real << ", " << img << ")" << endl;
    }
};

int main() {
    double real1, img1, real2, img2;

    cin >> real1 >> img1;
    cin >> real2 >> img2;

    Complex<double> x(real1, img1);
    Complex<double> y(real2, img2);

    Complex<double> result = x + y;
    result.print();

    return 0;
}
