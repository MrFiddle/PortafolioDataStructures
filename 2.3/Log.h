#ifndef _LOG_H_
#define _LOG_H_

#include "dateTime.h"

#include <iostream>

class Log{
    private:
    
        dateTime date;
        std::string mes;
        std::string dia;
        std::string hora;
        std::string minuto;
        std::string segundo;
        std::string ip;
        std::string descripcion;


    public:
        Log();
        Log(std::string m, std::string d, std::string h, std::string mi, std::string s, std::string ipa, std::string desc, dateTime date);
        dateTime getDate();
        std::string getAll();

};

Log::Log(){
  mes = "";
  dia = "";
  hora = "";
  minuto = "";
  segundo = "";
  ip = "";
  descripcion = "";
}

Log::Log(std::string m, std::string d, std::string h, std::string min, std::string s, std::string _ip, std::string desc, dateTime dt){
  mes = m;
  dia = d;
  hora = h;
  minuto = min;
  segundo = s;
  ip = _ip;
  descripcion = desc;
  date = dt;
}

 dateTime Log::getDate(){
    return date;
}

std::string Log::getAll(){
    return mes + " " + dia + " " + hora + ":" + minuto + ":" + segundo + " " + ip + " " + descripcion + "\0";
}

#endif // _LOG_H_