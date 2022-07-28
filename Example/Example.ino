/*
 * NTCReader,
 *          By Giacomo Martinelli
 * Released on 28 june 2022
*/
#include <NTCReader.h>

NTCReader ntc(A0, 2);//The first value is the Analog pin of the NTC and the second is the mw/dec C.
                     //You can find this value on the datasheet(if you don't have them, i reccomend put 6).                
void setup() {
  ntc.setR(10000.0); //You can manipulate Resistor and input volt based on your need(Data Type: double)
  ntc.setV(5.0);//Those values are the default values 
  Serial.begin(9600);//Activate the Serial port at 9600 baud rate to print our data
}

void loop() {
  //print current temperature, max and min registered on this session
  Serial.print("Temperature: ");
  Serial.println(ntc.read());
  Serial.print("Max=");
  Serial.print(ntc.getMax());
  Serial.print("  Min=");
  Serial.println(ntc.getMin());
  delay(1000);
}
