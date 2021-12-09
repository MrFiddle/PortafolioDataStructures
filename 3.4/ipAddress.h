#ifndef _IPADDRESS_H_
#define _IPADDRESS_H_

#include <iostream>
#include <stdio.h>
#include <math.h>

class ipAddress {
    public:

        ipAddress();
        ipAddress(std::string);
        std::string getIp();
        std::string getIpNoPort();
        std::string getIpYCantidad();
        int getIpByte(int index);
        long int getValor();
        int getCantidad();
        void sumarCantidad();
        bool operator ==(ipAddress);
        bool operator !=(ipAddress);
        bool operator >(ipAddress);
        bool operator <(ipAddress);
        bool operator >=(ipAddress);
        bool operator <=(ipAddress);

    private:

        int cantidad;
        long int valor;
        int ip[4];
        std::string ipString;
        std::string ipNoPort;
        

};

ipAddress::ipAddress() {

    ipString = "0.0.0.0:0000";
    ipNoPort = "0.0.0.0";
    cantidad = 0;

    ip[0] = 0;
    ip[1] = 0;
    ip[2] = 0;
    ip[3] = 0;

}

ipAddress::ipAddress(std::string _ip) {

    ipString = _ip;
    cantidad = 0;

    int pos1 = ipString.find(":");
    ipNoPort = ipString.substr(0, pos1);

    std::string temporal = ipNoPort;

    for (int i = 0; i < 4; i++) {

        int separador = ipNoPort.find(".");
        std::string temp = ipNoPort.substr(0, separador);
        ip[i] = std::stoi(temp);

        temp = ipNoPort.substr(0, separador + 1);
        ipNoPort = ipNoPort.substr(temp.length(), ipNoPort.length());

    }

    ipNoPort = temporal;

    valor = ip[0]*std::pow(256,3) + 
        ip[1]*std::pow(256,2) +
        ip[2]*std::pow(256,1) +
        ip[3]*std::pow(256,0);

}

std::string ipAddress::getIp() {

    return ipString;

}

std::string ipAddress::getIpNoPort() {

    return ipNoPort;

}

std::string ipAddress::getIpYCantidad() {

    // std::string ipcantidad = ipNoPort + " - " + std::to_string(cantidad);
    return std::to_string(cantidad);

}

int ipAddress::getCantidad() {

    return cantidad;

}

void ipAddress::sumarCantidad() {

    cantidad = cantidad + 1;

}

long int ipAddress::getValor() {

    return valor;

}

int ipAddress::getIpByte(int index) {

    return ip[index];

}

bool ipAddress::operator == (ipAddress other) {
  
    if (ipString == other.getIp()) {

        return true;

    } else {

        return false;

    }

}

bool ipAddress::operator != (ipAddress other) {
  
    if (ipString != other.getIp()) {
        
        return true;

    } else {

        return false;

    }

}

bool ipAddress::operator > (ipAddress other) {

    for (int i = 0; i < 4; i++) {

        if (ip[i] == other.getIpByte(i)) {

            continue;

        } else if (ip[i] > other.getIpByte(i)) {

            return true;

        } else if (ip[i] == other.getIpByte(i) && i == 3) {

            return false;

        } else {

            return false;

        }

    // if (valor > other.getValor()) {

    //     return true;
 
    // } else {

    //     return false;

    // }

    }
}

bool ipAddress::operator<( ipAddress other) {

    for (int i = 0; i < 4; i++) {

        if (ip[i] == other.getIpByte(i)) {

            continue;

        } else if (ip[i] < other.getIpByte(i)) {

            return true;

        } else if (ip[i] == other.getIpByte(i) && i == 3) {

            return false;

        } else {

            return false;
            
        }

    }

    // if (valor < other.getValor()) {

    //     return true;

    // } else {

    //     return false;

    // }

}

bool ipAddress::operator>=( ipAddress other) {

    //     if (ipString == other.getIp()) {
    //         return true;
    //     }
        
    //     for (int i = 0; i < 4; i++) {

    //     if (ip[i] == other.getIpByte(i)) {

    //         continue;

    //     } else if (ip[i] > other.getIpByte(i)) {

    //         return true;

    //     } else if (ip[i] == other.getIpByte(i) && i == 3) {

    //         return false;

    //     } else {

    //         return false;
            
    //     }


    // }

    if (valor >= other.getValor()) {

        return true;

    } else {

        return false;

    }

}

bool ipAddress::operator<=( ipAddress other) {
  
    // if (ipString == other.getIp()) {
    //     return true;
    // }

    // for (int i = 0; i < 4; i++) {

    //     if (ip[i] == other.getIpByte(i)) {

    //         continue;

    //     } else if (ip[i] < other.getIpByte(i)) {

    //         return true;

    //     } else if (ip[i] == other.getIpByte(i) && i == 3) {

    //         return false;

    //     } else {

    //         return false;
            
    //     }


    // }

    if (valor <= other.getValor()) {

        return true;

    } else {

        return false;

    }

}



#endif // _IPADDRESS_H_