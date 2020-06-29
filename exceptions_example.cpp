#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

void CheckNextSymbolAndSkip (stringstream &stream) {
    if (stream.peek() != '/') {
        stringstream error;
        error << "expected \'/\', but there is \'"
              << char(stream.peek()) << "\'!\n";
        throw runtime_error(error.str());
        //throw exception();
    }
    stream.ignore(1);
}

Date ParseDate(const string &ss_date) {
    stringstream stream(ss_date);
    Date date;
    stream >> date.year;
    CheckNextSymbolAndSkip(stream);
    stream >> date.month;
    CheckNextSymbolAndSkip(stream);
    stream >> date.day;
    return date;    
}

int main() {
    Date date;

    string ss_date = "2019f01/29";

    //try to do this block
    try {
        date = ParseDate(ss_date);
        cout << setw(2) << setfill('0') << date.day << '.'
             << setw(2) << setfill('0') << date.month << '.'
             << date.year << endl;
    }
    //class that we'd like to catch
    catch (exception &ex) {
        cout << "exception happened: " << ex.what();
        //cout << "exception happened" << endl;
    }

	return 0;
}