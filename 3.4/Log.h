#ifndef _LOG_H_
#define _LOG_H_

#include "dateTime.h"
#include "ipAddress.h"

#include <iostream>

class Log {
    private:
    
        dateTime date;
        std::string mes;
        std::string dia;
        std::string hora;
        std::string minuto;
        std::string segundo;
        ipAddress ip;
        std::string descripcion;


    public:
        Log();
        Log(std::string m, std::string d, std::string h, std::string mi, std::string s, ipAddress ipa, std::string desc, dateTime date);
        dateTime getDate();
        ipAddress getIp();
        std::string getAll();
        bool operator ==(Log);
        bool operator !=(Log);
        bool operator >(Log);
        bool operator <(Log);
        bool operator >=(Log);
        bool operator <=(Log);
        friend std::ostream& operator << (std::ostream& os, Log &c);

};

Log::Log(){
  mes = "";
  dia = "";
  hora = "";
  minuto = "";
  segundo = "";
  ip = ipAddress();
  descripcion = "";
}

Log::Log(std::string m, std::string d, std::string h, std::string min, std::string s, ipAddress _ip, std::string desc, dateTime dt){
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

ipAddress Log::getIp() {

    return ip;

}

std::string Log::getAll(){
    return mes + " " + dia + " " + hora + ":" + minuto + ":" + segundo + " " + ip.getIp() + " " + descripcion + "\0";
}

bool Log::operator == (Log other) {

    if (ip.getIpNoPort() == other.ip.getIpNoPort()) {
        
        return true;
        
    }

    return false;
    

    // if (ip.getValor() == other.ip.getValor()) {
    //     return true;
    // } else {
    //     return false;
    // }

}

bool Log::operator != (Log other) {
  
    if (ip.getIpNoPort() != other.ip.getIpNoPort()) {
        
        return true;

    } else {

        return false;

    }

    // if (ip.getValor() != other.ip.getValor()) {
    //     return true;
    // } else {
    //     return false;
    // } 


}

bool Log::operator > (Log other) {

    for (int i = 0; i < 4; i++) {

        if (ip.getIpByte(i) == other.ip.getIpByte(i)) {

            continue;

        } else if (ip.getIpByte(i) > other.ip.getIpByte(i)) {

            return true;

        } else {

            return false;

        }



    // if (ip.getValor() > other.ip.getValor()) {
    //     return true;
    // } else {
    //     return false;
    // }

    }
    
    return false;

}

bool Log::operator<( Log other) {

    for (int i = 0; i < 4; i++) {

        if (ip.getIpByte(i) == other.ip.getIpByte(i)) {

            continue;

        } else if (ip.getIpByte(i) < other.ip.getIpByte(i)) {

            return true;

        } else {

            return false;

        }
        

    }

    return false;
    // if (ip.getValor() < other.ip.getValor()) {
    //     return true;
    // } else {
    //     return false;
    // }

}

bool Log::operator>=( Log other) {

        if (ip.getIpNoPort() == other.ip.getIpNoPort()) {
            return true;
        }

        // if (ip.getValor() >= other.getIp().getValor()) {
        //     return true;
        // } else {
        //     return false;
        // }d
        
        for (int i = 0; i < 4; i++) {

            if (ip.getIpByte(i) == other.ip.getIpByte(i)) {

                continue;

            } else if (ip.getIpByte(i) > other.ip.getIpByte(i)) {

                return true;

            }

            return false;

        }
}

bool Log::operator<=( Log other) {

    // if (ip.getValor() <= other.getIp().getValor()) {
    //     return true;
    // } else {
    //     return false;
    // }

    if (ip.getIpNoPort() == other.ip.getIpNoPort()) {
        return true;
    }

    for (int i = 0; i < 4; i++) {

        if (ip.getIpByte(i) == other.ip.getIpByte(i)) {

            continue;

        } else if (ip.getIpByte(i) < other.ip.getIpByte(i)) {

            return true;

        }
        
        return false;

    }

}

std::ostream& operator << (std::ostream &out, Log &c) {

    out << c.getAll();
    return out;

}


#endif // _LOG_H_