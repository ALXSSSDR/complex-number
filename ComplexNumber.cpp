#include "ComplexNumber.hpp"

double ComplexNumber::getReal() const{
    return real;
}

double ComplexNumber::getImaginary() const{
    return imaginary;
}

void ComplexNumber::setReal(double real) {
    this->real = real;
}

void ComplexNumber::setImaginary(double imaginary) {
    this->imaginary = imaginary;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const{   // Сложение двух комплексных чисел
    double newReal = real + other.real;
    double newImaginary = imaginary + other.imaginary;
    return ComplexNumber(newReal, newImaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {   // Вычитание двух комплексных чисел
    double newReal = real - other.real;
    double newImaginary = imaginary - other.imaginary;
    return ComplexNumber(newReal, newImaginary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {   // Умножение двух комплексных чисел
    double newReal = (real * other.real) - (imaginary * other.imaginary);
    double newImaginary = (real * other.imaginary) + (imaginary * other.real);
    return ComplexNumber(newReal, newImaginary);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
    if (other.real == 0 && other.imaginary == 0) {
        // Ошибка: деление на ноль
        throw logic_error("Division by zero.");
    }
    
    double divisor = (other.real * other.real) + (other.imaginary * other.imaginary);
    double newReal = ((real * other.real) + (imaginary * other.imaginary)) / divisor;
    double newImaginary = ((imaginary * other.real) - (real * other.imaginary)) / divisor;
    return ComplexNumber(newReal, newImaginary);
}

bool ComplexNumber::operator==(const ComplexNumber& other) const {   // Сравнение двух комплексных чисел
    return real == other.real && imaginary == other.imaginary;
}

bool ComplexNumber::operator!=(const ComplexNumber& other) const {   // Проверка неравенства двух комплексных чисел
    return !(*this == other);
}

bool ComplexNumber::operator==(double num) {
    static constexpr double epsilon = 1e-9; // погрешность для сравнения с плавающей запятой

    double magnitude = getMagnitude();
    return fabs(magnitude - num) < epsilon;
}

ComplexNumber ComplexNumber::operator^(int exp) const {   // Возведение комплексного числа в степень
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

double ComplexNumber::getMagnitude() const {   // Вычисление модуля комплексного числа
    return sqrt((real * real) + (imaginary * imaginary));
}

void ComplexNumber::display() {
    std::cout << real << (imaginary < 0 ? " - " : " + ") << abs(imaginary) << "i" << std::endl;
}



