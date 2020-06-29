#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string &first_name, const string &last_name, const int &year) {
        name[year] = first_name;
        surname[year] = last_name;
    }

    void ChangeFirstName(const int &year, const string &first_name) {
        if (year >= name.begin()->first)
            name[year] = first_name;
    }

    void ChangeLastName(const int &year, const string &last_name) {
        if (year >= name.begin()->first)
            surname[year] = last_name;
    }

    string GetFullNameWithHistory(const int &year) const {
        if (year < name.begin()->first)
            return "No person";
        vector<string> names = GetFullDataByYear(name, year);
        vector<string> surnames = GetFullDataByYear(surname, year);
        return GetResult(TurnVectorToString(names), TurnVectorToString(surnames));
    }

    string GetFullName(const int &year) const {
        if (year < name.begin()->first)
            return "No person";
        string names = GetDataByYear(name, year);
        string surnames = GetDataByYear(surname, year);
        return GetResult(names, surnames);
    }

private:
    map<int, string> name;
    map<int, string> surname;

    string TurnVectorToString(const vector<string> &data) const {
        string result;
        if (data.empty())
            return result;
        result = data[0];
        if (data.size() > 1) {
            result += " (";
            for (int i = 1; i < data.size(); ++i) {
                result += data[i] + ", ";
            }
            result.erase(result.length() - 2); //delete last 2 characters of string result
            result += ')';
        }
        return result;
    }

    vector<string> GetFullDataByYear(const map<int, string> &data, const int &year) const {
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

    string GetDataByYear(const map<int, string> &data, const int &year) const {
        string result;
        for (const auto &item : data) {
            if (item.first > year)
                break;
            result = item.second;
        }
        return result;
    }

    string GetResult(const string &names, const string &surnames) const {
        if (names.empty() && surnames.empty())
            return "Incognito";
        if (names.empty())
            return surnames + " with unknown first name";
        if (surnames.empty())
            return names + " with unknown last name";
        return names + ' ' + surnames;
    }
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}