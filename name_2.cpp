#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

string TurnToString(const vector<string> &data) {
    string result;
    result = data[0];
    if (data.size() > 1) {
        result += " (";
        for (int i = 1; i < data.size(); ++i) {
            result += data[i] + ", ";
        }
        result.erase(result.length() - 2); //delete last 2 characters of string
        result += ')';
    }
    return result;
}

vector<string> GetFullDataByYear(const map<int, string> &data, const int &year) {
    vector<string> result;
    string temp_string;
    for (const auto &item : data) {
        if (item.first > year)
            break;
        if (temp_string != item.second) {
            result.push_back(item.second);
            temp_string = item.second;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

string GetDataByYear(const map<int, string> &data, const int &year) {
    string result;
    for (const auto &item : data) {
        if (item.first > year)
            break;
        result = item.second;
    }
    return result;
}

class Person {
public:
    void ChangeFirstName(int year, const string &first_name) {
        name[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        surname[year] = last_name;
    }

    string GetFullNameWithHistory(int year) {
        vector<string> res_name = GetFullDataByYear(name, year);
        vector<string> res_surname = GetFullDataByYear(surname, year);
        string result;
        if (res_name.empty() && res_surname.empty())
            result = "Incognito";
        else if (res_name.empty())
            result = TurnToString(res_surname) + " with unknown first name";
        else if (res_surname.empty())
            result = TurnToString(res_name) + " with unknown last name";
        else
            result = TurnToString(res_name) + ' ' + TurnToString(res_surname);
        return result;
    }

    string GetFullName(int year) {
        string res_name = GetDataByYear(name, year);
        string res_surname = GetDataByYear(surname, year);
        if (res_name.empty() && res_surname.empty())
            return "Incognito";
        if (res_name.empty())
            return res_surname + " with unknown first name";
        if (res_surname.empty())
            return res_name + " with unknown last name";
        return res_name + ' ' + res_surname;
    }

private:
    map<int, string> name;
    map<int, string> surname;
};

/*int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}*/

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}