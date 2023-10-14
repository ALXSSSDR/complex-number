#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber {
private:
    double real;            // Действительная часть
    double imaginary;       // Мнимая часть

public:
    ComplexNumber(double real, double imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }
    
    double getReal() const {    // Получить действительную часть
        return real;
    }
    
    void setReal(double real) {    // Установить действительную часть
        this->real = real;
    }
    
    double getImaginary() const {   // Получить мнимую часть
        return imaginary;
    }
    
    void setImaginary(double imaginary) {   // Установить мнимую часть
        this->imaginary = imaginary;
    }
    
    ComplexNumber operator+(const ComplexNumber& other) const {   // Сложение двух комплексных чисел
        double newReal = real + other.real;
        double newImaginary = imaginary + other.imaginary;
        return ComplexNumber(newReal, newImaginary);
    }
    
    ComplexNumber operator-(const ComplexNumber& other) const {   // Вычитание двух комплексных чисел
        double newReal = real - other.real;
        double newImaginary = imaginary - other.imaginary;
        return ComplexNumber(newReal, newImaginary);
    }
    
    ComplexNumber operator*(const ComplexNumber& other) const {   // Умножение двух комплексных чисел
        double newReal = (real * other.real) - (imaginary * other.imaginary);
        double newImaginary = (real * other.imaginary) + (imaginary * other.real);
        return ComplexNumber(newReal, newImaginary);
    }
    
    ComplexNumber operator/(const ComplexNumber& other) const {   // Деление двух комплексных чисел
        if (other.real == 0 && other.imaginary == 0) {
            // Ошибка: деление на ноль
            throw logic_error("Division by zero.");
        }
        
        double divisor = (other.real * other.real) + (other.imaginary * other.imaginary);
        double newReal = ((real * other.real) + (imaginary * other.imaginary)) / divisor;
        double newImaginary = ((imaginary * other.real) - (real * other.imaginary)) / divisor;
        return ComplexNumber(newReal, newImaginary);
    }
    
    bool operator==(const ComplexNumber& other) const {   // Сравнение двух комплексных чисел
        return real == other.real && imaginary == other.imaginary;
    }
    
    bool operator!=(const ComplexNumber& other) const {   // Проверка неравенства двух комплексных чисел
        return !(*this == other);
    }
    
    bool operator==(double real) const {   // Сравнение комплексного числа с вещественным числом
        return this->real == real && imaginary == 0.0;
    }
    
    bool operator!=(double real) const {   // Проверка неравенства комплексного числа с вещественным числом
        return !(*this == real);
    }
    
    bool operator==(int real) const {   // Сравнение комплексного числа с целым числом
        return this->real == real && imaginary == 0.0;
    }
    
    bool operator!=(int real) const {   // Проверка неравенства комплексного числа с целым числом
        return !(*this == real);
    }
    
    ComplexNumber operator^(int exp) const {   // Возведение комплексного числа в степень
        if (exp < 0) {
            // Ошибка: отрицательная степень не поддерживается
            throw logic_error("Negative exponent not supported.");
        }
        
        ComplexNumber result(1, 0);
        
        for (int i = 0; i < exp; i++) {
            result = result * (*this);
        }
        return result;
    }
    
    double getMagnitude() const {   // Вычисление модуля комплексного числа
        return sqrt((real * real) + (imaginary * imaginary));
    }
};

int main() {
    ComplexNumber c1(4, -2);
    ComplexNumber c2(2, 7);
    
    c2.setReal(8);
    
    ComplexNumber sum = c1 + c2;
    ComplexNumber difference = c1 - c2;
    ComplexNumber multiplication = c1 * c2;
    ComplexNumber division = c1 / c2;
    
    cout << "Sum: " << sum.getReal() << " + " << sum.getImaginary() << "i\n";
    cout << "Difference: " << difference.getReal() << " + " << difference.getImaginary() << "i\n";
    cout << "multiplication: " << multiplication.getReal() << " + " << multiplication.getImaginary() << "i\n";
    cout << "division: " << division.getReal() << " + " << division.getImaginary() << "i\n";
    
    if (c1 == c2) {
        cout << "c1 is equal to c2\n";
    } else {
        cout << "c1 is not equal to c2\n";
    }
    
    double realNumber = 2.9;
    
    if (c1 == realNumber) {
        cout << "c1 is equal to " << realNumber << "\n";
    } else {
        cout << "c1 is not equal to " << realNumber << "\n";
    }
    
    int exp = 2;
    ComplexNumber result = c1 ^ exp;   // Возведение в степень
    
    cout << "Result: " << result.getReal() << " + " << result.getImaginary() << "i\n";
    
    double modulus = c1.getMagnitude();   // Вычисление модуля
    cout << "Modulus of c1: " << modulus << "\n";
    
    return 0;
}
