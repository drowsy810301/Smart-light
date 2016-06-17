#define ledPin 13
byte pinState = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  
  int ir_sensor;

  ir_sensor = analogRead(A0);
  
  if(ir_sensor > 100){
    Serial.println(ir_sensor);
    digitalWrite(13, HIGH); 
  }
  else{
    digitalWrite(13, LOW);   
  }
  delay(5);
}

/*
void toggle(int pinNum) {
  digitalWrite(pinNum, pinState);
  pinState = !pinState;
}
*/
