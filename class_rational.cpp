//template
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <map>

using namespace std;

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

//another way
/*istream& operator >> (istream& is, Rational& r) {
    int n, d;
    char c;
    is >> n >> c >> d;
    if (is && c == '/') {
        r = Rational(n, d);
    }
    return is;
}*/

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
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

bool operator==(const Rational &lhs, const Rational &rhs) {
    return (lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator());
}

bool operator<(const Rational &lhs, const Rational &rhs) {
    return (lhs - rhs).Numerator() < 0;
}

//
//unit tests
//

//fifth test
int main() {
    {
        const set<Rational> rs = {{1, 2},
                                  {1, 25},
                                  {3, 4},
                                  {3, 4},
                                  {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        v.reserve(rs.size());
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25},
                                  {1, 2},
                                  {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
/*    return 0;
}

//fourth test
int main() {*/
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
/*    return 0;
}

//third test
int main() {*/
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
/*    return 0;
}

//second test
int main() {*/
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
/*    return 0;
}

//first test
int main() {*/

    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}