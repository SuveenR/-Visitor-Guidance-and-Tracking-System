/***************************************************************************
 *
 *Project name : Visitor Guidence Tracking 
 
 *****************************************************************************/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <SoftwareSerial.h>
#include <SoftwareSerial.h>
SoftwareSerial smsSerial(6,7); // RX and TX pins to communicate with GSM module
String number ="8618734119"; // Recipient's number - see text
#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
int i;
int val = 0 ;  

/////////////button1 //////////////////
byte c1[8]={B00100, B01110, B11111, B00100, B00100, B00100, B00100, B00100,}; //UP
byte c2[8]={B00010, B00100, B01000, B11111, B01000, B00100, B00010, B00000,}; //LEFT 
byte c3[8]={B01000, B00100, B00010, B11111, B00010, B00100, B01000, B00100,}; // RIGHT

#define button1 2
#define button2 3
#define button3 4
#define button4 5

#define ir A0

#define buz A1   
#define voice1 8   //voice2 = A1, voice3 = A2,voice4 = A3,voice5 = A4,voice6 = A5; 


void ir_sensor();
void buttons();


void setup() {
  Serial.begin(9600);
   smsSerial.begin(9600);
  lcd.init(); 
  lcd.backlight();
  SPI.begin();
  rfid.PCD_Init();
  pinMode(buz, OUTPUT);
   pinMode(button1, INPUT); // declare push button inputs
  pinMode(button2, INPUT);
  pinMode(button3, INPUT); // declare push button inputs
  pinMode(button4, INPUT);
  pinMode(ir, INPUT); // declare push button inputs
  pinMode(voice1, INPUT_PULLUP);
  lcd.clear();
  
 lcd.setCursor(3,0);
  lcd.print("Please Scan ");
  lcd.setCursor(1,1);
  lcd.print("your card...");
      delay(2000);
lcd.clear();

 
 digitalWrite(voice1,LOW);
  digitalWrite(buz,LOW);

}

void loop() {


  lcd.setCursor(0,0);
  lcd.print("1.");
  lcd.setCursor(2,0);
  lcd.print("VLSI");
  lcd.setCursor(0,1);
  lcd.print("2.");
 lcd.setCursor(2,1);
  lcd.print("HOD");


lcd.setCursor(8,0);
  lcd.print("3.");
  lcd.setCursor(10,0);
  lcd.print("AC");
  lcd.setCursor(8,1);
  lcd.print("4.");
 lcd.setCursor(10,1);
  lcd.print("DSD");
  
       // delay(3000);

      // digitalWrite(buz,LOW);

buttons();
 ir_sensor();

  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
      piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
      piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }
  
  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
      (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
      String(rfid.uid.uidByte[i], HEX) +
      (i != 3 ? ":" : "");
  }
   
  strID.toUpperCase();
  Serial.print("Tap card key: ");
  Serial.println(strID);
  delay(1000);

  if (strID.indexOf("17:BB:09:D6") >= 0) {  // sahethya

   lcd.clear();
  lcd.setCursor(2 ,1);
  lcd.print("valid Card");
  delay(800);
  lcd.clear();
  digitalWrite(buz, HIGH);
  delay (500);
  digitalWrite(buz, LOW);
  
 /////////////////// send sms //////////////

   smsSerial.println("AT+CMGF=1"); // Set to Text Mode
      delay(150);
      smsSerial.println("AT+CMGS=\"+91"+number+"\""); 
      delay(150);
      
   delay(100);
   smsSerial.println("MS.SAHETHYA E L");
    smsSerial.println("CONT No:9632208641");
    smsSerial.println("I AM FROM INDIA");
    delay(100);
    smsSerial.println("https://www.google.com/maps");
  //delay(1000);
  smsSerial.print("Latitude and longitude=");
  smsSerial.print("13.0454N,77.5479E\n");
 
      smsSerial.write((byte)0x1A); // End of message character 0x1A (CTRL+Z)
      delay(50);
      smsSerial.println();
 

  
   return;
  }
  if (strID.indexOf("47:D0:08:D6") >= 0) {  // tejsawini g s

   lcd.clear();
  lcd.setCursor(2 ,1);
  lcd.print("valid Card");
  delay(800);
  lcd.clear();
  digitalWrite(buz, HIGH);
  delay (500);
  digitalWrite(buz, LOW);

  /////////////////// send sms //////////////

   smsSerial.println("AT+CMGF=1"); // Set to Text Mode
      delay(150);
      smsSerial.println("AT+CMGS=\"+91"+number+"\""); 
      delay(150);
      
   delay(100);
   smsSerial.println("MS.TEJSAWINI G S");
    smsSerial.println("CONT No:8618734119");
    smsSerial.println("I AM FROM BANGALORE");
    delay(100);
    smsSerial.println("https://www.google.com/maps");
  //delay(1000);
  smsSerial.print("Latitude and longitude=");
  smsSerial.print("13.0454N,77.5479E\n");
 
      smsSerial.write((byte)0x1A); // End of message character 0x1A (CTRL+Z)
      delay(50);
      smsSerial.println();
   return;
  }
