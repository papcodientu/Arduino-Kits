int lightPin = 0;  // chân cắm của quang trở
int ledPin=11;     // chân cắm của đèn LED

void setup()
{
    Serial.begin(9600);  // xuất giá trị ra port 9600 
    pinMode( ledPin, OUTPUT );    //đăng ký điều khiển đèn LED ở cổng số 13
}

void loop()
{
    Serial.println(analogRead(lightPin));     // In giá trị của quang trở để dễ theo dõi 
                                                            // Giá trị tối đa là 1024
  // chia cho 5,5 có vẻ tốt hơn :-?
  analogWrite(ledPin,(analogRead(lightPin)   ) /5.5   );  
  // Đọc số ở quang trở, chia cho 5,5 ; sau đó gửi giá trị vào cổng đèn LED.
  delay(100);
  //tạm dừng mỗi 0,1 giây; sau đó chạy lại vòng lặp.
}
