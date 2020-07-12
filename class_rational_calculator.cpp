
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

//template
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <map>

using namespace std;

//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

//gcd: only positive numbers
int gcd(int a, int b) {
    while (true) {
        a = a % b;
        if (a == 0) {
            if (b < 0)
                b *= -1;
            return b;
        }
        b = b % a;
        if (b == 0) {
            if (a < 0)
                a *= -1;
            return a;
        }
    }
}

//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

//rational numbers class
class Rational {
public:
    //default constructor
    Rational() {
        NUMER = 0;
        DENOM = 1;
    }

    //constructor
    Rational(const int &numerator, const int &denominator) {
        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        const int temp = gcd(numerator, denominator);
        NUMER = numerator / temp;
        DENOM = denominator / temp;
        if (DENOM < 0) {
            NUMER = -NUMER;
            DENOM = -DENOM;
        }
    }

    //to identify numerator
    int Numerator() const {
        return NUMER;
    }

    //to identify denominator
    int Denominator() const {
        return DENOM;
    }

    //additional part, not sure that it works
    //assignment operator
    //also '=' doesn't work outside class even with friend prefix
    Rational &operator=(const Rational &number) {
        if (this == &number) {
            return *this;
        }
        NUMER = number.Numerator();
        DENOM = number.Denominator();
        return *this; //this -- pointer to current object
    }

    friend istream &operator>>(istream &in, Rational &temp);

private:
    int NUMER;
    int DENOM;
};

//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

ostream &operator<<(ostream &out, const Rational &number) {
    out << number.Numerator() << '/' << number.Denominator();
    return out;
}

istream &operator>>(istream &in, Rational &temp) {
    int numer(0), denom(1);
    in >> numer;
    in.ignore(1);
    if (in) {
        in >> denom;
        temp = Rational(numer, denom);
    }
    return in;
}

//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

Rational operator+(const Rational &lhs, const Rational &rhs) {
    return {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()};
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
    return {lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()};
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

bool operator==(const Rational &lhs, const Rational &rhs) {
    return (lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator());
}

bool operator<(const Rational &lhs, const Rational &rhs) {
    return (lhs - rhs).Numerator() < 0;
}

//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

Rational DoOperation(const Rational &lhs, const char &operation, const Rational &rhs) {
    switch (operation) {
        case '+':
        return lhs + rhs;
        case '-':
        return lhs - rhs;
        case '*':
        return lhs * rhs;
        case '/':
        return lhs / rhs;
        default:
        throw runtime_error("Invalid operation");
    }
}

//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----
//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

int main() {
    Rational a, b;
    char operation;
    try {
        cin >> a >> operation >> b;
        a = DoOperation(a, operation, b);
        //cout << "Result: ";
        cout << a << endl;
    } catch (const exception &ex) {
        //cout << "Attention: exception happened: ";
        cout << ex.what() << endl;
    }
    return 0;
}