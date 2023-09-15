#include <mbed.h>
#include "SerialCommunication.hpp"

SerialCommunication serial;

bool flag = false;
int result;

void calculate(char* message){
    int a;
    int b;
    int N = sscanf(message, "%d+%d\n", &a, &b);
    if(N == 2){
        flag = true;
        result = a + b;
    }
}


int main(){
    serial.attach(calculate);
    while(1){
        if(flag){
            flag = false;
            printf("%d\n", result);
        }
        wait_ns(1);
    }
}