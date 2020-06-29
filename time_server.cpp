#include <iostream>
#include <exception>
#include <string>
using namespace std;

/*string AskTimeServer() {
    return "23:59:59";
}*/

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            LastFetchedTime = AskTimeServer();
        } catch (const system_error &) { //catch here only system_error, other exeptions go through
            //return LastFetchedTime; //useless line
        }
        return LastFetchedTime;
    }
private:
    string LastFetchedTime = "00:00:00";
};

/*int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception &e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}*/