#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//add bus rout with name "bus" and "stop_count" (amount) stops with the names "stop1", "stop2", ...
void NEW_BUS(map<string, vector<string>>& buses, map<string, vector<string>>& stops);
//print names of all bus routes passing through the certain stop
void BUSES_FOR_STOP(map<string, vector<string>>& stops);
//print names of all stops of the certain bus root with list of buses you can interchange in each of stops
void STOPS_FOR_BUS(map<string, vector<string>>& buses, map<string, vector<string>>& stops);
//print list of all bus roots with stops
void ALL_BUSES(map<string, vector<string>>& buses);

int main() {
    int number;
    string command;
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;

    cin >> number; //amount of commands
    for (int item = 0; item < number; ++item) {
        cin >> command;
        if (command == "NEW_BUS")
            NEW_BUS(buses, stops);
        else if (command == "BUSES_FOR_STOP")
            BUSES_FOR_STOP(stops);
        else if (command == "STOPS_FOR_BUS")
            STOPS_FOR_BUS(buses, stops);
        else
            ALL_BUSES(buses);
    }

    return 0;
}

void NEW_BUS(map<string, vector<string>>& buses, map<string, vector<string>>& stops) {
    int stop_count;
    string bus, temp;
    cin >> bus >> stop_count; //scans bus root name, amount of stops
    for (int item = 0; item < stop_count; ++item) {
        cin >> temp; //scans stop name
        buses[bus].push_back(temp);
        stops[temp].push_back(bus);
    }
}

void BUSES_FOR_STOP(map<string, vector<string>>& stops) {
    string stop;
    cin >> stop; //scans bus stop
    if (stops.find(stop) == stops.end()) //the certain stop isn't found 
        cout << "No stop";
    else {
        for (const auto &item : stops[stop])
            cout << item << ' '; //prints roots containing this certain stop
    }
    cout << endl;
}

void STOPS_FOR_BUS(map<string, vector<string>>& buses, map<string, vector<string>>& stops) {
    string bus;
    cin >> bus; //scans bus root name
    if (buses.find(bus) == buses.end()) //the certain bus root isn't found
        cout << "No bus" << endl;
    else {
        for (const auto& stop : buses[bus]) { //prints each stop name for the certain bus root
            cout << "Stop " << stop << ":";
            if (stops[stop].size() == 1)
                cout << " no interchange" << endl;
            else {
                for (const auto& ich_bus : stops[stop]) { //prints interchanging buses for each stop
                    if (ich_bus != bus)
                        cout << ' ' << ich_bus;
                }
                cout << endl;
            }
        }
    }
}

void ALL_BUSES(map<string, vector<string>>& buses) {
    if (buses.empty())
        cout << "No buses" << endl;
    else {
        for (const auto& bus : buses) { //prints each bus root
            cout << "Bus " << bus.first << ":";
            for (const auto& stop : bus.second) //prints all stops for each root
                cout << ' ' << stop;
            cout << endl;
        }
    }
}
