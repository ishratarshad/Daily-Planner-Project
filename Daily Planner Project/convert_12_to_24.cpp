//Author: Ishrat Arshad
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: project 1B
 
// This program obtains the time in 12-hour notation and prints out the corresponding 24-hour notation

#include <iostream>
#include <string>
using namespace std;

// obtains time in 12 hour notation from user.
int main () {
    cout << "Enter time (hh:mm) in 12-hour notation (for example, 12:56 AM): ";
    string time;
    getline(cin, time);

// extract the AM/PM part
    string ampm = time.substr(time.length() - 2);

// extract the colon (:) 
    int colonIndex = time.find(":");
    
    string hourS = time.substr(0, colonIndex);
    string minS = time.substr(colonIndex+1);

    int hour = stoi(hourS);
    int min = stoi(minS);

// ensures format is valid
    if (hour < 1 || hour > 12 || min < 0 || min > 59) {
        cout << "invalid format" << endl;
        return -1;
    }

// converts time entered to 24-hour notation
    if (ampm == "AM" && hour == 12) {
        hour = 0;
    } else if (ampm == "PM" && hour != 12) {
        hour += 12;
    }

 // output statement   
    cout << "12-hour notation " << time << " in 24-hour notation is ";
    
   if (hour < 10) {
        cout << "0" << hour;
    } else {
        cout << hour;
    }

    cout << ":";

    if (min < 10) {
        cout << "0" << min;
    } else {
        cout << min;
    }

    cout << endl;

return 0;
}

