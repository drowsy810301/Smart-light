#define ledPin 13
byte pinState = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
   if(Serial.available()){
    int ir_value = Serial.read();
     digitalWrite(13, HIGH);    
     delay(20);
   }else{
    digitalWrite(13, LOW);
   }
   
  
}
