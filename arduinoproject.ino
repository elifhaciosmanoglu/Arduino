#include <math.h>
#define button 5
#define led_red1 10
#define led_green1 8
#define led_red2 7
#define led_red3 4
#define led_green2 3
#define led_red4 2


int button_situation = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led_red1, OUTPUT);
  pinMode(led_green1, OUTPUT);
  pinMode(led_red2, OUTPUT);
  pinMode(led_red3, OUTPUT);
  pinMode(led_green2, OUTPUT);
  pinMode(led_red4, OUTPUT);
}


void loop() { 

 button_situation = digitalRead(button);
 int temperature = analogRead(A0);
 temperature = temperature * 0.48828125;
 
  int light = analogRead(A1);
 

  if(button_situation == 1 and temperature >= 30 and light >= 400){
    digitalWrite(led_red1,HIGH);
    digitalWrite(led_green1,LOW);
    digitalWrite(led_red2,LOW);
    digitalWrite(led_red3,HIGH);
    digitalWrite(led_green2,LOW);
    digitalWrite(led_red4,LOW);
    Serial.print("There is a lot of light in your environment. Light intensity: ");
    Serial.println(light);
    Serial.print("Your environment is extremly hot. Degree: ");
    Serial.println(temperature);
  }
  else if(button_situation == 1 and temperature >= 30 and 170 < light < 400){
     digitalWrite(led_red1,HIGH);
     digitalWrite(led_green1,LOW);
     digitalWrite(led_red2,LOW);
     digitalWrite(led_red3,LOW);
     digitalWrite(led_green2,HIGH);
     digitalWrite(led_red4,LOW);
     Serial.print("Normal Light.  Light intensity: ");
     Serial.println(light);
    Serial.print("Your environment is extremly hot. Degree: ");
     Serial.println(temperature);
   
  }
  
  else if(button_situation == 1 and temperature >= 30 and light <= 170){
     digitalWrite(led_red1,HIGH);
     digitalWrite(led_green1,LOW);
     digitalWrite(led_red2,LOW);
    digitalWrite(led_red3,LOW);
    digitalWrite(led_green2,LOW);
    digitalWrite(led_red4,HIGH);
    Serial.print("PLEASE TURN ON THE LIGHTS!  Light intensity: ");
    Serial.println(light);
    Serial.print("Your environment is extremly hot. Degree: ");
     Serial.println(temperature);
   
  }

else if(button_situation == 1 and 17 < temperature < 30 and light >= 400){
     digitalWrite(led_red1,LOW);
     digitalWrite(led_green1,HIGH);
     digitalWrite(led_red2,LOW);
     digitalWrite(led_red3,HIGH);
    digitalWrite(led_green2,LOW);
    digitalWrite(led_red4,LOW);
    Serial.print("There is a lot of light in your environment. Light intensity: ");
       Serial.println(light);
     Serial.print("Normal Temperature. Degree: ");
      Serial.println(temperature);
    
}

else if(button_situation == 1 and 17 < temperature < 30 and 170 < light < 400){
       digitalWrite(led_red1,LOW);
     digitalWrite(led_green1,HIGH);
     digitalWrite(led_red2,LOW);
    digitalWrite(led_red3,LOW);
    digitalWrite(led_green2,HIGH);
    digitalWrite(led_red4,LOW);
    Serial.print("Normal Light.  Light intensity: ");
  Serial.println(light);
  Serial.print("Normal Temperature. Degree: ");
    Serial.println(temperature);
}


else if(button_situation == 1 and 17 < temperature < 30 and light <= 170){
       digitalWrite(led_red1,LOW);
     digitalWrite(led_green1,HIGH);
     digitalWrite(led_red2,LOW);
     digitalWrite(led_red3,LOW);
    digitalWrite(led_green2,LOW);
    digitalWrite(led_red4,HIGH);
       Serial.print("PLEASE TURN ON THE LIGHTS!  Light intensity: ");
    Serial.println(light);
      Serial.print("Normal Temperature. Degree: ");
       Serial.println(temperature);
    
  
}

else if(button_situation == 1 and temperature <= 17 and light >= 400){
 digitalWrite(led_red1,LOW);
    digitalWrite(led_green1,LOW);
    digitalWrite(led_red2,HIGH);
     digitalWrite(led_red3,HIGH);
    digitalWrite(led_green2,LOW);
    digitalWrite(led_red4,LOW);
    Serial.print("There is a lot of light in your environment. Light intensity: ");
    Serial.println(light);
    Serial.print("Your environment is cold. Degree: ");
        Serial.println(temperature);
}
 else if(button_situation == 1 and temperature <= 17 and 170 < light < 400){
 digitalWrite(led_red1,LOW);
    digitalWrite(led_green1,LOW);
    digitalWrite(led_red2,HIGH);
    digitalWrite(led_red3,LOW);
    digitalWrite(led_green2,HIGH);
    digitalWrite(led_red4,LOW);
    Serial.print("Normal Light.  Light intensity: ");
    Serial.println(light);
    Serial.print("Your environment is cold. Degree: ");
        Serial.println(temperature);
 }
 
else if(button_situation == 1 and temperature <= 17 and light <= 170){
   digitalWrite(led_red1,LOW);
    digitalWrite(led_green1,LOW);
    digitalWrite(led_red2,HIGH);
    digitalWrite(led_red3,LOW);
    digitalWrite(led_green2,LOW);
    digitalWrite(led_red4,HIGH);
    Serial.print("PLEASE TURN ON THE LIGHTS!  Light intensity: ");
    Serial.println(light);
    Serial.print("Your environment is cold. Degree: ");
    Serial.println(temperature);
    
}
else{
  digitalWrite(led_red1,LOW);
    digitalWrite(led_green1,LOW);
    digitalWrite(led_red2,LOW);
    digitalWrite(led_red3,LOW);
    digitalWrite(led_green2,LOW);
    digitalWrite(led_red4,LOW);
  
}

  delay(1800);
}
