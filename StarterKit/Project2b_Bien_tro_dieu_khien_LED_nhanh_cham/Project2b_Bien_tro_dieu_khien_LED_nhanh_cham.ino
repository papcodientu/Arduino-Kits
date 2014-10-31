/*
  Tác giả:Nguyễn Vương Tùng
  Ngày:22/09/2014
  Mạch Điều khiển đèn LED bằng biến trở
 */
int bientro = 2;    // khai báo cổng 2 sẽ là cổng biến trở 
int led = 13;   // khai báo cổng 13 là cổng của đèn LED
int val = 0;       // khai báo già trị nhận được từ biến trở

void setup() {
  pinMode(led, OUTPUT);  // cài đặt cổng led là output
}

void loop() {
  val = analogRead(bientro);    // đọc giá trị của biến trở, bỏ vô val
  digitalWrite(led, HIGH);  // bật đèn led
  delay(val);                  // dừng 1 khoảng thời gian, dựa theo giá trị của biến trở
  digitalWrite(led, LOW);   // tắt đèn led
  delay(val); // như vậy đèn led sẽ được bật tắt liên tục và độ bật tắt nhanh chậm sẽ dựa vào giá trị //của biến trở 
}
