#pragma once

#include <mbed.h>
#include <string>
#include <vector>

using namespace std;


class SerialCommunication{
    public:
        UnbufferedSerial serialPort;

        //初期化処理
        SerialCommunication(int speed=9600, PinName tx=USBTX, PinName rx=USBRX);

        //受信時に割り込みで実行する関数funcを設定
        void attach(function<void(char*)> f);

        //funcの設定をリセット
        void detach();

        //printfと同じノリで出力
        int printf(const char* format, ...);

        //前の改行から現時点で受信した文字列
        char str[64];
        unsigned int length;


    private:
        

        //受信時に割り込みで実行する関数
        function<void(char*)> func; 

        //1文字読んでstrの末尾に追加．改行なら関数funcを実行
        void readChar();
};