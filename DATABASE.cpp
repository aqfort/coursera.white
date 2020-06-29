#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <set>

using namespace std;

//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

class Date {
public:
    Date() {}

    Date(const int &new_YEAR,
         const int &new_MONTH,
         const int &new_DAY) {
        if (new_MONTH < 1 || new_MONTH > 12) {
            throw runtime_error("Month value is invalid: " + to_string(new_MONTH));
        } else if (new_DAY < 1 || new_DAY > 31) {
            throw runtime_error("Day value is invalid: " + to_string(new_DAY));
        }
        YEAR = new_YEAR;
        MONTH = new_MONTH;
        DAY = new_DAY;
    }

    int GetYear() const {
        return YEAR;
    }

    int GetMonth() const {
        return MONTH;
    }

    int GetDay() const {
        return DAY;
    }

    friend istream &operator>>(istream &in, Date &date);

private:
    int YEAR;
    int MONTH;
    int DAY;

    void ParseDateFromString(const string &string_input) {
        istringstream string_stream(string_input);
        bool flag = true;

        flag = flag && (string_stream >> YEAR);
        flag = flag && (string_stream.peek() == '-');
        string_stream.ignore(1);

        flag = flag && (string_stream >> MONTH);
        flag = flag && (string_stream.peek() == '-');
        string_stream.ignore(1);

        flag = flag && (string_stream >> DAY);
        flag = flag && (string_stream.eof());

        if (!flag) {
            throw runtime_error("Wrong date format: " + string_input);
        }

        if (MONTH < 1 || MONTH > 12) {
            throw runtime_error("Month value is invalid: " + to_string(MONTH));
        } else if (DAY < 1 || DAY > 31) {
            throw runtime_error("Day value is invalid: " + to_string(DAY));
        }
    }
};

//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

istream &operator>>(istream &in, Date &date) {
    string string_input;
    in >> string_input;
    date.ParseDateFromString(string_input);
    return in;
}

ostream &operator<<(ostream &out, const Date &date) {
    out << setfill('0') << setw(4) << date.GetYear() << '-'
        << setfill('0') << setw(2) << date.GetMonth() << '-'
        << setfill('0') << setw(2) << date.GetDay();
    return out;
}

bool operator<(const Date &lhs, const Date &rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    } else {
        return lhs.GetDay() < rhs.GetDay();
    }
}

//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        if (!event.empty()) {
            DATA[date].emplace(event);
        }
    }

    bool DeleteEvent(const Date& date, const string& event) {
        if (DATA.count(date) > 0 && DATA[date].count(event) > 0) {
            if (DATA[date].size() > 1) {
                DATA[date].erase(event);
            } else {
                DATA.erase(date);
            }
            return true;
        } else {
            return false;
        }
    }

    int DeleteDate(const Date& date) {
        int result(0);
        if (DATA.count(date) > 0) {
            result = DATA.at(date).size();
            DATA.erase(date);
        }
        return result;
    }

    set<string> Find(const Date& date) const {
        set<string> result;
        if (DATA.count(date) > 0) {
            result = DATA.at(date);
        }
        return result;
    }

    void Print() const {
        for (const auto &item : DATA) {
            for (const auto &under_item : item.second) {
                cout << item.first << ' ' << under_item << endl;
            }
        }
    }

private:
    map<Date, set<string>> DATA;
};

//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

int main() {
    Database db;
    string command;

//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

    //ifstream input("input.txt");

//----- ----- ----- ----- ----- ----- ----- ----- ----- -----

    while (getline(cin, command)) { //if wanna use input.txt: cin -> input
        try {
            if (command.empty()) {
                continue;
            }

            Date date;

            stringstream command_stream(command);
            command_stream >> command;

            if (command == "Add") {
                command.clear();
                command_stream >> date >> command;

                if (!command.empty()) {
                    db.AddEvent(date, command);
                }
            }

            else if (command == "Del") {
                command.clear();
                command_stream >> date;

                if (!command_stream.eof()) {
                    command_stream >> command;
                }

                if (command.empty()) {
                    cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
                } else if (db.DeleteEvent(date, command)) {
                    cout << "Deleted successfully" << endl;
                } else {
                    cout << "Event not found" << endl;
                }
            }

            else if (command == "Find") {
                command_stream >> date;
                for (const auto &item : db.Find(date)) {
                    cout << item << endl;
                }
            }

            else if (command == "Print") {
                db.Print();
            }

            else {
                cout << "Unknown command: " << command << endl;
                return 0;
            }
            command.clear();
        }

        catch (const exception &ex) {
            cout << ex.what() << endl;
            return 0;
        }
    }

    return 0;
}