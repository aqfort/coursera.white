#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, d;
    cin >> a >> b >> c;

    d = pow(b, 2) - 4 * a * c;

    if (d < 0) {
        cout << "No roots\n";
    } else {

        d = sqrt(d);

        if (a != 0) {
            if (d == 0) {
                cout << "One root: x = " << -b / (2 * a) << endl;
            } else {
                cout << "Two roots:\n1: " << (-b - d) / (2 * a) << endl << "2: " << (-b + d) / (2 * a) << endl;
            }
        } else if (b != 0) {
            cout << "One root: x = " << -c / b << endl;
        } else {
            cout << (c != 0 ? "No roots\n" : "Any number is a root\n");
        }
    }

    return 0;
}