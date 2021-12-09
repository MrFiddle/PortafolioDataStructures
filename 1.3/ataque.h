#ifndef ATAQUE_H
#define ATAQUE_H

#include <iostream>
#include <vector>
#include <ctime>

class Ataque {
    public:
        Ataque();
        Ataque(std::string month, int day, int hours, int minutes, int seconds);
        time_t getDate();
        bool operator == (const Ataque&);
        bool operator !=(const Ataque&);
        bool operator >(const Ataque&);
        bool operator <(const Ataque&);
        bool operator <=(const Ataque&);
    private:
        // Months
        std::vector<std::string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        // Date-time struct
        struct tm dateTimeStruct;
        // Unix timestamp
        time_t date;
        
};

Ataque::Ataque() {
    std::string month = "Jan";
    dateTimeStruct.tm_sec = 0;
    dateTimeStruct.tm_min = 0;
    dateTimeStruct.tm_hour = 0;
    dateTimeStruct.tm_mday = 0;
    for (int i = 0; i < months.size(); i++) {
        dateTimeStruct.tm_mon = i;
    }
    dateTimeStruct.tm_year = 2021 - 1900;
    date = mktime(&dateTimeStruct);
}

Ataque::Ataque(std::string month, int day, int hours, int minutes, int seconds) {
    dateTimeStruct.tm_sec = seconds;
    dateTimeStruct.tm_min = minutes;
    dateTimeStruct.tm_hour = hours;
    dateTimeStruct.tm_mday = day;
    for (int i = 0; i < months.size(); i++) {
        if (months[i] == month) {
            dateTimeStruct.tm_mon = i;
        }
    }
    dateTimeStruct.tm_year = 2021 - 1900;
    date = mktime(&dateTimeStruct);
}

time_t Ataque::getDate() {
  return date;
}

bool Ataque::operator==(const Ataque &value) {
  return this->date == value.date;
}

bool Ataque::operator!=(const Ataque &value) {
  return this->date != value.date;
}

bool Ataque::operator>(const Ataque &value) {
  return this->date > value.date;
}

bool Ataque::operator<(const Ataque &value) {
  return this->date < value.date;
}

bool Ataque::operator<=(const Ataque &value) {
  return this->date <= value.date;
}

#endif