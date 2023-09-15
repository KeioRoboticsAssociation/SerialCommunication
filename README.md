# SerialCommunication

シリアル通信用のクラスです．動作未検証の部分があります．

使い方
```cpp
#include "SerialCommunication.hpp"

//初期化
//ボーレート，TXピン，RXピンを順に設定
SerialCommunication serial(baud_rate, tx_pin, rx_pin);

//受信割り込み
//1行ごとに割り込みで処理を実行
//funcはchar*を引数にもつ
serial.attach(func);

//出力
serial.printf("hello %d\n", 123)
```