/*
  Tác giả:Nguyễn Vương Tùng
  Ngày:21/09/2014
  Mạch Điều khiển đèn LED đa màu
 */
int redPin =7;
int greenPin = 6;
int bluePin = 5;
int nutbam = 13;
int trangthainutbam = 0;
int trangthainutbamtruoc = LOW;
int mau = 0;

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup()
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(nutbam, INPUT);
    digitalWrite(nutbam, HIGH);
}
 
void loop()
{
    int bamnut = digitalRead(nutbam);
    if(bamnut != trangthainutbamtruoc){
        lastDebounceTime = millis();
    }
    
    if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (nutbam != trangthainutbam) {
      trangthainutbam = nutbam;

      // only toggle the LED if the new button state is HIGH
      if(trangthainutbam == LOW) {
      switch(mau) {
        case 0: setColor(255, 0, 0); // red
                mau =1;
                break;
        case 1: setColor(0, 255, 0); // green
                mau =2;
                break;
        case 2: setColor(0, 0, 255); // blue
                mau =3;
                break;
        case 3: setColor(255, 255, 0); // yellow
                mau =4;
                break;
        case 4: setColor(80, 0, 80); // purple
                mau =5;
                break;   
        default: setColor(0, 255, 255); // aqua
                mau =0;
                break;
            
      }
    }

    }
      }
        trangthainutbamtruoc = nutbam;
}
 
void setColor(int red, int green, int blue)
{
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
}