if (strID.indexOf("B7:40:FF:D5") >= 0) {  // MR SHARAN SWAMY B N

   lcd.clear();
  lcd.setCursor(2 ,1);
  lcd.print("valid Card");
  delay(800);
  lcd.clear();
  digitalWrite(buz, HIGH);
  delay (500);
  digitalWrite(buz, LOW);


 /////////////////// send sms //////////////

   smsSerial.println("AT+CMGF=1"); // Set to Text Mode
      delay(150);
      smsSerial.println("AT+CMGS=\"+91"+number+"\""); 
      delay(150);
      
   delay(100);
   smsSerial.println("Mr.SHARAN SWAMY B N");
    smsSerial.println("CONT No:9632208641");
    smsSerial.println("I AM FROM CHENNAI");
    delay(100);
    smsSerial.println("https://www.google.com/maps");
  //delay(1000);
  smsSerial.print("Latitude and longitude=");
  smsSerial.print("13.0454N,77.5479E\n");
 
      smsSerial.write((byte)0x1A); // End of message character 0x1A (CTRL+Z)
      delay(50);
      smsSerial.println();
 
   return;
  }
  if (strID.indexOf("B5:A1:79:05") >= 0) {  // SUVEEN R

   lcd.clear();
  lcd.setCursor(2 ,1);
  lcd.print("valid Card");
  delay(800);
  lcd.clear();
  digitalWrite(buz, HIGH);
  delay (500);
  digitalWrite(buz, LOW);

 /////////////////// send sms //////////////

   smsSerial.println("AT+CMGF=1"); // Set to Text Mode
      delay(150);
      smsSerial.println("AT+CMGS=\"+91"+number+"\""); 
      delay(150);
      
   delay(100);
   smsSerial.println("Mr.SUVEEN R");
    smsSerial.println("CONT No:9632208641");
    smsSerial.println("I AM FROM HYDERABAD");
    delay(100);
    smsSerial.println("https://www.google.com/maps");
  //delay(1000);
  smsSerial.print("Latitude and longitude=");
  smsSerial.print("13.0454N,77.5479E\n");
 
      smsSerial.write((byte)0x1A); // End of message character 0x1A (CTRL+Z)
      delay(50);
      smsSerial.println();
 

  
   return;
  }
  
  else {
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print("Invalid Card");
  delay(800);
  lcd.clear();
  tone(buz, 700);
  delay(1000);
  noTone(buz);
  delay(500);

/////////////////// send sms //////////////

   smsSerial.println("AT+CMGF=1"); // Set to Text Mode
      delay(150);
      smsSerial.println("AT+CMGS=\"+91"+number+"\""); 
      delay(150);
      
   delay(100);
     smsSerial.println("UNKNOWN PERSON"); 
    delay(100);
    smsSerial.println("https://www.google.com/maps");
  //delay(1000);
  smsSerial.print("Latitude and longitude=");
  smsSerial.print("13.0454N,77.5479E\n");
 
      smsSerial.write((byte)0x1A); // End of message character 0x1A (CTRL+Z)
      delay(50);
      smsSerial.println();

  return;
  }
}

 void buttons()
    {

    int pressed1 = digitalRead(button1);
    int pressed2 = digitalRead(button2);
    int pressed3 = digitalRead(button3);
    int pressed4 = digitalRead(button4);

if (pressed1 == HIGH)
{

    lcd.clear();
    lcd.createChar(8 , c1); 
    lcd.setCursor(1 ,0);
    lcd.print(char(8)); 
    lcd.setCursor(3,0);
    lcd.print("UP"); 
    delay(2000);
    lcd.clear();
//    lcd.createChar(8 , c2); 
//    lcd.setCursor(1 ,0);
//    lcd.print(char(8));  
//    lcd.setCursor(3,0);
//    lcd.print("LEFT"); 
//    delay(2000);
//    lcd.clear();
    lcd.createChar(8 , c3); 
    lcd.setCursor(1 ,0);
    lcd.print(char(8));  
    lcd.setCursor(3,0);
    lcd.print("RIGHT"); 
    delay(2000);
    lcd.clear();


 /////////////////// send sms //////////////

   smsSerial.println("AT+CMGF=1"); // Set to Text Mode
      delay(150);
      smsSerial.println("AT+CMGS=\"+91"+number+"\""); // Specify recipient's number in international format
      delay(150);
      
   delay(100);
    smsSerial.println("Root Map");
     smsSerial.println("UP");
       smsSerial.println("RIGHT");
    delay(100);
    smsSerial.println("https://www.google.com/maps");
  //delay(1000);
  smsSerial.print("Latitude and longitude=");
  smsSerial.print("13.0454N,77.5479E\n");
 
      smsSerial.write((byte)0x1A); // End of message character 0x1A (CTRL+Z)
      delay(50);
      smsSerial.println();
    
}
else if(pressed2 == HIGH)
  {
    lcd.clear();
    lcd.createChar(8 , c1); 
    lcd.setCursor(1 ,0);
    lcd.print(char(8)); 
    lcd.setCursor(3,0);
    lcd.print("UP"); 
    delay(2000);
    lcd.clear();
//    lcd.createChar(8 , c2); 
//    lcd.setCursor(1 ,0);
//    lcd.print(char(8));  
//    lcd.setCursor(3,0);
//    lcd.print("UP"); 
//    delay(2000);
//    lcd.clear();
//    lcd.createChar(8 , c3); 
//    lcd.setCursor(1 ,0);
//    lcd.print(char(8));  
//    lcd.setCursor(3,0);
//    lcd.print("RIGHT"); 
//    delay(2000);
//        lcd.clear();


    /////////////////// send sms //////////////

   smsSerial.println("AT+CMGF=1"); // Set to Text Mode
      delay(150);
      smsSerial.println("AT+CMGS=\"+91"+number+"\""); // Specify recipient's number in international format
      delay(150);
      
   delay(100);
    smsSerial.println("Root Map");
     smsSerial.println("UP");
//      smsSerial.println("LEFT");
//       smsSerial.println("RIGHT");
    delay(100);
    smsSerial.println("https://www.google.com/maps");
  //delay(1000);
  smsSerial.print("Latitude and longitude=");
  smsSerial.print("13.0454N,77.5479E\n");
 
      smsSerial.write((byte)0x1A); // End of message character 0x1A (CTRL+Z)
      delay(50);
      smsSerial.println();
    
}
else if(pressed3 == HIGH)
  {
    lcd.clear();
    lcd.createChar(8 , c1); 
    lcd.setCursor(1 ,0);
    lcd.print(char(8)); 
    lcd.setCursor(3,0);
    lcd.print("UP"); 
    delay(2000);
    lcd.clear();
    lcd.createChar(8 , c3); 
    lcd.setCursor(1 ,0);
    lcd.print(char(8));  
    lcd.setCursor(3,0);
    lcd.print("LEFT"); 
    delay(2000);
        lcd.clear();


    /////////////////// send sms //////////////

   smsSerial.println("AT+CMGF=1"); // Set to Text Mode
      delay(150);
      smsSerial.println("AT+CMGS=\"+91"+number+"\""); // Specify recipient's number in international format
      delay(150);
      
   delay(100);
    smsSerial.println("Root Map");
     smsSerial.println("UP");
       smsSerial.println("LEFT");
    delay(100);
    smsSerial.println("https://www.google.com/maps");
  //delay(1000);
  smsSerial.print("Latitude and longitude=");
  smsSerial.print("13.0454N,77.5479E\n");
 
      smsSerial.write((byte)0x1A); // End of message character 0x1A (CTRL+Z)
      delay(50);
      smsSerial.println();
    
}
else if(pressed4 == HIGH)
  {
    lcd.clear();
    lcd.createChar(8 , c1); 
    lcd.setCursor(1 ,0);
    lcd.print(char(8)); 
    lcd.setCursor(3,0);
    lcd.print("UP"); 
    delay(2000);
    lcd.clear();
    lcd.createChar(8 , c3); 
    lcd.setCursor(1 ,0);
    lcd.print(char(8));  
    lcd.setCursor(3,0);
    lcd.print("RIGHT"); 
    delay(2000);
    lcd.clear();
    lcd.createChar(8 , c2); 
    lcd.setCursor(1 ,0);
    lcd.print(char(8));  
    lcd.setCursor(3,0);
    lcd.print("LEFT"); 
    delay(2000);
    lcd.clear();


    /////////////////// send sms //////////////

   smsSerial.println("AT+CMGF=1"); // Set to Text Mode
      delay(150);
      smsSerial.println("AT+CMGS=\"+91"+number+"\""); // Specify recipient's number in international format
      delay(150);
      
   delay(100);
    smsSerial.println("Root Map");
     smsSerial.println("UP");
       smsSerial.println("RIGHT");
       smsSerial.println("LEFT");
    delay(100);
    smsSerial.println("https://www.google.com/maps");
  //delay(1000);
  smsSerial.print("Latitude and longitude=");
  smsSerial.print("13.0454N,77.5479E\n");
 
      smsSerial.write((byte)0x1A); // End of message character 0x1A (CTRL+Z)
      delay(50);
      smsSerial.println();
     
}

else
{
   digitalWrite(buz,LOW);
     noTone(buz);


}
}

