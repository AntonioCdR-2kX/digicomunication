#define NODOS_T 8

char n_nodo=0;
char n_letra;
int n=0; 
int t_0=0;

bool letra[NODOS_T];


void setup()
{
  Serial.begin(9600);

  pinMode(13,OUTPUT);
}

void loop()
{
  if (Serial.available()>1){
    
    // Consulto el nodo
    Serial.print("Nodo: ");
    n_nodo=Serial.read();
    if(n_nodo>='1' && n_nodo<='9')
      n=n_nodo-'0';
    Serial.println(n);

    // Consulto la letra
    Serial.print("Letra: ");
    n_letra=Serial.read();
    if(n_letra=='H')
      letra[n]=1;
    else if(n_letra=='L')
      letra[n]=0;
    Serial.println(n_letra);

  }


}
