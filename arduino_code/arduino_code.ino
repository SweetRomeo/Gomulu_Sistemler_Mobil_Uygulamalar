#include <SoftwareSerial.h> // Hc-06 Bluetooth Modülü kütüphanesi tanımladık. 
SoftwareSerial bluetooth(PA9,PA10); // Hc-06 Bluetooth Modülü kütüphanesinde rxd ve txd pinlerini tanımladık. 
int buttonPin = PA0;
int LEDpin = PG13;
String textToSend = "k";
const int trigPin = PG11;
const int echoPin = PG10;
int alarmMode = 0;
int safeMode = 0;
const int buzzerPin = PE2;


int state;
int ledstate = 0;
char data;
unsigned long currentTime;




void setup(){
  Serial.begin(19200); //Serial haberleşmeyi aktif hale getirdik. 
  bluetooth.begin(9600);  // Hc-06 Bluetooth Modülü serial haberleşmesini aktif hale getirdik.
  pinMode(LEDpin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  pinMode(buttonPin, INPUT);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.write("Sent: ");
  digitalWrite(LEDpin, LOW);
  digitalWrite(buzzerPin, HIGH);
  
  currentTime = millis();
  
}
void loop() {
  if (bluetooth.available()){
    data = bluetooth.read();
    if(data == 'a') {
      safeMode = -1;
      digitalWrite(LEDpin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      }
      
    else if(data == 's') {
      digitalWrite(LEDpin, LOW);
      digitalWrite(buzzerPin, LOW);
      safeMode = 1;
      }
      
      
  }

  if((millis() > currentTime + (ledstate ? 90 : 10)) && (mesureDist() < 15)) {
    
      if(ledstate) {
        bluetooth.print(textToSend);
        digitalWrite(LEDpin, LOW);
        currentTime = millis();
        if(!safeMode)
          alarmMode = 1;
      }
      else {
        digitalWrite(LEDpin, HIGH);
        currentTime = millis();
      }
      ledstate = !ledstate;
    }

if(alarmMode || !safeMode)
  digitalWrite(buzzerPin, HIGH);
  
  Serial.print("Sent: ");
  Serial.println(textToSend);
}

int mesureDist() {
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * 0.034 / 2;
  
  
  }
