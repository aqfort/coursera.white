#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() { //another useless program
    int number, temp;
    string temp_string;
    set<string> temp_set;
    map<set<string>, int> data;
    cin >> number;
    for (int iterator = 0; iterator < number; ++iterator) {
        cin >> temp;
        for (int i = 0; i < temp; ++i) {
            cin >> temp_string;
            temp_set.insert(temp_string);
        }
        temp = data.size() + 1;
        if (data.find(temp_set) != data.end())
            cout << "Already exists for " << data[temp_set] << endl;
        else {
            data[temp_set] = temp;
            cout << "New bus " << temp << endl;
        }
        temp_set.clear();
    }
    return 0;
}