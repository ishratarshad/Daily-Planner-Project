// Author: Ishrat Arshad
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: project 1D

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void hours_minutes_in_24h(string str, int& hours, int& minutes) {
    string ampm = str.substr(str.length() - 2);  
    int colonIndex = str.find(":"); 
    string hourS = str.substr(0, colonIndex);  
    string minS = str.substr(colonIndex + 1, 2);  

    hours = stoi(hourS);  
    minutes = stoi(minS);  

    if (hours < 1 || hours > 12 || minutes < 0 || minutes > 59) {
        cout << "Invalid time format in string: " << str << endl;
        return;
    }

    if (ampm == "am" && hours == 12) {
        hours = 0;  
    } else if (ampm == "pm" && hours != 12) {
        hours += 12;  
    }
}


int duration(string str) {
    size_t dash_pos = str.find('-');
    string start_time = str.substr(0, dash_pos);  
    string end_time = str.substr(dash_pos + 1);   

    int start_hours, start_minutes;
    int end_hours, end_minutes;

    hours_minutes_in_24h(start_time, start_hours, start_minutes);
    hours_minutes_in_24h(end_time, end_hours, end_minutes);

    int start_total_minutes = start_hours * 60 + start_minutes;
    int end_total_minutes = end_hours * 60 + end_minutes;

    if (end_total_minutes < start_total_minutes) {
        end_total_minutes += 24 * 60;  
    }

    return end_total_minutes - start_total_minutes;
}


int main() {
    string file_name, search_priority;
    
    cout << "Enter a file name: ";
    cin >> file_name;
    cout << "Enter priority: ";
    cin >> search_priority;

    ifstream fin(file_name);

    if (fin.fail()) {
        cout << "Error opening file!" << endl;
        return -1;
    }

    string line, time, activity, priority;
    int total_duration = 0;

    getline(fin, line);  

    while (getline(fin, time, ',')) {
        getline(fin, activity, ',');
        getline(fin, priority);

        if (priority == search_priority) {
            int task_duration = duration(time);
            if (task_duration >= 0) {
                cout << time << ", " << activity << ", " << task_duration / 60 << " hours and " << task_duration % 60 << " minutes" << endl;
                total_duration += task_duration;
            }
        }
    }

    cout << "Total duration: " << total_duration / 60 << " hours and " << total_duration % 60 << " minutes" << endl;

    fin.close();
    
    return 0;
}
