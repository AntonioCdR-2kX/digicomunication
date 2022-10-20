#define t_ON 200
#define t_OFF 200

 
char letra=0;
char new_letra=0;
int t_0=0;

void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop()
{
  if (Serial.available()){
    Serial.println("Dato");
    new_letra=Serial.read();
    if(new_letra>='A' && new_letra<='Z') letra=new_letra; 
  }

  if (letra=='L'){
    digitalWrite(13, HIGH);
  }
  else if(letra=='H'){
     if(millis()>t_0 && millis()<t_0+t_ON){
      digitalWrite(13, HIGH);
      Serial.println("ON");
    }
    else if(millis()>t_0+t_ON && millis()<t_0+t_ON+t_OFF){
      digitalWrite(13, LOW);
      Serial.println("OFF");
    }
    else 
      t_0=millis();
  }
  
  Serial.println(millis()-t_0);
}
