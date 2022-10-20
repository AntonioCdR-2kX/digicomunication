void setup()
{

  Serial.begin(9600);
}

void loop()
{



  Serial.println(analogRead(LDR));  
  
  if (analogRead(LDR) > LIGHT_UMB)  
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
  
  
  Serial.print('H');

  delay(5000);

  Serial.print('L');

  delay(5000);
}
