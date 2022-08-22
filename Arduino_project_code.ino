#define BLYNK_TEMPLATE_ID "TMPLOhC1AFLj"
#define BLYNK_DEVICE_NAME "remoteled"
#define BLYNK_AUTH_TOKEN "ClJkaIrmBmJkIHPCLCAxAGlbv2cejVEJ"
#define BLYNK_PRINT Serial
#define greenLed 0
#define redLed 1
#define leds 13
#include <Bridge.h>
#include <BlynkSimpleYun.h>

char auth[] = BLYNK_AUTH_TOKEN;

float temp;
int tempPin = A1;
float light;
int lightPin = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Blynk.begin(auth);

 pinMode(greenLed, OUTPUT);
 pinMode(redLed,OUTPUT);
 pinMode(leds,OUTPUT);
}
BLYNK_WRITE(V0)
{
  int value = param.asInt();

  if (value ==1)
  digitalWrite(leds, HIGH);
  else
  digitalWrite(leds,LOW);
}
BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);
}

void sensorRead()
{
  
  light = analogRead(lightPin);
  temp = analogRead(tempPin);
  temp = temp * 0.48828125;
  Blynk.virtualWrite(V1, temp);
  Blynk.virtualWrite(V2, light);
}


void loop()
{

  Blynk.run();
    light = analogRead(lightPin);
    temp = analogRead(tempPin);
temp = temp * 0.48828125;

if(temp>25 and light>200){
digitalWrite(redLed,LOW);
Serial.print("TEMPERATURE = ");
Serial.print(temp); 
Serial.print("*C");
Serial.println();
Serial.print("LIGHT INTENSITY = ");
Serial.print(light); 
Serial.println();
}
else if(temp>25 and light<700){
digitalWrite(redLed,LOW);
Serial.print("TEMPERATURE = ");
Serial.print(temp); 
Serial.print("*C");
Serial.println();
Serial.print("Please open the light. LIGHT INTENSITY = ");
Serial.print(light); 
Serial.println(); }

 else if(temp<25 and light>700){
 digitalWrite(redLed, HIGH);
Serial.print("The room is cold, please turn on the heater.");
Serial.print("TEMPERATURE =");
Serial.print(temp); 
Serial.print("*C");
Serial.println();
Serial.print("LIGHT INTENSITY = "); 
Serial.print(light); 
Serial.println();}

else if(temp<25 and light<700){
 digitalWrite(redLed, HIGH);
Serial.print("The room is cold, please turn on the heater.");
Serial.print("TEMPERATURE =");
Serial.print(temp); 
Serial.print("*C");
Serial.println();
Serial.print("Please open the light(you can use your remote control devices). LIGHT INTENSITY = ");
Serial.print(light);
Serial.println();}

delay(1500); 

}
