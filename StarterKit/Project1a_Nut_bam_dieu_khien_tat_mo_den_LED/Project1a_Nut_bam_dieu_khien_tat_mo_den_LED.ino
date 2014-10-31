/*
Mạch bật tất đèn LED bằng nút bấm dùng Arduino

Linh kiện:
- Nút bấm 4 chân
- Đèn LED
- Điện trở 220 Ohm
- Arduino Uno

Cách lắp mạch:
- Cực dương LED nối vào cổng 2 trên board Arduino, 
cực âm LED nối vào cổng Ground
- Cực 1 hoặc 2 nút bấm nối vào cổng 8 trên board Arduino, 
cực 3 hoặc 4 nút bấm nối vào cổng Ground

Tác giả: Nhân Nguyễn
Ngày: 06/09/2014
Website: http://papcodientu.com/
*/

const int nutBam = 8;
const int denLED = 2;

int trangthaiNutBam = 0;

void setup() {
  // Khai báo các cổng trên board Arduino
  pinMode(denLED, OUTPUT);  // Đèn LED là thiết bị đầu ra (output)
  pinMode(nutBam, INPUT);   // Nút bấm là thiết bị đầu vào (input)
  
  // Thiet lap trang thai ban dau led va nut bam
  digitalWrite(denLED, LOW);
  digitalWrite(nutBam, HIGH);
}

void loop() {
  // Kiểm tra trạng thái nút bấm
  trangthaiNutBam = digitalRead(nutBam);
  
  if (trangthaiNutBam == LOW) {  // nút đã được bấm
    digitalWrite(denLED, HIGH);  // bật đèn sáng
  } else {                       // nút không được bấm
    digitalWrite(denLED, LOW);   // tắt đèn
  }
}
