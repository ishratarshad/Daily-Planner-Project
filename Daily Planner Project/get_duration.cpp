// Author: Ishrat Arshad
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: project 1C
 
// This program calculateS duration of two time in 24-hour time notations

//library
#include <iostream>
#include <string>
using namespace std;

// gets start time
int main () {
    cout << "Enter start time (hh:mm) in 24-hour notation (for example, 12:56): ";
    string start;
    cin >> start;

    int colonIndex = start.find(":");
    
    string starthourS = start.substr(0, colonIndex);
    string startminS = start.substr(colonIndex+1);

    int starthour = stoi(starthourS);
    int startmin = stoi(startminS);

// gets end time
    cout << "Enter end time (hh:mm) in 24-hour notation (for example, 12:56): ";
    string end;
    cin >> end;
    int colonIndexEnd = end.find(":");
    
    string endhourS = end.substr(0, colonIndexEnd);
    string endminS = end.substr(colonIndexEnd + 1);

    int endhour = stoi(endhourS);
    int endmin = stoi(endminS);


// Checks start time is later than end time
    if (starthour > endhour || (starthour == endhour && startmin > endmin)) {
        cout << "invalid input" << endl;
        return -1;
    }

    // Calculate duration
    int totalStartMinutes = starthour * 60 + startmin;
    int totalEndMinutes = endhour * 60 + endmin;

    int durationMinutes = totalEndMinutes - totalStartMinutes;

    int hours = durationMinutes / 60;
    int minutes = durationMinutes % 60;

    // Output the duration
    cout << "The duration is " << hours << " hours and " << minutes << " minutes." << endl;

    return 0;
}
