
int rojo = 11;
int azul = 10;
int verde = 9;

void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop() {
 	setColor(random(255),random(255),random(255));  	
  	delay(1000);
}

void setColor(int red, int green, int blue){
	analogWrite(rojo, red);
	analogWrite(verde, green);
	analogWrite(azul, blue);
}
