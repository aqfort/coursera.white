#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void NEXT(const vector<int>& month_days, vector<vector<string>>& data, int& month, const int& months_count) {
    int next_month = (month + 1) % months_count;
    if (month_days[month] < month_days[next_month]) {
        //data.resize(month_days[next_month], vector<string>(0)); //not correct
        for (int i = month_days[month] - 1; i < month_days[next_month]; i++) {
            //data.push_back(vector<string>()); //same shit???
            data.emplace_back();
            data[i + 1].clear();
        }
    } else if (month_days[month] > month_days[next_month]) {
        for (int i = month_days[next_month]; i < month_days[month]; i++) {
            data[month_days[next_month] - 1].insert(end(data[month_days[next_month] - 1]), begin(data[i]), end(data[i]));
        }
    }
    month = next_month;
}

void PRINT(const vector<vector<string>>& data, const int& day) {
    cout << data[day].size() << ' ';
    for (const auto &temp : data[day])
        cout << temp << ' ';
    cout << endl;
}

//number -- quantity of commands
//day -- the day which we view [1,... -> [0,...
//month -- current month [0,...
//command -- command name

int main() {
    int number, day, month = 0;
    string command;
    const vector<int> month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //[1,...
    const int months_count = month_days.size();
    vector<vector<string>> data(month_days[month]);

    cin >> number;
    for (int i = 0; i < number; ++i) {
        cin >> command;
        if (command == "ADD") {
            cin >> day >> command;
            day--;
            data[day].push_back(command);
        } else if (command == "NEXT") {
            NEXT(month_days, data, month, months_count);
        } else {
            cin >> day;
            day--;
            PRINT(data, day);
        }
    }

    return 0;
}
