#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPalindrom(const string &word) {
    string word_reversed = word;
    reverse(word_reversed.begin(), word_reversed.end());
    return word_reversed == word;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> result;
    for(auto temp : words) {
        if(IsPalindrom(temp) && temp.size() >= minLength)
            result.push_back(temp);
    }
    return result;
}

int main() {
    vector<string> words = {"abacaba", "aba", "weew", "bro", "code"};
    words = PalindromFilter(words, 4);
    for(auto word : words)
        cout << word << ' ';
    return 0;
}