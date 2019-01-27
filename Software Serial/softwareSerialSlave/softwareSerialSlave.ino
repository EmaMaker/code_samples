#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7); // RX, TX

/**THIS EXAMPLE HAS BEEN SET UP AS MASTER-SLAVE COMMUNICATION, BUT USING mySerial.listen() and mySerial.send() BOTH ARDUINO'S CAN SEND DATA TO THE OTHER**/

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);

  Serial.println("Slave Arduino ready to receive!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(57600);
}

void loop() {
  //prints what the master sent, if data is available
  if(mySerial.available() > 0){
    Serial.println(mySerial.read());
  }
}
