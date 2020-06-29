#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//input.txt
//2 3
//1,2,3
//4,5,6

int main() {
    int N(0), M(0), temp(0);
    ifstream input("input.txt");
    if (input) {
        input >> N >> M;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                input >> temp;
                input.ignore(1);
                cout << setw(10) << temp;
                if (j == M - 1)
                    cout << endl;
                else
                    cout << ' ';
            }
        }
    }
    return 0;
}
