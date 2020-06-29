#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() { //useless program
    int number, temp;
    string temp_string;
    vector<string> temp_vector;
    map<vector<string>, int> data;
    cin >> number;
    for (int iterator = 0; iterator < number; ++iterator) {
        cin >> temp;
        for (int i = 0; i < temp; ++i) {
            cin >> temp_string;
            temp_vector.push_back(temp_string);
        }
        temp = data.size() + 1;
        if (data.find(temp_vector) != data.end())
            cout << "Already exists for " << data[temp_vector] << endl;
        else {
            data[temp_vector] = temp;
            cout << "New bus " << temp << endl;
        }
        temp_vector.clear();
    }
    return 0;
}