#ifndef _DATETIME_H_
#define _DATETIME_H_

#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>

class dateTime {
  public:
    dateTime();
    dateTime(std::string mes, int dia, int horas, int minutos, int segundos);
    time_t getDate();
    bool operator ==(const dateTime&);
    bool operator !=(const dateTime&);
    bool operator >(const dateTime&);
    bool operator <(const dateTime&);
    bool operator >=(const dateTime&);
    bool operator <=(const dateTime&);
    
  
  private:
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    struct tm dateStruct;
    time_t date;

};

dateTime::dateTime(){
}

dateTime::dateTime(std::string mes, int dia, int horas, int minutos, int segundos) {
  dateStruct.tm_sec = segundos;
  dateStruct.tm_min = minutos;
  dateStruct.tm_hour = horas;
  dateStruct.tm_mday = dia;
  dateStruct.tm_isdst = 0;
  for (int i=0; i < meses.size(); i++) {
    if (meses[i]==mes)
      dateStruct.tm_mon = i;
  }
  dateStruct.tm_year = 2021 - 1900;
  date = mktime(&dateStruct);
}

time_t dateTime::getDate() {
  return date;
}

bool dateTime::operator==(const dateTime &other) {
  return this->date == other.date;
}

bool dateTime::operator!=(const dateTime &other) {
  return this->date != other.date;
}

bool dateTime::operator>(const dateTime &other) {
  return this->date > other.date;
}

bool dateTime::operator<(const dateTime &other) {
  return this->date < other.date;
}

bool dateTime::operator>=(const dateTime &other) {
  return this->date >= other.date;
}

bool dateTime::operator<=(const dateTime &other) {
  return this->date <= other.date;
}

#endif // _DATETIME_H_