#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7); // RX, TX

/**THIS EXAMPLE HAS BEEN SET UP AS MASTER-SLAVE COMMUNICATION, BUT USING mySerial.listen() and mySerial.send() BOTH ARDUINO'S CAN SEND DATA TO THE OTHER**/

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);


  Serial.println("Master arduino ready to send!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(57600);
}

void loop() {
  
  mySerial.write('A'); //Write the serial data: A is corrispondent for 65 (ASCII)
  delay(1); //bit of delay for the data to be processed
}
