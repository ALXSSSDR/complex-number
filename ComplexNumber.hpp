#ifndef ComplexNumber_hpp
#define ComplexNumber_hpp

#include <iostream>

class ComplexNumber {
private:
    double real;            // Действительная часть
    double imaginary;       // Мнимая часть
    
public:
    ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary) {}
    
    double getReal() const;
    
    void setReal(double real);
    
    double getImaginary() const;
    
    void setImaginary(double imaginary);
    
    ComplexNumber operator+(const ComplexNumber& other) const;
    
    ComplexNumber operator-(const ComplexNumber& other) const;
    
    ComplexNumber operator*(const ComplexNumber& other) const;
    
    ComplexNumber operator/(const ComplexNumber& other) const;
    
    bool operator==(const ComplexNumber& other) const;
    
    bool operator!=(const ComplexNumber& other) const;
    
    bool operator==(double num);
    
    ComplexNumber operator^(int exp) const;
    
    double getMagnitude() const;
    
    void display();
};

#endif
