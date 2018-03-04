
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);

  pinMode(10,OUTPUT);
  lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
       
     digitalWrite(10,HIGH); 
     
     lcd.clear(); 
     lcd.setCursor(0,1);
     lcd.print("Hello World !!");

     sensorValue = analogRead(A0);
     outputValue = map(sensorValue, 0, 1023, 0, 100);

  Serial.print("sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

     lcd.setCursor(0,0);
     lcd.print("Value = ");
     lcd.print(outputValue);
     delay(1000);
     
/*
  for(int i=0;i<=9;i++)
  {
    for(int j=0;j<16;j++)
    {
    lcd.setCursor(j,0);
    lcd.print(i);
    delay (200);
    lcd.setCursor(j,0);
    lcd.print(" ");
    }
  }
*/  
}
