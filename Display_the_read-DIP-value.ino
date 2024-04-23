// 定義 DIP 開關的引腳
const int DIP[] = {30, 31, 32, 33};
// 定義每個 DIP 開關對應的二進制權重
const byte Weight[] = {8, 4, 2, 1};
// 定義七段顯示器的引腳陣列（對應到 A~G）
int seg7[] = {22, 23, 24, 25, 26, 27, 28, 29};
// 定義共陰七段顯示器的編碼表
char TAB[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x03, 0x78, 0x00, 0x18, 0x08, 0x03, 0x46, 0x21, 0x06, 0x0E};
int ii; // 迴圈計數器
int number; // 存儲 DIP 開關轉換的數字

void setup() {
  // 設置七段顯示器的引腳為輸出
  for (ii = 0; ii < 7; ii++) {
    pinMode(seg7[ii], OUTPUT);
  }
  // 設置 DIP 開關的引腳為輸入
  for (ii = 0; ii < 4; ii++) {
    pinMode(DIP[ii], INPUT);
  }
}

void loop() {
  number = 0; // 初始化數字變數
  // 讀取 DIP 開關的狀態，計算數字值
  for (ii = 0; ii < 4; ii++) {
    if (digitalRead(DIP[ii]) == HIGH)
      number += Weight[ii];
  }
  // 將數字值轉換為對應的七段顯示器編碼並顯示
  OutPort(TAB[number]);
}

// 將七段顯示器編碼寫入七段顯示器的函式
void OutPort(byte dat) {
  // 將七段顯示器編碼的每個位元寫入對應的引腳
  for (int jj = 0; jj < 7; jj++) {
    digitalWrite(seg7[jj], dat % 2);
    dat = dat >> 1;
  }
}
