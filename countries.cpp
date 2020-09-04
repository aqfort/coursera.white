#include <iostream>
#include <string>
#include <map>

using namespace std;

void CHANGE_CAPITAL(map<string, string> &data);
void RENAME(map<string, string> &data);
void ABOUT(map<string, string> &data);
void DUMP(const map<string, string> &data);

int main() {
    int commands_number;
    string command;
    map<string, string> data;

    cin >> commands_number;

    for (int i = 0; i < commands_number; ++i) {
        cin >> command;
        if (command == "CHANGE_CAPITAL") {
            CHANGE_CAPITAL(data);
        } else if (command == "RENAME") {
            RENAME(data);
        } else if (command == "ABOUT") {
            ABOUT(data);
        } else {
            DUMP(data);
        }
    }

    return 0;
}

void CHANGE_CAPITAL(map<string, string> &data) {
    string new_country, new_capital;
    cin >> new_country >> new_capital;
    if (data.count(new_country) == 0) {
        cout << "Introduce new country " << new_country << " with capital " << new_capital << endl;
    } else if (data[new_country] == new_capital) {
        cout << "Country " << new_country << " hasn't changed its capital" << endl;
    } else {
        cout << "Country " << new_country << " has changed its capital from "
             << data[new_country] << " to " << new_capital << endl;
    }
    data[new_country] = new_capital;
}

void RENAME(map<string, string> &data) {
    string old_country, new_country;
    cin >> old_country >> new_country;
    if (old_country == new_country || data.count(old_country) == 0 || data.count(new_country) != 0) {
        cout << "Incorrect rename, skip" << endl;
    } else {
        cout << "Country " << old_country << " with capital " << data[old_country]
             << " has been renamed to " << new_country << endl;
        data[new_country] = data[old_country];
        data.erase(old_country);
    }
}

void ABOUT(map<string, string> &data) {
    string country;
    cin >> country;
    if (data.count(country) == 0) {
        cout << "Country " << country << " doesn't exist" << endl;
    } else {
        cout << "Country " << country << " has capital " << data[country] << endl;
    }
}

void DUMP(const map<string, string> &data) {
    if (data.empty()) {
        cout << "There are no countries in the world" << endl;
    } else {
        for (const auto &item : data) {
            cout << item.first << '/' << item.second << ' ';
        }
        cout << endl;
    }
}