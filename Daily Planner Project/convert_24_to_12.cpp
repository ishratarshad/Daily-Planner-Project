//Author: Ishrat Arshad
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: project 1A
 
// This program obtains the relation between 24-hour notation and 12-hour notation is shown in the following table. Let mm be minutes.

//library
#include <iostream>
#include <string>
using namespace std;

// This prompts the user to enter a time in 24-hour notation and stores it into a string variable
int main () {
    cout << "Enter time (hh:mm) in 24-hour notation (for example, 12:56): ";
    string time;
    cin >> time;

    int colonIndex = time.find(":");
    
    string hourS = time.substr(0, colonIndex);
    string minS = time.substr(colonIndex+1);


// Uses the stoi function to convert a string to the corresponding integers
    int hour = stoi(hourS);
    int min = stoi(minS);

// Ensures that the user enters a valid input where the is not hour < 0 or hour > 23) or minute is not minute < 0 or minute > 59
    if (hour < 0 || hour > 23 || min < 0 || min > 59) {
        cout << "invalid input" << endl;
        return -1;
    }

    string ampm;
    if (hour >= 12) {
        ampm = "PM";
    } else {
        ampm = "AM";
    }


    if (hour == 0) {
        hour = 12;
    } else if (hour > 12) {
        hour -= 12;
    }

    cout << "24-hour notation " << time << " in 12-hour notation is " << hour << ":" << min << " " << ampm << endl;

return 0;
}


