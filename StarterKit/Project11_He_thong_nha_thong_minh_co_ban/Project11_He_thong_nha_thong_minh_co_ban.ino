/*
Hệ thống nhà thông minh cơ bản dùng Arduino

Linh kiện:
- Nút bấm 4 chân
- Đèn LED RGB
- Điện trở 220 Ohm, 10K Ohm
- Quang trở
- Còi
- Cảm biến nhiệt độ
- Cảm biến chuyển động
- Arduino Uno

Cách lắp mạch:
- Xem hình

Tác giả: Nhân Nguyễn
Ngày: 13/01/2015
Lịch sử thay đổi
- 13/01/2015 Rev. 1.1 Upgraded
- 04/11/2014 Rev. 1.0 Added button debounce
- 06/09/2014 Rev. 0.1 Draft, no button debounce
Website: http://papcodientu.com/
*/

// thư viện DHT - https://github.com/RobTillaart/Arduino
#include <dht.h>

// khai báo biến DHT
dht DHT;

// Các thiết bị đầu vào
const int nutBam = 0;    // nut bam noi vao pin 2 cua Arduino
const int denledDo1 = 2;  // đèn LED điều khiển bởi nút bấm
const int denledXanhLaCay1 = 1;
const int quangTro = A5;  // Quang trở cảm biến ánh sáng
const int cambienNhietDo = 7;  // Cảm biến nhiệt độ và độ ẩm DHT11
const int cambienChuyenDong = 8;  // Cảm biến chuyển động PIR

// Các thiết bị đầu ra
const int coi = 3;
const int denledDo2 = 11;
const int denXanhLaCay2 = 10;
const int denXanhNuocBien2 = 9;

int trangthaidenLED = LOW;  // trang thai den LED hien tai
int trangthaiNutBam;    // trang thai nut bam hien tai
int trangthainutbamTruoc = LOW;   // trang thai nut bam truoc do

long thoidiemDebounceTruoc = 0;  // thoi diem nut bam chuyen doi trang thai
long dotreDebounce = 50;   // do tre cua moi lan debounce

void setup() {
  // Khai báo các cổng trên board Arduino
  pinMode(denLED, OUTPUT);  // Đèn LED là thiết bị đầu ra (output)
  pinMode(nutBam, INPUT);   // Nút bấm là thiết bị đầu vào (input)
  
  // Thiet lap trang thai ban dau led va nut bam
  digitalWrite(denLED, trangthaidenLED);
}

void loop() {
  int giatriNutBam = digitalRead(nutBam);  // doc gia tri cua nut bam
  
  // Neu trang thai nut bam thay doi, do viec bi nhieu hoac duoc nhan
  if (giatriNutBam != trangthainutbamTruoc) {
    // reset thoi diem debounce
    thoidiemDebounceTruoc = millis(); 
  }
  
  // nut bam duoc giu lau hon dotreDebounce, nut bam that su duoc nhan
  if ((millis() - thoidiemDebounceTruoc) > dotreDebounce) {
    // trang thai nut bam da thay doi
    if (giatriNutBam != trangthaiNutBam) {
      // thay doi trang thai nut bam bang gia tri hien tai
      trangthaiNutBam = giatriNutBam;
     
      // nut bam da duoc nhan
      if (trangthaiNutBam == HIGH) {
        // thay doi trang thai den LED
        trangthaidenLED = !trangthaidenLED;  
      }
    }
  }
  
  // xuat gia trang thai den LED
  digitalWrite(denLED, trangthaidenLED);
  
  // ghi lai gia tri nut bam
  trangthainutbamTruoc = giatriNutBam;
}