void ir_sensor()
{
val = digitalRead(ir);  //  IR sensor output pin connected  
 Serial.println(val);  // see the value in serial monitor in Arduino IDE  
 delay(500);  
 if(val == 0 )  
 {  
  
digitalWrite(voice1, HIGH); 
delay(100); 
digitalWrite(voice1, LOW); 
delay(1000); 
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Not Allowed");
  delay(1000);
  lcd.clear();
//  delay (10);
//  digitalWrite(buz, LOW);
 /////////////////// send sms //////////////

   smsSerial.println("AT+CMGF=1"); // Set to Text Mode
      delay(150);
      smsSerial.println("AT+CMGS=\"+91"+number+"\""); // Specify recipient's number in international format
      delay(150);
      
   delay(100);
    smsSerial.println(" Not Allowed");
    delay(100);
    smsSerial.println("https://www.google.com/maps");
  //delay(1000);
  smsSerial.print("Latitude and longitude=");
  smsSerial.print("13.0454N,77.5479E\n");
 
      smsSerial.write((byte)0x1A); // End of message character 0x1A (CTRL+Z)
      delay(50);
      smsSerial.println();
     tone(buz, 700);
  delay(1000);
  noTone(buz);
  delay(500);
 }  
 else  
 {  
 digitalWrite(buz,LOW);  
   noTone(buz);

 }  
 }
  
