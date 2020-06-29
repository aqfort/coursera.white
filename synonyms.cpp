#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

void ADD(map<string, set<string>> &data, const string word1, const string word2);

unsigned int COUNT(map<string, set<string>> &data, const string word1);

bool CHECK(map<string, set<string>> &data, const string word1, const string word2);

int main() {
    int number;
    string word1, word2, temp_string;
    map<string, set<string>> data;

    cin >> number;
    for (int iterator = 0; iterator < number; ++iterator) {
        cin >> temp_string;
        if (temp_string == "ADD") {
            cin >> word1 >> word2;
            ADD(data, word1, word2);
        } else if (temp_string == "COUNT") {
            cin >> word1;
            cout << COUNT(data, word1) << endl;
        } else {
            cin >> word1 >> word2;
            if (CHECK(data, word1, word2))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}

void ADD(map<string, set<string>> &data, const string word1, const string word2) {
    data[word1].insert(word2);
    data[word2].insert(word1);
}

unsigned int COUNT(map<string, set<string>> &data, const string word1) {
    return data[word1].size();
}

bool CHECK(map<string, set<string>> &data, const string word1, const string word2) {
    return static_cast<bool> (data[word1].count(word2));
}