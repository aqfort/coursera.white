#include <sstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Duration
{
    int hour;
    int min;

    Duration(int h = 0, int m = 0) {
        hour = h + m / 60;
        min = m % 60;
    }
};

ostream& operator << (ostream& out, const Duration& dur) {
    out << setfill('0');
    out << setw(2) << dur.hour << ':'
        << setw(2) << dur.min;
    return out;
}

istream& operator >> (istream& in, Duration& dur) {
    in >> dur.hour;
    in.ignore(1);
    in >> dur.min;
    return in;
}

Duration operator + (const Duration& lhs, const Duration& rhs) {
    return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

bool operator < (const Duration& lhs, const Duration& rhs) {
    if (lhs.hour == rhs.hour) {
        return lhs.min < rhs.min;
    }
    return lhs.hour < rhs.hour;
}

void PrintVector (const vector<Duration>& vector) {
    for (const auto& item : vector) {
        cout << item << ' ';
    }
    cout << endl;
}

int main()
{
    stringstream dur_ss("02:50");
    Duration dur1, dur2 = {0, 35};
    dur_ss >> dur1;
    Duration dur3 = dur1 + dur2;

    vector<Duration> v {
        dur3, dur1, dur2
    };

    PrintVector(v);

    sort(begin(v), end(v));

    PrintVector(v);

    return 0;
}