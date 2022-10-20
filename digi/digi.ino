#define t_ON 200
#define t_OFF 200

char letra=0;
int t_0=0;

int LDR = A0; 

int LED = 12;   
 

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(LDR, OUTPUT);
}

void loop()
{
  if (Serial.available()){
    Serial.println("Dato");
    letra=Serial.read();
    Serial.println(letra);
  }

  if (letra=='L'){
    digitalWrite(13, LOW);
  }
  else if(letra=='H'){
    if(millis()>t_0 && millis()<t_0+t_ON){
      digitalWrite(13, HIGH);
    }
    else if(millis()>t_0+t_ON && millis()<t_0+t_OFF){
      digitalWrite(13, LOW);
    }
    else 
      t_0=millis();
  }

  Serial.println(analogRead(LDR));  
  
  if (analogRead(LDR) > 300)  
  {  
      Serial.println("LIGHT ON");  
      digitalWrite(LED, HIGH);  
  }   
  else  
  {  
      Serial.println("LIGHT DOWN");  
      digitalWrite(LED, LOW);  
  }  
  
  delay(1000); 
}
