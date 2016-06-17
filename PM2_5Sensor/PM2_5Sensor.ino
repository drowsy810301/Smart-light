#include <SoftwareSerial.h>



#define pmsDataLen 32
uint8_t buf[pmsDataLen];
int idx = 0;
int pm10 = 0;
int pm25 = 0;
int pm100 = 0;

void setup() {
Serial.begin(57600);
Serial1.begin(9600); // PMS 3003 UART has baud rate 9600
}

void loop() { // run over and over
uint8_t c = 0;
idx = 0;
memset(buf, 0, pmsDataLen);

while (true) {
while (c != 0x42) {
while (!Serial1.available());
c = Serial1.read();
}
while (!Serial1.available());
c = Serial1.read();
if (c == 0x4d) {
// now we got a correct header)
buf[idx++] = 0x42;
buf[idx++] = 0x4d;
break;
}
}

while (idx != pmsDataLen) {
while(!Serial1.available());
buf[idx++] = Serial1.read();
}

pm10 = ( buf[10] << 8 ) | buf[11];
pm25 = ( buf[12] << 8 ) | buf[13];
pm100 = ( buf[14] << 8 ) | buf[15];

Serial.print("pm2.5: ");
Serial.print(pm25);
Serial.println(" ug/m3");
Serial.print("pm10: ");
Serial.print(pm10);
Serial.println(" ug/m3");
}
