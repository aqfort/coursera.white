#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

pair<string, string> GetNameSurname(const map<int, pair<string, string>> &data, const int &year) {
    auto it = --data.end();
    auto stop = data.begin();
    pair<string, string> result;
    while ((it->first > year || it->second.first.empty()) && it != stop)
        it--;
    if ((it != stop || !it->second.first.empty()) && it->first <= year)
        result.first = it->second.first;
    it = --data.end();
    while ((it->first > year || it->second.second.empty()) && it != stop)
        it--;
    if ((it != stop || !it->second.second.empty()) && it->first <= year)
        result.second = it->second.second;
    return result;
}

class Person {
public:
    void ChangeFirstName(int year, const string &first_name) {
        data[year].first = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        data[year].second = last_name;
    }

    string GetFullName(int year) {
        if (data.size() == 0)
            return "ERROR";
        pair<string, string> result = GetNameSurname(data, year);
        if (result.first.empty() && result.second.empty())
            return "Incognito";
        if (!result.first.empty() && !result.second.empty())
            return result.first + ' ' + result.second;
        if (!result.first.empty())
            return result.first + " with unknown last name";
        return result.second + " with unknown first name";
    }

private:
    map<int, pair<string, string>> data;
};

int main() {
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
}