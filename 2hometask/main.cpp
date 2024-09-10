//
//  main.cpp
//  2hometask
//
//  Created by Valeria  Bukova on 10.09.2024.
//

#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce()
    {
        int gcd_value = gcd(abs(numerator), abs(denominator));
        numerator /= gcd_value;
        denominator /= gcd_value;

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom)
    {
        if (denominator == 0)
        {
            cout << "Error: Denominator cannot be zero." << endl;
            exit(1);
        }
        reduce();
    }

    void setValues(int num, int denom)
    {
        numerator = num;
        denominator = denom;
        if (denominator == 0)
        {
           cout << "Error: Denominator cannot be zero." << endl;
            exit(1);
        }
        reduce();
    }

    Fraction add(const Fraction& other) const
    {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction subtract(const Fraction& other) const
    {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction multiply(const Fraction& other) const
    {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction divide(const Fraction& other) const
    {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        if (denom == 0)
        {
            cout << "Error: Division by zero." << endl;
            exit(1);
        }
        return Fraction(num, denom);
    }

    void display() const
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main()
{
    Fraction frac1(3, 4);
    Fraction frac2(2, 5);

    Fraction result;

    result = frac1.add(frac2);
    cout << "Addition: ";
    result.display();

    result = frac1.subtract(frac2);
    cout << "Subtraction: ";
    result.display();

    result = frac1.multiply(frac2);
    cout << "Multiplication: ";
    result.display();

    result = frac1.divide(frac2);
    cout << "Division: ";
    result.display();

    return 0;
}
