#define N_DIGI 1

#define LIGHT_UMB 300
#define L_CONT 5
#define LED 13
#define LDR A0


char letra=0;
char n_letra=0;
int n=0;
   

void setup()
{
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop()
{
  //Si el puerto está disponible y 
  if (Serial.available()){
    if(letra!=n_letra){
      Serial.print(N_DIGI);
      Serial.println(n_letra);
      letra=n_letra;
    }
  }

  // Contador para cambiar de estado y no cambiar con cualquier pico de valor
  if (analogRead(LDR) > LIGHT_UMB && n<L_CONT) n++;
  else if(analogRead(LDR) < LIGHT_UMB && n>0) n--; 


  if(n==L_CONT) 
  {  
      n_letra='H';  
      digitalWrite(LED, HIGH);  
  }   
  else if(n==0)  
  {  
      n_letra='L';  
      digitalWrite(LED, LOW);  
  }  
  

  delay(100); 
}
