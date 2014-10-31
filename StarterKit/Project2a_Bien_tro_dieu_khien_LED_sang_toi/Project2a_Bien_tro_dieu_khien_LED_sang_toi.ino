/*
  Tác giả:Nguyễn Vương Tùng
  Ngày:21/09/2014
  Mạch Điều khiển đèn LED bằng biến trở
 */
//khai báo cổng đèn LED
int led = 13;
// cài đặt
void setup() {                
  // cài đặt cổng led làcổng output
  pinMode(led, OUTPUT);     
}
// vòng lặp
void loop() {
  //bật cho đèn sáng
  digitalWrite(led, HIGH);
}

