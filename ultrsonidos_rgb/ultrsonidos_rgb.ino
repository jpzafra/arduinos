int rojo=11;
int azul=10;
int verde=9;

int trig = 12;
int echo = 13;

long distancia;

long tiempo;

void setup(){
  
  Serial.begin(9600); 
  
  
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
  pinMode(rojo, OUTPUT); 
  pinMode(azul, OUTPUT); 
  pinMode(verde, OUTPUT);   
}

void loop(){
  
  setColor(0,0,0);
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(2); 
  digitalWrite(trig, LOW); 
  delayMicroseconds(5); 
  digitalWrite(trig, LOW);
  
  tiempo=pulseIn(echo, HIGH); 
  distancia = ms2Cms(tiempo);
  
  if (distancia>40){
    setColor(0,255,0);
  }
  if (distancia<=40&&distancia>20){
    setColor(255,255,0);
  }
  if (distancia<=20){
    setColor(255,0,0);
  }
  
  Serial.print ("Milisegundos: ");
  Serial.print(tiempo);
  Serial.print("  Distancia estimada: ");
  Serial.print(distancia);
  Serial.println(" cm");
 
  delay(100);
} 

long ms2Cms(long microseconds){
  // La velocidad del sonido a 20º de temperatura es 340 m/s o
  // 29 microsegundos por centrimetro.
  // La señal tiene que ir y volver por lo que la distancia a 
  // la que se encuentra el objeto es la mitad de la recorrida.
  return microseconds / 29 /2 ;
}

void setColor(int red, int green, int blue)
{
  analogWrite(rojo, red);
  analogWrite(verde, green);
  analogWrite(azul, blue);  
}
