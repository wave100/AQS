/*
  SD card datalogger

 This example shows how to log data from three analog sensors
 to an SD card using the SD library.

 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

 created  24 Nov 2010
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  /*
  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  */
}

byte i2c_readRegisterByte (byte deviceAddress, byte registerAddress) {
  byte registerData;
  Wire.beginTransmission(deviceAddress);              // set sensor target
  Wire.write(registerAddress);                                     // set memory pointer
  Wire.endTransmission();
  // delete this comment – it was only needed for blog layout.   
  Wire.beginTransmission(deviceAddress);              // get data from device 
  Wire.requestFrom(deviceAddress, 1);                     // request one byte
  resisterData = Wire.read(); 
// you could add more data reads here if you request more than one byte
  return registerData;           // the returned byte from this function is the content from registerAddress
}
// delete this comment – it was only needed to maintain blog layout
byte i2c_writeRegisterByte (byte deviceAddress, byte registerAddress, byte newRegisterByte)  {
  byte result;
  Wire.beginTransmission(deviceAddress); 
  Wire.write(registerAddress);  
  Wire.write(newRegisterByte); 
  result = Wire.endTransmission(); // Wire.endTransmission(); returns 0 if write operation was successful
  // delete this comment – it was only needed for blog layout.
  //delay(5);  // optional:  some sensors need time to write the new data, but most do not. Check Datasheet.
  if(result > 0)  
    { Serial.print(F(“FAIL in I2C register write! Error code: “));Serial.println(result); }
  // delete this comment – it was only needed for blog layout. 
    return result;    // the returned value from this function could be tested as shown above
   //it’s a good idea to check the return from Wire.endTransmission() the first time you write to a sensor 
  //if the first test is okay (result is 0), then I2C sensor coms are working and you don’t have to do extra tests
} 

void loop() {
  // make a string for assembling the data to log:
  String data[100] = "";
  data[0] = "Sensor 1, Sensor 2, Sensor 3, GPS"
  // read three sensors and append to the string:
  for (int i = 1; i<sizeof(data); i++){
    dataString = ""
    for (int analogPin = 0; analogPin < 3; analogPin++) {
      int sensor = analogRead(analogPin);
      dataString += String(sensor);
      if (analogPin < 3) {
        dataString += ", ";
    }
    dataString += String(i2c_readRegisterByte(deviceAddress, registerAddress)
    data[i] = dataString
  }

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    for (int i = 0;i<sizeof(data);i++){
    dataFile.println(data[i]);
    }
    dataFile.close();
    // print to the serial port too:
    //Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}
