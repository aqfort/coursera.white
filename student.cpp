#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#define ERROR "bad request"
#define PATH "input.txt"

using namespace std;

//3
//Ivan Ivanov 1 1 1901
//Petr Petrov 2 2 1902
//Alexander Sidorov 3 3 1903
//3
//name 1
//date 3
//mark 5

class Student {
public:
    void Add() {
        cin >> name >> surname >> day >> month >> year;
    }

    void AddFromFile(ifstream &input) {
        input >> name >> surname >> day >> month >> year;
    }

    string Name() const {
        return name + ' ' + surname;
    }

    string Date() const {
        return to_string(day) + '.' + to_string(month) + '.' + to_string(year);
    }

private:
    string name;
    string surname;
    unsigned int day{};
    unsigned int month{};
    unsigned int year{};
};

int main() {
    int N{}, M{};
    vector<Student> data{};

    /*ifstream input(PATH);

    if (input) {
        input >> N;
        for (unsigned int i = 0; i < N; ++i) {
            data.emplace_back();
            data.back().AddFromFile(input);
        }
        input >> M;
        string command{};
        int temp{};
        for (int j = 0; j < M; ++j) {
            input >> command >> temp;
            if (temp < 1 && temp > N)
                cout << ERROR << endl;
            else if (command == "name")
                cout << data[temp - 1].Name() << endl;
            else if (command == "date")
                cout << data[temp - 1].Date() << endl;
            else
                cout << ERROR << endl;
        }
    }*/

    cin >> N;
    if (N > 0) {
        for (unsigned int i = 0; i < N; ++i) {
            data.emplace_back();
            data.back().Add();
        }
    }
    cin >> M;
    if (M > 0) {
        string command{};
        int temp{};
        for (int j = 0; j < M; ++j) {
            cin >> command >> temp;
            if (temp < 1 || temp > N)
                cout << ERROR << endl;
            else if (command == "name")
                cout << data[temp - 1].Name() << endl;
            else if (command == "date")
                cout << data[temp - 1].Date() << endl;
            else
                cout << ERROR << endl;
        }
    }

    return 0;
}