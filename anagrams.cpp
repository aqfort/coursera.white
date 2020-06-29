#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> CharCounter(const string& word) { //returns amount of each symbol of the word
    map<char, int> result;
    for (const auto& temp : word) {
        result[temp]++;
    }
    return result;
}

//enter quantity of pairs of words and then these words
//for each pair of words programm will print
//is these words are anagrams

int main() {
    int N(0);
    string word1, word2;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> word1 >> word2;
        if (CharCounter(word1) == CharCounter(word2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}