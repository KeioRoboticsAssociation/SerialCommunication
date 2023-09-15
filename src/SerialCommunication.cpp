#include <mbed.h>
#include "serialCommunication.hpp"
#include <chrono>
#include <cstdarg>
#include <cstdio>

using namespace std;



SerialCommunication::SerialCommunication(int speed, PinName tx, PinName rx): serialPort(tx, rx) {
    length = 0;
    func = [](char* comment) {return;};
    serialPort.baud(speed);
    
    serialPort.format(
        /* bits */ 8,
        /* parity */ SerialBase::None,
        /* stop bit */ 1
    );
    
    #if 1
    serialPort.attach([this]() {readChar();});
    #endif
}

int SerialCommunication::printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int l = vprintf(format, args);
    va_end(args);
    serialPort.write(format, l);
    return l;
}


void SerialCommunication::readChar() {
    char copied_str[64];
    char c;

    serialPort.read(&c, 1);
    str[length] = c;

    length++;

    if(c == '\n'){
        str[length] = '\0';
        length = 0;
        strcpy(copied_str, str);
        func(copied_str);
    }
}


void SerialCommunication::attach(function<void(char*)> f) {
    //受信時に割り込みで実行される関数を設定
    func = f;
}


void SerialCommunication::detach(){
    func = [](char* comment) {return;};
}


